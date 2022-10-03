#include <cstdio>
#include <algorithm>
#include <iostream>
#define inf (1e18)
using namespace std;
const int M = 5005;
long long dp[M][M], n, f[M];
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1, siz[M];
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
// dp[u][i] : 以 u 为根留 i 数
void dfs(int u, int fa){
    // siz[u] = 1;
    for(int i = 0; i <= n; i++) dp[u][i] = inf;
    dp[u][0] = 0;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        dfs(v, u); // printf("%d->%d\n", u, v);
        for(int k = siz[u] + siz[v]; k >= 0; k--){
            dp[u][k] = inf;
            for(int j = max(k - siz[u], 1); j <= min(siz[v], k); j++){
                dp[u][k] = min(dp[u][k], dp[u][k - j] + dp[v][j]);
            }
        }
        siz[u] += siz[v];
    }
    // printf("%d %d:", u, siz[u]);
    // for(int i = 0; i <= n; i++){
    //     printf("%d ", dp[u][i] == inf ? -1 : dp[u][i]);
    // }
    // printf("\n");
    ++siz[u];
    for(int i = siz[u]; i >= 1; i--) dp[u][i] = dp[u][i-1];
    dp[u][0] = inf; dp[u][1] = f[siz[u] - 1]; dp[u][siz[u]] = 0;
    for(int j = 2; j <= siz[u]; j++){
        dp[u][1] = min(dp[u][1], dp[u][j] + f[j-1]);
    }
    // printf("%d %d:", u, siz[u]);
    // for(int i = 0; i <= n; i++){
        // printf("%d ", dp[u][i] == inf ? -1 : dp[u][i]);
    // }
    // printf("\n");
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%d", &f[i]);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    dfs(1, 0);
    printf("%lld\n", dp[1][1]);
}