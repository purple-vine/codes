#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int M = 500005, N = 505,inf = 998244353;
struct wll{
    int S, T;
    struct edge{
        int to, nxt, w;
    }e[M << 1];
    int head[N], cnt1 = 1;
    void link(int u, int v, int w){
        e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
        e[++cnt1] = {u, head[v], w}; head[v] = cnt1;
    }
    queue<int> q; int cur[N], n, m, d[N];
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
    int work(){
        int ans = 0;
        while(bfs()) ans += dinic(S, inf);
        return ans;
    }
} s1, s2;
int n, a[M], s[M], ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        s[i] = 1;
        for(int j = 1; j < i; j++)
            if(a[j] <= a[i]) s[i] = max(s[i], s[j] + 1);
        ans = max(ans, s[i]);
    }
    printf("%d\n", ans);
    s1.S = 2*n+1; s1.T = 2*n+2;
    s2.S = 2*n+1; s2.T = 2*n+2;
    s2.link(s2.S, 1, inf); s2.link(2*n, s2.T, inf);
    s2.link(1, n+1, inf); s2.link(n, 2*n, inf);
    for(int i = 1; i <= n; i++){
        s1.link(i, i+n, 1); 
        if(i > 1 && i < n) s2.link(i, i+n, 1); 
        for(int j = 1; j < i; j++){
            if(a[j] <= a[i] && s[i] == s[j] + 1){
                s1.link(j+n, i, 1); s2.link(j+n, i, 1);
            }
        }
        if(a[i] == 1) s1.link(s1.S, i, 1), s2.link(s1.S, i, 1);
    }
    printf("%d\n%d\n", s1.work(), s2.work());
}