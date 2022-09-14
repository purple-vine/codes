#include <cstdio>
using namespace std;
const int M = 1000005, mod = 1000000007;
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
int fac[M], invfac[M];
void pre(int n = 250000){
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * inv(i) % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int T, n, m = 2, k, val[M];
int main(){
    scanf("%d %d", &k, &n); pre(n + 5);
    int sum = 0, ans = 0;
    for(int i = 1; i <= n+2; i++)
        val[i] = addd(val[i-1], qpow(i, n));
    if(k <= n+2) {printf("%d\n", val[k]); return 0;}
    for(int i = 1; i <= n+2; i++) {
        int t1 = 1ll * val[i] * inv(k - i + mod) % mod, 
            t2 = 1ll * invfac[i-1] * invfac[n+m-i] % mod * ((n+m-i) % 2 == 0 ? 1: (mod-1)) % mod;
        add(ans, 1ll * t1 * t2 % mod);
        // printf("%d\n", ans);
    }
    for(int i = 1; i <= n+2; i++) ans = 1ll * ans * (k - i) % mod;
    printf("%d\n", ans);
}