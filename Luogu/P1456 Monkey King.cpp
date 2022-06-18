#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
struct zps{
    int ls[M], rs[M], dis[M]; bool f[M];
    int n, rt[M], val[M];
    void init(int n_) {n = n_; for(int i = 1; i <= n; i++) rt[i] = i;}
    int find(int x) {return rt[x] == x ? x : rt[x] = find(rt[x]);}
    int build(int t) {val[++n] = t; dis[n] = 1; rt[n] = n; return n;}
    int merge(int x, int y){
        if(!x || !y) return x|y;
        if(val[y] > val[x]) swap(x, y);
        rs[x] = merge(rs[x], y);
        if(dis[rs[x]] > dis[ls[x]]) swap(ls[x], rs[x]);
        dis[x] = dis[rs[x]] + 1;
        return x;
    }
    int pop(int x){
        x = find(x); f[x] = 0;
        rt[rs[x]] = rt[ls[x]] = rt[x] = merge(rs[x], ls[x]);
        dis[x] = rs[x] = ls[x] = 0;
        return val[x];
    }
}t;
int n, m, a[M];
int main(){
    scanf("%d", &n); t.init(n*2);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        t.val[i] = a[i]; t.f[i] = t.dis[i] = 1;
    }
    scanf("%d", &m);
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        x = t.find(x); y = t.find(y); int lx = t.ls[x], ly = t.ls[y];
        if(x == y) {printf("-1\n"); continue;}
        int xx = t.pop(x), yy = t.pop(y); printf("%d\n", max(xx, yy) / 2);
        int plx = t.build(xx/2), ply = t.build(yy/2);
        plx = t.merge(plx, ply); ply = t.merge(lx, ly);
        t.merge(plx, ply);
    }
}