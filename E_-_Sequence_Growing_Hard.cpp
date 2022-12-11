#include <cstdio>
using namespace std;
const int M = 305;
int mod;
int add(int a, int b) {a += b; return a > mod ? a-mod : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void addn(int &x, int y) {x += y; if(x > mod) x -= mod;}
int n, dp[M][M], k, C[M][M], s[M][M];
int main(){
    scanf("%d %d %d", &n, &k, &mod);
    C[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) 
            C[i][j] = add(C[i-1][j-1], C[i-1][j]);
        printf("\n");
    }
    for(int i = 0; i <= k; i++) dp[i][1] = 1, s[i][1] = k-i+1;
    for(int x = 2; x <= n+1; x++) {
        for(int v = k; v >= 0; v--) {
            for(int y = 1; y < x; y++) 
                addn(dp[v][x], 1ll * C[x-2][y-1] * s[v+1][y] % mod * dp[v][x-y] % mod);
            s[v][x] = add(s[v+1][x], dp[v][x]);
        }
    }
    printf("%d\n", dp[0][n+1]);
}