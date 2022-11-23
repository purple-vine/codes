#include <cstdio>
using namespace std;
const int M = 1e6 + 5;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int dep[M], son[M];
void dfs1(int u, int fa) {
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to; if(v == fa) continue;
        dfs1(v, u);
        if(dep[v] > dep[son[u]]) son[u] = v;
    }
    dep[u] = dep[son[u]] + 1;
}
int buf[M], *f[M], *g[M], *now = buf, ans[M];
void dfs2(int u, int fa) {
    f[u][0] = 1;
    if(son[u]) {
        f[son[u]] = f[u] + 1;
        dfs2(son[u], u);
        ans[u] = ans[son[u]] + 1;
    }
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to; if(v == fa || v == son[u]) continue;
        f[v] = now; now += dep[v]; dfs2(v, u);
        for(int i = 1; i <= dep[v]; i++) {
            f[u][i] += f[v][i-1];
            if(f[u][i] > f[u][ans[u]] || (f[u][i] == f[u][ans[u]] && i < ans[u]))
                ans[u] = i;
        }
    }
    if(f[u][ans[u]] == 1) ans[u] = 0;
}
int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    dfs1(1, 0); f[1] = now; now += dep[1]; dfs2(1, 0);
    for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}