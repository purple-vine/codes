#include <cstdio>
#include <iostream>
using namespace std;
const int M = 4005;
int q[M], l, r, n, m, t, k, a[M][M], dp[M][M];
int main(){
    scanf("%d %d %d %d", &n, &m, &k, &t);
    for(int i = 1; i <= k; i++) {
        int x, y, v; scanf("%d %d %d", &x, &y, &v);
        a[x][y] += v;
    }
    for(int i = 1; i <= m; i++) dp[1][i] = a[1][i];
    for(int i = 2; i <= n; i++) {
        l = 1; r = 0;
        for(int j = 1; j <= m; j++) {
            while(l <= r && q[l] < j - t) ++l;
            while(l <= r && dp[i-1][q[r]] < dp[i-1][j]) --r;
            q[++r] = j; dp[i][j] = dp[i-1][q[l]] + a[i][j];
        }
        l = 1; r = 0;
        for(int j = m; j >= 1; j--) {
            while(l <= r && q[l] > j + t) ++l;
            while(l <= r && dp[i-1][q[r]] < dp[i-1][j]) --r;
            q[++r] = j; dp[i][j] = max(dp[i][j], dp[i-1][q[l]] + a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
}