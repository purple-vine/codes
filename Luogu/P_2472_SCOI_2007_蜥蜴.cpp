#include <cstdio>
#include <queue>
#include <iostream>
#define in(a, b) (((a)-1) * c + (b))
#define out(a, b) (in((a), (b)) + r*c)
using namespace std;
const int M = 500005, inf = 998244353;
int S, T;
struct edge{
    int to, nxt, w;
}e[M << 1];
int head[M], cnt1 = 1;
void link(int u, int v, int w){
    // printf("link %d %d %d\n", u, v, w);
    e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
    e[++cnt1] = {u, head[v], 0}; head[v] = cnt1;
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
int getans(){
    int ans = 0;
    while(bfs()) ans += dinic(S, inf);
    return ans;
}
int D;
int dis(int x1, int y1, int x2, int y2){
    return (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
}
int r, c, a[105][105];
int main(){
    scanf("%d %d %d", &r, &c, &D); int cnt = 0;
    S = 2*r*c + 2, T = 2*r*c + 3; n = T;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf("%1d", &a[i][j]);
            if(a[i][j]) link(in(i, j), out(i, j), a[i][j]);
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            char cc; scanf(" %1c", &cc);
            if(cc == 'L') link(S, in(i, j), 1), ++cnt;
        }
    }
    for(int i1 = 1; i1 <= r; i1++){
        for(int j1 = 1; j1 <= c; j1++){
            for(int i2 = 1; i2 <= r; i2++){
                for(int j2 = 1; j2 <= c; j2++){
                    if(i1 == j1 && i2 == j2) continue;
                    if(dis(i1, j1, i2, j2) <= D * D && a[i1][j1] && a[i2][j2])
                        link(out(i1, j1), in(i2, j2), inf);
                }
            }
            if((i1 - D < 1 || j1 - D < 1 || i1+D > r || j1+D > c) && a[i1][j1]){
                link(out(i1, j1), T, inf);
            }
        }
    }
    printf("%d\n", cnt - getans());
}