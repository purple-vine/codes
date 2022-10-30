#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int M = 500005;
struct edge{
    int to, nxt;
} e[M << 1];
int head[M], cnt1;
void link(int u, int v) {
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int dp[M][2]; bool vis[M][2];
struct tp {
    int x, y, dis; bool operator < (const tp &t) const {return dis > t.dis;}
} ;
priority_queue<tp> q;
void dij(){
    memset(dp, 0x7f, sizeof(dp));
    dp[1][0] = 0; q.push({1, 0, 0});
    while(!q.empty()) {
        int u = q.top().x, t = q.top().y, dis = q.top().dis; q.pop();
        if(vis[u][t]) continue; vis[u][t] = 1;
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to, w = 1 + dis;
            if(w < dp[v][w&1]) {
                dp[v][w&1] = w; q.push({v, w&1, dp[v][w&1]});
            }
        }
    }
}
int n, m, Q;
int main(){
    scanf("%d %d %d", &n, &m, &Q);
    for(int i = 1; i <= m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    dij();
    // for(int i = 1; i <= n; i++) printf("%d %d\n", dp[i][0], dp[i][1]);
    while(Q--){
        int u, k; scanf("%d %d", &u, &k);
        printf("%s\n", dp[u][k&1] <= k ? "Yes" : "No");
    }
}