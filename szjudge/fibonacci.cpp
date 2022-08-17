#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
const int M = 1000005, mod = 1000000007;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a >= mod ? a-mod : a;}
int minuss(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x >= mod) x -= mod;}
void muniss(int &x, int y) {x -= y; if(x < 0) x += mod;}
int mu[M], p[M], tt, sum[M], F[M]; bool f[M];
void pre(int n){
	F[1] = sum[1] = f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
	}
    for(int i = 1; i <= n; i++)
        for(int j = 1; i*j <= n; j++)
            add(sum[i*j], 1ll * F[i] * mu[j] % mod * j % mod * j % mod);
    for(int i = 1; i <= n; i++) add(sum[i], sum[i-1]);
}
int s(int n) {return 1ll * n * (n-1) / 2 % mod;}
int solve(int n, int m){
    if(n > m) swap(n, m); int ans = 0;
    for(int l = 1, r; l <= n; l = r+1){
        r = min(m/(m/l), n/(n/l));
        add(ans, 1ll * minuss(sum[r], sum[l-1]) * s(n/l) % mod * s(m/l) % mod);
    }
    return ans;
}
int T, n, m;
int main(){
    scanf("%d", &T); pre(100000);
    while(T--){
        scanf("%d %d", &n, &m);
        printf("%d\n", solve(n, m));
    }
}