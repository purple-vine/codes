#include <cstdio>
#include <cmath>
using namespace std;
const int M = 1e5 + 5, N = 355;
int f[N][M], g[N][M], n, mod;
int add(int a, int b) {a += b; return a > mod ? a-mod : a;}
void addn(int &x, int y) {x += y; if(x > mod) x -= mod;}
int main(){
    scanf("%d %d", &n, &mod);
    int m = sqrt(n);
    f[0][0] = 1;
    for(int i = 1; i < m; i++) {
        for(int j = 0; j <= n; j++)
            f[i][j] = f[i-1][j];
        for(int j = i; j <= n; j++) 
            addn(f[i][j], f[i][j-i]);
    }
    g[0][0] = 1;
    for(int i = 1; i <= m+5; i++) {
        for(int j = 1; j <= n; j++) {
            if(j >= m) addn(g[i][j], g[i-1][j-m]);
            if(j >= i) addn(g[i][j], g[i][j-i]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            addn(ans, 1ll * f[m-1][i] * g[j][n-i] % mod);
    printf("%d\n", ans);
}