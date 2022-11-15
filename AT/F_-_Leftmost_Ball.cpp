// agc002F
#include <cstdio>
using namespace std;
const int M = 4e6 + 5, mod = 1e9 + 7, N = 2005;
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
    fac[0] = invfac[0] = fac[1] = invfac[1] = invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod,
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}

int dp[N][N];
int main(){
    int n, k; scanf("%d %d", &n, &k);
    pre(n * k);
    if(k == 1) {puts("1"); return 0;}
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            add(dp[i+1][j], dp[i][j]);
            if(j+1 <= i)
                add(dp[i][j+1], 1ll * dp[i][j] * (n-j) % mod * C(n*k - i - j*(k-1) - 1, k-2) % mod);
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= n; j++) printf("%d ", dp[i][j]);
    //     printf("\n");
    // }
    printf("%d\n", dp[n][n]);
}