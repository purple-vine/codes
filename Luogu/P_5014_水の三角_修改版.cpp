#include <cstdio>
using namespace std;
const int M = 5000005, mod = 998244353;
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
void pre(int n = 250000){
    invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod;
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
}
int C(int n, int m) {
    if(m > n || m < 0) return 0;
    return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;
}
int solve(long long n){
    int x = 1; long long sum = 0;
    while(sum < n) sum += 1ll * x, ++x;
    --x; sum -= x; int y = (n - sum), ans = 0;
    // printf("x=%d y=%d\n", x, y);
    --x; --y;
    for(int t = 0; t <= y; t++){
        add(ans, 1ll * minus(C(x-t + y-t, x-t), C(x-t + y-t, x-t+1)) * C(x+y-t, t) % mod);
        // printf("ans=%d %d %d %d\n", ans, C(x-t + y-t, x-t), C(x-t + y-t, x-t+1), C(x+y-t, t));
    }
    return ans;
}
int main(){
    int T;
    scanf("%d", &T); pre(2000000);
    while(T--){
        long long n; scanf("%lld", &n);
        printf("%d\n", solve(n));
    }
}