#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) printf("%d:\n", x);\
    for(int i = 0; i < (1 << n); i++){\
        for(int j = 0; j < (1 << n); j++) printf("%d ", dp[x][i][j]);\
        printf("\n");\
    }\
    printf("\n");
#endif
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
const int M = 11;
int a[1 << M][1 << M], dp[1 << M][1 << M], n; vector<int> t[1 << M];
void dfs(int x){
    int T = 0; while((1 << T) <= x) ++T; --T;
    // printf("x=%d T=%d\n", x, T);
    if(x >= (1 << n)) {dp[x - (1 << n)][x - (1 << n)] = 0; t[x].push_back(x - (1<<n)); return;}
    dfs(x<<1); dfs(x<<1|1); for(int i : t[x<<1|1]) t[x].push_back(i); for(int i : t[x<<1]) t[x].push_back(i);
    if(t[x].size() == 2) {dp[t[ls][0]][t[rs][0]] = dp[t[rs][0]][t[ls][0]] = a[t[ls][0]][t[rs][0]]; return;}
    for(int i : t[x<<1]){
        for(int l : t[x<<1|1]){
            dp[i][l] = 1e9;
            for(int k : t[x<<1|1]){
                if(dp[k][l] == -1) continue;
                for(int j : t[x<<1]){
                    if(dp[i][j] == -1) continue;
                    if(dp[i][l] > dp[i][j] + dp[k][l] + a[j][k])
                        dp[i][l] = min(dp[i][l], dp[i][j] + dp[k][l] + a[j][k]);
                }
            }
            if(dp[i][l] == 1e9) dp[i][l] = -1;
        }
    }
    for(int i : t[x<<1|1]){
        for(int l : t[x<<1]){
            dp[i][l] = 1e9;
            for(int k : t[x<<1]){
                if(dp[k][l] == -1) continue;
                for(int j : t[x<<1|1]){
                    if(dp[i][j] == -1) continue;
                    if(dp[i][l] > dp[i][j] + dp[k][l] + a[j][k])
                        dp[i][l] = min(dp[i][l], dp[i][j] + dp[k][l] + a[j][k]);
                }
            }
            if(dp[i][l] == 1e9) dp[i][l] = -1;
        }
    }
    // debug(x);
}
int main(){
    scanf("%d", &n); memset(dp, -1, sizeof(dp));
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < (1 << n); j++) scanf("%d", &a[i][j]);
    }
    dfs(1);
    int ans = 1e9;
    // for(int x = 1; x <= n+1; x++) {
    //     printf("%d:\n", x);
    //     for(int i = 0; i < (1 << n); i++){
    //         for(int j = 0; j < (1 << n); j++) printf("%d ", dp[x][i][j]);
    //         printf("\n");
    //     }
    //     printf("\n");
    // }
    for(int i = 0; i < (1 << n-1); i++){
        for(int j = 0; j < (1 << n-1); j++){
            ans = min(ans, dp[i][j+(1 << n-1)]);
        }
    }
    printf("%d\n", ans);
}