#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1e6 + 5;
struct edge {
    int to, nxt, w;
} e[M << 1];
int h[M];
struct EDGE {
    int u, v, w;
    bool operator < (const EDGE &t) const {
        return h[v] == h[t.v] ? w < t.w: h[v] > h[t.v];
    }
} E[M << 1];
int head[M], cnt1, cnt2;
void link(int u, int v, int w) {
    e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
} 
bool vis[M], f[M];
int fa[M];
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
    u = find(u); v = find(v); if(u != v) fa[u] = v;
}
int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for(int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        if(h[u] >= h[v]) link(u, v, w);
        if(h[v] >= h[u]) link(v, u, w);
    }
    // printf("gg\n");
    queue<int> q;
    q.push(1); int sm = 1;
    vis[1] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to; E[++cnt2] = {u, v, e[i].w};
            if(!vis[v]) q.push(v), vis[v] = 1, ++sm;
        }
    }
    printf("%d ", sm);
    sort(E+1, E+cnt2+1);
    for(int i = 1; i <= n; i++) fa[i] = i;
    long long ans = 0;
    for(int i = 1; i <= cnt2; i++) {
        int v = E[i].v, u = E[i].u;
        if(find(u) == find(v)) continue;
        ans += E[i].w; merge(u, v);
    }
    printf("%lld\n", ans);
}