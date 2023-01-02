#include <cstdio>
#include <vector>
#include <assert.h>
using namespace std;
const int M = 905, N = 65;
const int mod = 1000000009;
struct modint {
    int x;
    modint(int o = 0) {x = o;}
    modint &operator = (int o) {return x = o, *this;}
    modint &operator += (modint o) {return x = x+o.x >= mod ? x+o.x-mod : x+o.x, *this;}
    modint &operator -= (modint o) {return x = x-o.x < 0 ? x-o.x+mod : x-o.x, *this;}
    modint &operator *= (modint o) {return x = 1ll*x*o.x%mod, *this;}
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
inline modint qpow(modint x, int y) {return x ^ y;}

modint C[M][M];
inline void initC(int n) {
    C[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) 
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}
int c[N]; modint dp[N][N][N], f[N][N][N], g[N][N], f1[M]; // 最后一项： -1 的幂次
int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    initC(n * m);
    for(int i = 1; i <= k; i++) scanf("%d", &c[i]);
    dp[0][0][0] = 1;
    f1[0] = 1;
    for(int i = 1; i <= n*m; i++) f1[i] = f1[i-1] * (mod-1);
    for(int i = 0; i < k; i++) {
        for(int x = 0; x <= n; x++) 
            for(int y = 0; y <= m; y++)
                g[x][y] = C[x*y][c[i+1]];
        for(int x = 0; x <= n; x++) 
            for(int y = 0; y <= m; y++) 
                for(int u = 0; u <= x; u++) 
                    for(int v = 0; v <= y; v++) {
                        f[i][x][y] += C[x][u] * C[y][v] * f1[x-u] * f1[y-v] * g[u][v];
                    }
        for(int x = 0; x <= n; x++) 
            for(int y = 0; y <= m; y++) if(dp[i][x][y] != 0) 
                for(int u = 0; u <= n; u++) 
                    for(int v = 0; v <= m; v++) 
                        dp[i+1][x+u][y+v] += f[i][u][v] * dp[i][x][y] * C[n-x][u] * C[m-y][v];
    }
    modint ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) 
            ans += dp[k][i][j]; 
    }
    printf("%d\n", ans);   
}