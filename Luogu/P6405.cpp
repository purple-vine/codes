#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#define d(x, y) ((x-1)*n + y)
#define eps (1e-12)
using namespace std;
const int M = 1005, N = 6000005;
int a[M][M], v[M][M], n;
struct edge{
    int u, v; double w;
}e[N];
int cnt1;
void link(int u, int v, double w){
    // printf("%d-%d %lf\n", u, v, w);
    e[++cnt1] = {u, v, w};
}
bool same(edge a, edge b) {return (fabs(a.w-b.w) <= eps);}
bool cmp(edge a, edge b) {return a.w < b.w;}
struct mdf{
    int x, y, dh;
};
struct bcj{
    int fa[N], h[N], siz[N];
    int find(int x) {return fa[x] == x ? x : find(fa[x]);}
    mdf q[N]; int top;
    void merge(int x, int y){
        if((x = find(x)) != (y = find(y))){
            if(h[x] <= h[y]) swap(x, y);
            siz[x] += siz[y]; fa[y] = x; h[x] += h[x] == h[y];
            q[++top] = {x, y, h[x] == h[y]};
        }
    }
    void roll(int x){
        while(top > x){
            int x = q[top].x, y = q[top].y, dh = q[top].dh;
            siz[x] -= siz[y]; fa[y] = y; h[x] -= dh; --top;
        }
    }
}t;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n*n; i++) t.fa[i] = i, t.siz[i] = t.h[i] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < n; j++)
            if(v[i][j] != v[i][j+1]){
                double tim = -1.0 * (a[i][j] - a[i][j+1]) / (v[i][j] - v[i][j+1]);
                if(tim > 0) link(d(i, j), d(i, j+1), tim);
            } else {
                if(a[i][j] == a[i][j+1]) t.merge(d(i, j), d(i, j+1));
            }
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= n; j++)
            if(v[i][j] != v[i+1][j]){
                double tim = -1.0 * (a[i][j] - a[i+1][j]) / (v[i][j] - v[i+1][j]);
                if(tim > 0) link(d(i, j), d(i+1, j), tim);
            } else {
                if(a[i+1][j] == a[i][j]) t.merge(d(i+1, j), d(i, j));
            }
    sort(e+1, e+cnt1+1, cmp);
    int ans = 1, num = t.top;
    for(int i = 1, j = 1; i <= cnt1; i = j){
        while(same(e[i], e[j])){
            t.merge(e[j].u, e[j].v);
            ans = max(ans, t.siz[t.find(e[j].u)]); ++j;
        }
        t.roll(num);
    }   
    printf("%d\n", ans);
}