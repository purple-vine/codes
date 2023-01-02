#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int M = 305;
int n, m, mod, p[M], q[M], cnt[M]; 
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
    friend modint operator ^(modint a,int b) {return a ^= b;}
    friend bool operator == (modint a, int b) {return a.x == b;}
    friend bool operator != (modint a, int b) {return a.x != b;}
    bool operator ! () {return !x;}
    modint operator - () {return x ? mod-x : 0;}
    bool operator < (const modint &b) const {return x < b.x;}
};
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &m, &mod);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= m; i++) scanf("%d %d", &p[i], &q[i]), ++cnt[q[i]];
        vector<vector<modint>> C(n+1, vector<modint>(n+1, 0));
        C[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            C[i][0] = 1;
            for(int j = 1; j <= i; j++) 
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
        vector<vector<modint>> dp(n+2, vector<modint>(n+1, 0));
        int lim = 0; bool f = 1;
        dp[n+1][0] = 1;
        for(int i = n; i >= 1; i--) {
            ++lim; lim -= cnt[i];
            if(lim < 0) {f = 0; printf("NO\n"); break;}
            for(int j = 0; j <= lim && j <= n-m; j++) {
                for(int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i+1][j - k] * C[n - m - j + k][k];
                }
            }
        }
        if(f) printf("YES %d\n", dp[1][n-m]);
    }
}