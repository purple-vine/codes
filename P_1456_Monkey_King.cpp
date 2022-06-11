//create-time : 2022-05-15
//problem : luogu P1456
//status : AC
//AC-time : 2022-5-15
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 200005;
struct zps{
    #define ls(x) t.ls[x]
    #define rs(x) t.rs[x]
    int ls[M], rs[M], dis[M]; bool f[M];
    int cnt, rt[M], s[M], laz1[M], laz2[M];
    void clr(int x) {s[x] = rs[x] = ls[x] = dis[x] = 0;}
    int find(int x) {return rt[x] == x ? x : rt[x] = find(rt[x]);}
    int build(int t, int pl) {ls[pl] = rs[pl] = 0; s[pl] = t; dis[pl] = 1; rt[pl] = pl; return pl;}
    int build(int t) {return build(t, ++cnt);}
    int _merge(int x, int y){
        if(!x || !y) return x|y;
        if(s[y] > s[x]) swap(x, y);
        rs[x] = _merge(rs[x], y);
        if(dis[rs[x]] > dis[ls[x]]) swap(ls[x], rs[x]);
        dis[x] = dis[rs[x]] + 1;
        return x;
    }
    int merge(int x, int y){
        return rt[x] = rt[y] = _merge(x, y);
    }
    int top(int x) {return s[find(x)];}
    int pop(int x){
        x = find(x); rt[x] = merge(ls[x], rs[x]);
        clr(x); return rt[x];
    }
    void print(int x){
        if(!x) return;
        printf("%d-%d ", x, s[x]); print(ls[x]); print(rs[x]);
    }
}t;
int n, m, a[M];
int main(){
    while(~scanf("%d", &n)){
        t.cnt = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            t.build(a[i], i);
        scanf("%d", &m);
        while(m--){
            int x, y; scanf("%d %d", &x, &y); x = t.find(x); y = t.find(y);
            if(x == y) {printf("-1\n"); continue;}
            int s1 = t.top(x), s2 = t.top(y);
            int pl1 = t.pop(x), pl2 = t.pop(y);
            int a = t.merge(pl1, t.build(s1/2, x)), b = t.merge(pl2, t.build(s2/2, y));
            t.merge(a, b); printf("%d\n", t.top(a));
        }
    }
}