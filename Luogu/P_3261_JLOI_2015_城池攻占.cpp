//time : 2022-05-19 19:33
//problem id : luogu P3261
//status : RE
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 1000000000000000005
#define LL long long
using namespace std;
const int M = 600005;
struct edge {int to, nxt;} e[M];
int head[M], cnt1;
int n, m, f[M], a[M], ans1[M], ans2[M], c[M]; LL s[M], h[M], b[M];
void link(int u, int v) {e[++cnt1] = {v, head[u]}; head[u] = cnt1;}
struct zps{
    #define ls(x) t.ls[x]
    #define rs(x) t.rs[x]
    int ls[M], rs[M], dis[M]; bool f[M];
    int cnt, rt[M]; LL s[M], laz1[M], laz2[M];
    void clr(int x) {rs[x] = ls[x] = dis[x] = 0;}
    int find(int x) {return rt[x] == x ? x : rt[x] = find(rt[x]);}
    int build(long long t) {ls[++cnt] = rs[cnt] = 0; s[cnt] = t; laz2[cnt] = dis[cnt] = 1; rt[cnt] = cnt; return cnt;}
    void pushdown(int x){
        if(laz2[x] != 1){
            laz1[ls[x]] *= laz2[x]; s[ls[x]] *= laz2[x];
            laz1[rs[x]] *= laz2[x]; s[rs[x]] *= laz2[x];
            laz2[x] = 1;
        }
        if(laz1[x]){
            laz1[ls[x]] += laz1[x]; s[ls[x]] += laz1[x];
            laz1[rs[x]] += laz1[x]; s[rs[x]] += laz1[x];
            laz1[x] = 0;
        }
    }
    int _merge(int x, int y){
        if(!x || !y) return x|y;
        pushdown(x); pushdown(y);
        if(s[y] > s[x]) swap(x, y);
        rs[x] = _merge(rs[x], y);
        if(dis[rs[x]] > dis[ls[x]]) swap(ls[x], rs[x]);
        dis[x] = dis[rs[x]] + 1;
        return x;
    }
    int merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return x;
        return rt[x] = rt[y] = _merge(x, y);
    }
    long long top(int x) {return s[find(x)];}
    void pop(int x){
        x = find(x); pushdown(x);
        rt[x] = merge(ls[x], rs[x]);
        dis[x] = ls[x] = rs[x] = 0; 
    }
    void print(int x){
        if(!x) return; pushdown(x);
        printf("%d-%lld-%lld-%lld ", x, s[x], laz1[x], laz2[x]); print(ls[x]); print(rs[x]);
    }
    bool empty(int x){
        return find(x) == 0;
    }
}t;
void dfs(int u){
    // printf("in %d\n", u);
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs(v); int vt = t.find(v), ut = t.find(u);
        // if(a[v] == 0) t.laz1[vt] += b[v];
        // else t.laz2[vt] *= b[v];
        t.merge(vt, ut);
    }
    if(u == 1) return;
    while(!t.empty(u) && t.top(u) <= h[u]){
        // printf("pop  %d\n", u);
        t.pop(u); ans1[u]++;
        // printf("%d:", u); t.print(t.find(u));
        // printf("ans1[u]=%d topnow = %d\n", ans1[u], t.top(u));
    }
    for(int i = 1; i <= n; i++){
        printf("%d:", i);
        t.print(t.find(i));
        printf("\n");
    }
    printf("\n");
    printf("out %d\n", u);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &h[i]), t.build(inf);
    for(int i = 2; i <= n; i++) scanf("%d %d %lld", &f[i], &a[i], &b[i]), link(f[i], i);
    for(int i = 1; i <= m; i++) scanf("%lld %d", &s[i], &c[i]);
    for(int i = 1; i <= m; i++) t.merge(c[i], t.build(s[i]));
    dfs(1);
    for(int i = 1; i <= n; i++) printf("%d\n", ans1[i]);
}