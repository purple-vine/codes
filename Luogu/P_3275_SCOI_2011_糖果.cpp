#include <cstdio>
#include <queue>
using namespace std;
const int M = 1e6 + 5;
int n, m, deg[M];
struct gragh{
    struct edge{
        int to, nxt, w;
    }e[M << 1];
    int head[M], cnt1;
    void link(int u, int v, int w){
        e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
    }
    int dfn[M], low[M], cnt, sta[M], top, col[M]; bool in[M];
    void tarjan(int u, int f) {
        low[u] = dfn[u] = ++cnt; sta[++top] = u; in[u] = 1;
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(!dfn[v]){
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
            }
            else if(in[v]) low[u] = min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u]) {
            do {
                int v = sta[top];
                col[v] = u; in[v] = 0;
            } while(sta[top--] != u);
        }
    } 
    int fa[M];
    int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}
    void merge(int u, int v) {if((u = find(u)) != (v = find(v))) fa[u] = v;}
    bool suodian(gragh &t) {
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int u = 1; u <= n; u++) {
            // printf("%d-%d ", u, col[u]);
            for(int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if(col[u] != col[v]) t.link(col[u], col[v], e[i].w), ++deg[col[v]];
                if(col[u] == col[v] && e[i].w == 1) return 0;
            }
        }
        return 1;
    }
} g1, g2, g3;
int ans[M];
void link(int u, int v, int w) {
    // printf("%d %d %d\n", u, v, w);
    g1.link(u, v, w); g2.link(v, u, w);
}
bool vis[M];
int main () {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int op, x, y; scanf("%d %d %d", &op, &x, &y);
        if(op == 1) link(x, y, 0), link(y, x, 0);
        else if(op == 2) link(x, y, 1);
        else if(op == 3) link(y, x, 0);
        else if(op == 4) link(y, x, 1);
        else if(op == 5) link(x, y, 0);
    }
    if(!g1.suodian(g3)) return printf("-1\n"), 0;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!deg[i] && g1.fa[i] == i) q.push(i);
        ans[i] = 1; // printf("%d-%d ", g1.fa[i], deg[i]);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = g3.head[u]; i; i = g3.e[i].nxt) {
            int v = g3.e[i].to;
            ans[v] = max(ans[v], ans[u] + g3.e[i].w);
            if(!--deg[v]) q.push(v);
        }
    }
    long long tot = 0;
    for(int i = 1; i <= n; i++) tot += 1ll * ans[g1.col[i]]; //, printf("%d ", ans[g1.col[i]]);
    printf("%lld\n", tot);
}