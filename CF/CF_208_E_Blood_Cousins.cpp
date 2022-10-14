#include <cstdio>
#include <vector>
using namespace std;
const int M = 100005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1, fa[M];
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, f[M][25], dep[M], in[M], out[M], rk[M], cnt[M], cnt2;
void dfs(int u){
    in[u] = ++cnt2; rk[cnt2] = u; dep[u] = dep[f[u][0]] + 1;
    for(int i = 1; i <= 23; i++) f[u][i] = f[f[u][i-1]][i-1];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs(v);
    }
    out[u] = cnt2;
}
int getkth(int u, int k){
    for(int i = 23; i >= 0; i--) if(k >> i & 1)
        u = f[u][i];
    return u;
}
struct tp {int id, p;};
vector<tp> q[M]; int ans[M];
void getans(int u){
    ++cnt[dep[u]];
    // printf("u=%d\n", u);
    // for(int i = 0; i <= n; i++) printf("%d ", cnt[i]);
    // printf("\n");
    for(tp t : q[u]) ans[t.id] = -cnt[dep[u] + t.p];
    for(int i = head[u]; i; i = e[i].nxt){
        getans(e[i].to);
    }
    // --cnt[dep[u]];
    for(tp t : q[u]) ans[t.id] += cnt[dep[u] + t.p];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &f[i][0]);
        if(f[i][0] == 0) f[i][0] = i;
        else link(f[i][0], i);
    }
    for(int i = 1; i <= n; i++) if(f[i][0] == i) dfs(i);
    // for(int i = 1; i <= n; i++) printf("%d ", dep[i]);
    // printf("\n");
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        int v, p;
        scanf("%d %d", &v, &p);
        if(dep[v] <= p) {ans[i] = 0; continue;}
        v = getkth(v, p); q[v].push_back({i, p});
        // printf("v=%d\n", v);
    }
    for(int i = 1; i <= n; i++) if(f[i][0] == i) getans(i);
    for(int i = 1; i <= m; i++) printf("%d ", ans[i] ? ans[i] - 1 : 0);
}