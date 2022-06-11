#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
struct zps{
    int ls[M], rs[M], dis[M]; bool f[M];
    int n, rt[M];
    struct tp{
        int id, v;
        bool operator < (const tp &t) const{
            return v ^ t.v ? v < t.v : id < t.id;
        }
    }val[M];
    void init(int n_) {n = n_; for(int i = 1; i <= n; i++) rt[i] = i;}
    int find(int x) {return rt[x] == x ? x : rt[x] = find(rt[x]);}
    int merge(int x, int y){
        if(!x || !y) return x|y;
        if(val[y] < val[x]) swap(x, y);
        rs[x] = merge(rs[x], y);
        if(dis[rs[x]] > dis[ls[x]]) swap(ls[x], rs[x]);
        dis[x] = dis[rs[x]] + 1;
        return x;
    }
    int pop(int x){
        x = find(x); f[x] = 0;
        rt[rs[x]] = rt[ls[x]] = rt[x] = merge(rs[x], ls[x]);
        dis[x] = rs[x] = ls[x] = 0;
        return val[x].v;
    }
}t;
int n, m, a[M];
int main(){
    scanf("%d", &n); t.init(n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        t.val[i] = {i, a[i]}; t.f[i] = t.dis[i] = 1;
    }
    scanf("%d", &m);
    while(m--){
        char op; int x, y;
        scanf(" %c %d", &op, &x);
        if(op == 'M'){
            scanf("%d", &y);
            if(!t.f[x] || !t.f[y]) continue;
            x = t.find(x); y = t.find(y);
            if(x != y) t.rt[x] = t.rt[y] = t.merge(x, y);
        } else {
            if(!t.f[x]) {puts("0"); continue;}
            printf("%d\n", t.pop(x));
        }
    }
}