#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int M = 20, mod = 1000000000;
// 用前 i 条线段恰好覆盖到 j 的方案数
int dp[M*M][M], n, x[M*M], y[M*M], cnt, a[M*M];
bool cmp(int i, int j) {return y[i] != y[j] ? y[i] < y[j] : x[i] < x[j];}
int main(){
	scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(__gcd(i, j) == 1) x[++cnt] = i, y[cnt] = j, a[cnt] = cnt;
    sort(a+1, a+cnt+1, cmp);
    dp[0][1] = 1;
    for(int i = 1; i <= cnt; i++){
        int xx = x[a[i]], yy = y[a[i]];
        // printf("%d %d\n", xx, yy);
        // for(int j = 1; j <= n; j++) dp[i][j] = dp[i-1][j];
        for(int j = 1; j <= n; j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if(xx <= j) dp[i][yy] = (dp[i][yy] + dp[i-1][j]) % mod;
            else dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
        }
    }
    printf("%d\n", dp[cnt][n]);
}