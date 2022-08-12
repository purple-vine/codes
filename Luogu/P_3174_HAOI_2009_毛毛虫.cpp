#include <cstdio>
#include <iostream>
using namespace std;
const int M = 300005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int dp[M], n, u, v, ans;
void dfs(int u, int fa){
    dp[u] = 1; int s = 0;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue; ++s;
        dfs(v, u);
    }
    int t = s > 2 ? s-2 : 0;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        ans = max(ans, dp[v] + dp[u] + (u != 1) + t);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    if(s) dp[u] += s-1; ans = max(ans, dp[u] + (u != 1));
    // printf("%d:%d\n", u, dp[u]);
}
int main(){
    scanf("%d %d", &n, &n); ++n;
    for(int i = 1; i < n; i++) scanf("%d %d", &u, &v), link(u, v), link(v, u);
    dfs(1, 0);
    printf("%d\n", ans);
}