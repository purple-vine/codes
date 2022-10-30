#include <cstdio>
#include <bitset>
#include <queue>
#include <cstring>
#include <vector>
#ifdef DEBUG_LOCAL
#define dprintf printf
#else
#define dprintf
#endif
#define LL long long
using namespace std;
const int M = 500005, N = 2505;
const LL inf = 4e18 + 5;
struct edge{
   int to, nxt;
} e[M << 1];
int head[N], cnt1;
void link(int u, int v) {
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, k;
bool vis[N]; queue<int> q; int dis[N]; LL val[N];
bool path[N][N];
void bfs(int t) {
    q.push(t);
    memset(vis, 0, sizeof(vis)); memset(dis, 0, sizeof(dis));
    vis[t] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to; if(vis[v]) continue;
            vis[v] = 1; dis[v] = dis[u] + 1;
            if(dis[v] <= k) q.push(v);
        }
    }
    for(int i = 1; i <= n; i++)
        if(vis[i] && i != t) path[t][i] = 1;
}
LL mn[N][3]; int pl[N][3]; // 走两条路到 u 的前 2 大值与对应位置
int main(){
    // freopen("holiday.in", "r", stdin);
    // freopen("holiday.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 2; i <= n; i++) scanf("%lld", &val[i]);
    for(int i = 1; i <= m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    for(int i = 1; i <= n; i++) bfs(i);
    path[1][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 2; j++) mn[i][j] = -inf;
        for(int j = 2; j <= n; j++){
            if(!path[i][j] || !path[j][1]) continue;
            LL v = val[j] + val[i];
            if(v > mn[i][0]) {
                mn[i][2] = mn[i][1]; pl[i][2] = pl[i][1];
                mn[i][1] = mn[i][0]; pl[i][1] = pl[i][0];
                mn[i][0] = v, pl[i][0] = j;
            } else if(v > mn[i][1]) {
                mn[i][1] = mn[i][0]; pl[i][1] = pl[i][0];
                mn[i][1] = v, pl[i][1] = j;
            } else if(v > mn[i][2]) {
                mn[i][2] = v, pl[i][2] = j;
            }
        } 
    }
    LL ans = 0;
    for(int x = 2; x <= n; x++){
        for(int y = x+1; y <= n; y++){
            if(!path[x][y]) continue;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++) {
                    int x1 = pl[x][i], y1 = pl[y][j];
                    if(x1 != y && y1 != x && x1 != y1) 
                        if(mn[x][i] + mn[y][j] > ans) {
                            ans = mn[x][i] + mn[y][j];
                        }
                        // ans = max(ans, mn[x][i] + mn[y][j]);
                }
            }
        }
    }
    printf("%lld\n", ans);
}