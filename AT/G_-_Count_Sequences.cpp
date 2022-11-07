#include <cstdio>
using namespace std;
const int M = 1e7+5, mod = 998244353;
int qpow(int a, int b){
    long long ans = 1ll;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
    return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
int fac[M], invfac[M], invn[M];
void pre(int n = M - 3){
    fac[0] = invfac[0] = fac[1] = invfac[1] = invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod,
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int n, m, ans;
int main(){
    pre(); scanf("%d %d", &n, &m);
    ++n;
    for(int i = 0; i <= n-2; i++) {
        int j = n - 2 - i;
        for(int s = 0; s < 3; s++) {
            int t = (m - 2*i - j - s) % 3;
            if(t < 0) continue;
            int res = m - 2*i - j - t - s; res /= 3;
            add(ans, 1ll * C(n-2, i) * C(res + n - 1, n - 1) % mod);
            // printf("i=%d j=%d  t=%d")
        }
    } 
    printf("%d\n", ans);
}