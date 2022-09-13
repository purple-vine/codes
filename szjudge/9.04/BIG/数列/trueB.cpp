#include <cstdio>
#include <algorithm>
#include <queue>
#include <assert.h>
using namespace std;
const int M = 500005, N = 25;
struct edge{
    int to, nxt, id;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v, int k){
    e[++cnt1] = {v, head[u], k}; head[u] = cnt1;
}
int n, m, u1[M], v1[M], cnt, d1[M], nxt[M], st[M], top, ans[M];
namespace bcj{
    int fa[M];
    void init() {for(int i = 1; i <= n; i++) fa[i] = i;}
    int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
    void merge(int x, int y){
        if((x = find(x)) != (y = find(y))) fa[y] = x;
    }
}
int dep[M], id1[M], fa[M][N];
void dfs1(int u, int f){
    fa[u][0] = f; dep[u] = dep[f] + 1;
    for(int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dfs1(v, u); id1[v] = e[i].id;
    }
}
int lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = 20; i >= 0; i--) if(dep[u] <= dep[fa[v][i]]) v = fa[v][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return u == v ? u : fa[u][0];
}
void solve(int u, int l){
    while(dep[u] > dep[l]){
        if(!ans[id1[u]]) st[++top] = u;
        bcj::merge(fa[u][0], u); u = bcj::find(u);
    }
}
int main(){
    // freopen("ex_A2.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        if(t == 1) link(u, v, i), link(v, u, i);
        u1[i] = u, v1[i] = v, d1[i] = t;
    }
    dfs1(1, 0); int ecnt = 0; bcj::init();
    int d = 0;
    for(int i = 1; i <= n; i++) d = max(d, dep[i]);
    assert(d >= 1000);
    for(int i = 1; i <= m; i++){
        if(ans[i]) continue;
        int u = u1[i], v = v1[i];
        if(d1[i] == 0){
            int l = lca(u, v); top = 0; solve(u, l); solve(v, l);
            // printf("u=%d v=%d lca=%d\n", u, v, l);
            sort(st+1, st+top+1, [](int x, int y) {return id1[x] < id1[y];});
            for(int j = 1; j <= top; j++) ans[id1[st[j]]] = ++ecnt;
            // for(int i = 1; i <= top; i++) printf("%d ", st[i]);
            // printf("\n");
            ans[i] = ++ecnt;
        } else {
            ans[i] = ++ecnt; 
            if(dep[u] > dep[v]) swap(u, v);
            bcj::merge(u, v);
        }
    }
    for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
}
/*
9 13
3 6 0
3 2 1
1 2 1
8 3 1
7 9 0
5 6 0
6 7 1
4 6 1
4 7 0
2 5 1
2 4 1
3 9 1
5 4 0
*/