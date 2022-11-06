#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int M = 5005, inf = (unsigned)(1 << 31) - 1;
int S, T;
struct edge{
    int to, nxt, w;
}e[M << 1];
int head[M], cnt1 = 1;
void link(int u, int v, int w){
    e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
}
queue<int> q; int cur[M], n, m, d[M];
bool bfs(){
    while(q.size()) q.pop();
    q.push(S);
    for(int i = 1; i <= n; i++) cur[i] = head[i], d[i] = 0;
    d[S] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to;
            if(e[i].w && !d[v]) {
                d[v] = d[u] + 1; q.push(v);
                if(v == T) return 1;
            }
        }
    } return 0;
}
int dinic(int u, int flow){
    if(u == T) return flow;
    int ret = flow, i;
    for(i = cur[u]; i; i = e[i].nxt){
        int v = e[i].to;
        if(e[i].w && d[v] == d[u]+1){
            int t = dinic(v, min(ret, e[i].w));
            if(!t) d[v] = 0;
            e[i].w -= t; e[i^1].w += t;
            ret -= t;
            if(!ret) return flow;
        }
    }
    cur[u] = i;
    return flow - ret;
}
int main(){
    scanf("%d %d %d %d", &n, &m, &S, &T);
    for(int i = 1; i <= m; i++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        link(u, v, w); link(v, u, 0);
    }
    long long ans = 0;
    // printf("inf=%d\n", inf);
    while(bfs()) ans += dinic(S, inf);
    printf("%lld\n", ans);
}