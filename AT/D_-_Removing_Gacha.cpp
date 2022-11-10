#include <cstdio>
using namespace std;
const int M = 2e5 + 5, mod = 998244353;
int n, p[M], H[M], dep[M];
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
void pre(int n = M - 2){
    H[1] = fac[0] = invfac[0] = fac[1] = invfac[1] = invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod,
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod, 
        H[i] = addd(H[i-1], invn[i]);
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int main(){
    scanf("%d", &n); pre(n);
    dep[1] = 1; int ans = 1;
    for(int i = 2; i <= n; i++) {
        scanf("%d", &p[i]); dep[i] = dep[p[i]] + 1;
        add(ans, H[dep[i]]);
    }
    printf("%d\n", ans);
}