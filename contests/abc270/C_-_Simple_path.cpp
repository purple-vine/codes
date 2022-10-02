#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 2000005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1, dep[M], fa[M]; bool vis[M];
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
void dfs(int u, int f){
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dep[v] = dep[u] + 1; fa[v] = u; dfs(v, u);
    }
}
int n, x, y, st[M], top;
int main(){
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v); link(u, v); link(v, u);
    }
    dfs(1, 0);
    int u = x, v = y;
    if(dep[u] < dep[v]) swap(u, v);
    while(dep[u] > dep[v]) u = fa[u], vis[u] = 1;
    while(u != v) u = fa[u], v = fa[v], vis[u] = 1, vis[v] = 1;
    u = x; v = y;
    while(vis[fa[u]]) printf("%d ", u), u = fa[u];
    printf("%d ", u);
    while(vis[fa[v]]) st[++top] = v, v = fa[v];
    while(top) printf("%d ", st[top--]);
}