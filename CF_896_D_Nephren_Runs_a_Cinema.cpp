#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int M = 100005, N = 23;
int mod, phimod, p[N], cnt, n, l, r;
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int phi(int n){
	int ans = n;
	for(int i = 2; i * i <= n; i++) if(n % i == 0) {
		ans = ans / i * (i-1); while(n % i == 0) n /= i;
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans; 
}
int inv(int k) {return qpow(k, phimod - 1);}
struct num{
    num() {x = 0; memset(md, 0, sizeof(md));}
    num(int k) {
        memset(md, 0, sizeof(md)); if(k == 0) return; 
        for(int i = 1; i <= cnt; i++){
            while(k % p[i] == 0) k /= p[i], ++md[i];
        }
        x = k; invx = inv(k);
    }
    num operator / (const num &t) const{
        num ans; ans.x = 1ll * x * t.invx % mod, ans.invx = 1ll * invx * t.x % mod;
        for(int i = 1; i <= cnt; i++) ans.md[i] = md[i] - t.md[i];
        return ans;
    }
    num operator * (const num &t) const{
        num ans; ans.x = 1ll * x * t.x % mod, ans.invx = 1ll * invx * t.invx % mod;
        for(int i = 1; i <= cnt; i++) ans.md[i] = md[i] + t.md[i];
        return ans;
    }
    int to_num(){
        int ans = x;
        for(int i = 1; i <= cnt; i++) ans = 1ll * ans * qpow(p[i], md[i]) % mod;
        return ans;
    }
    int x, invx, md[N];
} s[M];
int C(int n, int m){
    // printf("n=%d m=%d\n", n, m);
    if(m > n || m < 0) return 0;
    // printf("C(%d, %d) = %d\n", n, m, (s[n] / s[m] / s[n-m]).to_num());
    return (s[n] / s[m] / s[n-m]).to_num();
}
signed main(){
    scanf("%lld %lld %lld %lld", &n, &mod, &l, &r);
    int t = mod;
    for(int i = 2; i * i <= t; i++)
        if(t % i == 0) {p[++cnt] = i; while(t % i == 0) t /= i;}
    if(t > 1) p[++cnt] = t;
    phimod = phi(mod);
    s[0] = num(1);
    for(int i = 1; i <= n; i++) s[i] = s[i-1] * num(i);
    int ans = 0;
    for(int z = 0; z <= n-l; z++){
        ans = (1ll * ans + 1ll * C(n, z) * (C(n-z, (n-z-l)/2) - C(n-z, (n-z-r + 1) / 2 - 1) + mod) % mod) % mod;
        // printf("z=%d ans=%d\n", z, ans);
    }
    printf("%lld\n", ans);
}