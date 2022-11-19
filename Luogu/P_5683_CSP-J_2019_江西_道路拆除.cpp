#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
const int M = 3005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, s1, s2, t1, t2; bool vis[M];
priority_queue<pair<int, int> > q;
void dij(int *d, int s) {
    memset(d, 0x3f, (n+2) * sizeof(int));
    memset(vis, 0, sizeof(vis));
    d[s] = 0; q.push(make_pair(0, s));
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue; vis[u] = 1;
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to; 
            if(d[u] + 1 < d[v]) {
                d[v] = d[u] + 1; q.push({-d[v], v});
            }
        }
    }
}
int disu[M], dis1[M], dis2[M];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v); link(u, v); link(v, u);
    }
    scanf("%d %d %d %d", &s1, &t1, &s2, &t2);
    dij(disu, 1); dij(dis1, s1); dij(dis2, s2);
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        if(disu[i] + dis1[i] > t1 || disu[i] + dis2[i] > t2) continue;
        ans = max(ans, m - disu[i] - dis1[i] - dis2[i]);
    }
    printf("%d\n", ans);
}