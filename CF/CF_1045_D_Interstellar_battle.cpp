#include <cstdio>
using namespace std;
const int M = 100005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, fa[M]; double p[M], sum[M], ans;
void dfs(int u, int f){
    fa[u] = f;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dfs(v, u); sum[u] += p[v];
    }
    ans += p[u] - p[u] * sum[u];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf", &p[i]), p[i] = 1 - p[i];
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        ++u; ++v;
        link(u, v); link(v, u);
    }
    dfs(1, 0);
    int q; scanf("%d", &q);
    while(q--){
        int u; double t; scanf("%d %lf", &u, &t); t = 1-t; ++u;
        ans -= p[fa[u]] - p[fa[u]] * sum[fa[u]];
        ans -= p[u] - p[u] * sum[u];
        sum[fa[u]] -= p[u]; p[u] = t; sum[fa[u]] += p[u];
        ans += p[fa[u]] - p[fa[u]] * sum[fa[u]];
        ans += p[u] - p[u] * sum[u];
        printf("%.5lf\n", ans);
    }
}