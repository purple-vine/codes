#include <cstdio>
using namespace std;
const int M = 5000005;
struct edge{
    int to, nxt;
}e[M];
int head[M], cnt1 = 1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, a[M], b[M], dir[M]; bool vis[M], vis1[M];
void dfs(int u, int f){
    if(vis1[u]) return; vis1[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt){
        // printf("u=%d i=%d\n", u, i);
        int v = e[i].to; if((i ^ 1) == f || vis[i]) continue;
        vis[i^1] = vis[i] = 1; dir[i] = 1; dir[i^1] = 0; dfs(v, i);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= m; i++) link(a[i], b[i]), link(b[i], a[i]);
    for(int i = 1; i <= n; i++) if(!vis1[i]) dfs(i, 0);
    for(int i = 1; i <= m; i++){
        printf("%d", dir[i << 1]);
    }
}