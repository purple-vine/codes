#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int M = 300005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v,  head[u]}; head[u] = cnt1;
}
bool vis1[M], vis2[M]; int dis1[M], dis2[M], n, m, u, v;
queue<int> q;
void dij(int s, bool *vis, int *dis){
    for(int i = 0; i <= n; i++) dis[i] = 2e6;
    dis[s] = 0; q.push(s); vis[s] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to; if(!vis[v]) dis[v] = dis[u]+1, q.push(v), vis[v] = 1;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &u, &v); link(u, v); link(v, u);
    }
    dij(1, vis1, dis1); dij(n, vis2, dis2);
    for(int i = 1; i <= n; i++){
        int ans  = min(dis1[n], min(dis1[i] + dis2[0], dis1[0] +  dis2[i]));
        printf("%d ", ans >= 2e6 ? -1 : ans);
    }
}