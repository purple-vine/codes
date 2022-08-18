#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M = 305;
int n, m, k; long long dp[M][M][2][2][2][2];
long long dfs(int n, int m, bool u, bool d, bool l, bool r){
    if(dp[n][m][u][d][l][r] != -1) return dp[n][m][u][d][l][r];
    // printf("%d %d %d %d %d %d\n", n, m, u, d, l, r);
    long long ans = 1ll * (n*m-k) * (n*m-k);
    // 竖切
    if((u|l|r) && (d|l|r)){
        for(int i = 1; i < m; i++)
            ans = min(ans, dfs(n, i, u, 0, l, r) + dfs(n, m-i, 0, d, l, r));
    }
    // 横切
    if((l|u|d) && (r|u|d)){
        for(int i = 1; i < n; i++)
            ans = min(ans, dfs(i, m, u, d, l, 0) + dfs(n-i, m, u, d, 0, r));
    }
    dp[n][m][u][d][l][r] = dp[m][n][l][r][d][u] = dp[m][n][r][l][u][d] = dp[n][m][d][u][r][l]
    = dp[n][m][u][d][r][l] = dp[n][m][d][u][l][r] = ans;
    return ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &n, &m, &k);
    printf("%lld\n", dfs(n, m, 1, 1, 1, 1));
}