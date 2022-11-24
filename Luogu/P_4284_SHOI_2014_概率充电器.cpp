#include <cstdio>
#include <cmath>
using namespace std;
const int M = 5e5 + 5;
struct edge{
    int to, nxt, w;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v, int w){
    e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
}
int n, p[M]; double q[M], ans[M];
void dfs1(int u, int fa) {
    q[u] = p[u] / 100.0;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to; if(v == fa) continue; dfs1(v, u);
        q[u] += q[v] * (1 - q[u]) * e[i].w / 100.0;
    }
}
void dfs2(int u, int fa) {
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to, w = e[i].w;
        if(v == fa) continue;
        if(fabs(1 - q[v] * w / 100.0) < 1e-8) {dfs2(v, u); continue;}
        double tmp = (q[u] - (q[v] * w / 100.0)) / (1 - (q[v] * w / 100.0));
        // printf("q1=%lf e=%d q2=%lf\n", q[u], w, q[v]);
        // printf("v=%d tmp=%lf\n", v, tmp);
        q[v] += tmp * (1 - q[v]) * w / 100.0;
        dfs2(v, u);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        link(u, v, w); link(v, u, w);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    dfs1(1, 0);
    dfs2(1, 0);
    double tot = 0; 
    for(int i = 1; i <= n; i++) tot += q[i];
    printf("%.6lf\n", tot);
    return 0;
}