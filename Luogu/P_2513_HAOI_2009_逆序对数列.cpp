#include <cstdio>
#include <iostream>
using namespace std;
const int M = 1005, mod = 10000;
int dp[M][M], sum[M][M];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    dp[1][0] = 1;
    for(int i = 1; i <= k+1; i++) sum[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        int mx = min(i * (i-1) / 2, k);
        for(int j = 0; j <= mx; j++) {
            dp[i][j] = (sum[i-1][j + 1] - sum[i-1][max(j - i + 1, 0)] + mod) % mod;
        }
        for(int j = 0; j <= k; j++) sum[i][j+1] = (sum[i][j] + dp[i][j]) % mod;
    }
    printf("%d\n", dp[n][k]);
}