#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int M = 205;
char c[M][M];
int n, m, k, t, l[M], d[M], sx, sy, dp[M][M][M];
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
int main(){
    scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &k);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf(" %c", &c[i][j]);
    for(int i = 1; i <= k; i++) {
        int s, t; scanf("%d %d %d", &s, &t, &d[i]);
        l[i] = t - s + 1;
    }
    // printf("??\n");
    memset(dp, -1, sizeof(dp));
    dp[0][sx][sy] = 0;
    for(int e = 1; e <= k; e++) {
        int tx = dx[d[e]], ty = dy[d[e]];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int s = 0; s <= l[e]; s++) {
                    int xx = i - s * tx, yy = j - s * ty;
                    if(xx < 1 || xx > n || yy < 1 || yy > m || c[xx][yy] == 'x') break;
                    if(dp[e-1][xx][yy] != -1)
                        dp[e][i][j] = max(dp[e][i][j], dp[e-1][i - s*tx][j - s * ty] + s);
                }
            }
        }
        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= m; j++) printf("%2d ", dp[e][i][j]);
        //     printf("\n");
        // }
        // printf("\n");
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            ans = max(ans, dp[k][i][j]);
    printf("%d\n", ans);
}