#include <cstdio>
#include <map>
#define LL long long
// #define int long long
using namespace std;
const int M = 1000005, m = 1000000;
int mod, inv6, inv2; map<LL, int> t; LL n;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int mnss(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
void mns(int &a, int b) {a -= b; if(a < 0) a += mod;}
int p[M], tt, phi[M], sf[M]; bool f[M];
void pre(int n = m){
	f[1] = 1; sf[1] = phi[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, phi[i] = i-1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; phi[k] = phi[i] * p[j]; break;}
			f[k] = 1; phi[k] = phi[i] * (p[j]-1);
		}
        sf[i] = addd(sf[i-1], 1ll * i * i % mod * phi[i] % mod) % mod;
	} 
}
int s(LL n) {n %= mod; return 1ll * n * (n+1) % mod * inv2 % mod;}
int ss(LL n) {n %= mod; return 1ll * n * (n+1) % mod * (2*n+1) % mod * inv6 % mod;}
int Sf(LL n){
    if(n <= m) return sf[n];
    if(t[n]) return t[n];
    int ans = 1ll * s(n) * s(n) % mod;
    for(LL l = 2, r; l <= n; l = r+1){
        r = n/(n/l); mns(ans, 1ll * mnss(ss(r), ss(l-1)) * Sf(n/l) % mod);
    }
    return t[n] = ans;
}
int solve(LL n){
    int ans = 0;
    for(LL l = 1, r; l <= n; l = r+1) {
        r = n/(n/l);
        add(ans, 1ll * s(n/l) * s(n/l) % mod * mnss(Sf(r), Sf(l-1)) % mod);
    }
    return ans;
}
signed main(){
    // freopen("temp.out", "w", stdout);
    scanf("%d %lld", &mod, &n);
    inv6 = inv(6); pre(); inv2 = inv(2);
    printf("%d\n", solve(n));
}