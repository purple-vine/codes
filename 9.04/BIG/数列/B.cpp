#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int M = 2005;
struct edge{
    int to, nxt, id;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v, int k){
    e[++cnt1] = {v, head[u], k}; head[u] = cnt1;
}
int fa[M], dep[M], id1[M];
void dfs1(int u, int f){
    fa[u] = f; dep[u] = dep[f] + 1;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dfs1(v, u); id1[v] = e[i].id;
    }
}
int n, m, u1[M], v1[M], cnt, d1[M];
namespace g1{ // 反图
    const int M = 2000005;
    struct edge{
        int to, nxt;
    }e[M << 1];
    int head[M], cnt2, deg[M];
    void link(int u, int v){
        e[++cnt2] = {v, head[u]}; head[u] = cnt2;
        ++deg[v];
    }
    int ans[M], cnt;
    priority_queue<int> q;
    void solve(){
        for(int i = 1; i <= m; i++)
            if(!deg[i]) q.push(i);
        while(!q.empty()){
            int u = q.top(); q.pop();
            ans[u] = m + 1 - ++cnt;
            for(int i = head[u]; i; i = e[i].nxt){
                int v = e[i].to; --deg[v];
                if(deg[v] == 0) q.push(v);
            }
        }
    }
}
int main(){
    freopen("ex_A2.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        if(t == 1) link(u, v, i), link(v, u, i);
        else u1[++cnt] = u, v1[cnt] = v, d1[cnt] = i;
    }
    dfs1(1, 0);
    for(int i = 1; i <= cnt1; i++){
        int u = u1[i], v = v1[i], id = d1[i];
        if(dep[u] > dep[v]) swap(u, v);
        while(dep[v] > dep[u]) g1::link(id, id1[v]), v = fa[v];
        while(u != v) {
            // printf("u=%d v=%d\n", u, v);
            g1::link(id, id1[u]); g1::link(id, id1[v]);
            // printf("%d %d\n", id, id1[u]); printf("%d %d\n", id, id1[v]);
            u = fa[u]; v = fa[v];
        }
    }
    g1::solve();
    for(int i = 1; i <= m; i++) printf("%d ", g1::ans[i]);
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