#include <cstdio>
#include <queue>
#include <cmath>
#define inf 998244353
using namespace std;
const int M = 5e4 + 5;
struct node {
    int dis, i;
    bool operator < (const node &tmp) const {
        return dis > tmp.dis;
    }
} d[M];
int n, l, r, ans, a[M]; priority_queue<node> q; bool vis[M];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < a[1]; i++) d[i].dis = inf, d[i].i = i;
    d[0].dis = 0; q.push(d[0]);
    while(!q.empty()) {
        node u = q.top(); q.pop(); if(vis[u.i]) continue;
        for(int i = 2; i <= n; i++) {
            int v = (u.i + a[i]) % a[1], w = u.dis + a[i];
            if(d[v].dis > w) d[v].dis = w, q.push(d[v]);
        }
        vis[u.i] = 1;
    }
    int m; scanf("%d", &m);
    while(m--) {
        int t; scanf("%d", &t);
        if(t >= d[t % a[1]].dis) puts("TAK");
        else puts("NIE");
    }
}