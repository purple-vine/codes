#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 2005;
int f[M][M], n, k, a[M], b[M], cnt[M];
const int mod = 1000000009;
struct modint {
    int x;
    modint(int o = 0) {x = o;}
    modint &operator = (int o) {return x = o, *this;}
    modint &operator += (modint o){return x = x+o.x >= mod ? x+o.x-mod : x+o.x, *this;}
    modint &operator -= (modint o){return x = x-o.x < 0 ? x-o.x+mod : x-o.x, *this;}
    modint &operator *= (modint o){return x = 1ll*x*o.x%mod, *this;}
    modint &operator ^= (int b) {
        modint a = *this, c = 1;
        for(; b; b >>= 1, a *= a) if(b & 1) c *= a;
        return x=c.x, *this;
    }
    modint &operator /= (modint o) {return *this *= o ^= mod-2;}
    friend modint operator + (modint a, modint b) {return a += b;}
    friend modint operator - (modint a, modint b) {return a -= b;}
    friend modint operator * (modint a, modint b) {return a *= b;}
    friend modint operator / (modint a, modint b) {return a /= b;}
    friend modint operator ^ (modint a,int b) {return a ^= b;}
    friend bool operator == (modint a, int b) {return a.x == b;}
    friend bool operator != (modint a, int b) {return a.x != b;}
    bool operator ! () {return !x;}
    modint operator - () {return x ? mod-x : 0;}
    bool operator < (const modint &b) const {return x < b.x;}
};
inline modint qpow(modint x, int y) {return x ^ y;}

vector<modint> fac, ifac, iv;
inline void initC(int n) {
    if(iv.empty()) fac = ifac = iv = vector<modint>(2,1);
    int m = iv.size(); ++n;
    if(m >= n) return;
    iv.resize(n), fac.resize(n), ifac.resize(n);
    for(int i = m; i <= n; i++) {
        iv[i] = iv[mod%i] * (mod - mod/i);
        fac[i] = fac[i-1] * i, ifac[i] = ifac[i-1] * iv[i];
    }
}
inline modint C(int n, int m) {
    if(n < 0 || m < 0 || n < m) return 0;
    return initC(n), fac[n] * ifac[m] * ifac[n-m];
}
int main() {
    scanf("%d %d", &n, &k);
    initC(n);
    if(n % 2 != k % 2) return printf("0\n"), 0;
    k = (n + k) / 2;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    for(int i = 1; i <= n; i++) {
        cnt[i] = a + n + 1 - lower_bound(a+1, a+n+1, b[i]);
    }
    vector<vector<modint> > dp(n+2, vector<modint>(n+1, 0));
    dp[n+1][0] = 1;
    for(int i = n; i >= 1; i--) {
        dp[i][0] = dp[i+1][0];
        for(int j = 1; j <= n-i+1; j++) {
            dp[i][j] += dp[i+1][j-1] * (modint){cnt[i] - j + 1};
            dp[i][j] += dp[i+1][j];
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }
    modint ans = 0;
    for(int i = k; i <= n; i++) ans += qpow(mod-1, i - k) * dp[1][i] * fac[n - i] * C(i, k);
    printf("%d\n", ans);
}