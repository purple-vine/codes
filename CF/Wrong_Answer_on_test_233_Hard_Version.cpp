#include <cstdio>
using namespace std;
const int M = 2e5 + 5, mod = 998244353;
int qpow(int a, int b) {
    long long ans = 1ll;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
    return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int add(int a, int b) {a += b; return a > mod ? a-mod : a;}
int sub(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void subn(int &a, int b) {a -= b; if(a < 0) a += mod;}
void addn(int &x, int y) {x += y; if(x > mod) x -= mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
int fac[M * 3], invfac[M * 3], invn[M * 3];
void pre(int n = 250000) {
    fac[0] = invfac[0] = fac[1] = invfac[1] = invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod,
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int n, a[M], m, k;
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) m += a[i] != a[i % n + 1];
    int ans = 0, inv2 = inv(2);
    pre(3 * n);
    for(int i = 1; i <= m; i++) {
        int tmp = qpow(2, i);
        if(i % 2 == 0) subn(tmp, C(i, i / 2));
        addn(ans, 1ll * inv2 * tmp % mod * qpow(k-2, m-i) % mod * C(m, i) % mod);
    }
    printf("%d\n", 1ll * ans * qpow(k, n-m) % mod);
}