#include <cstdio>
#include <algorithm>
#define D 30
using namespace std;
const int M = 5000005;
struct Trie{
    int rt[M], son[M][2], cnt[M], cnt1;
    inline int build() {return ++cnt1;}
    void ins(int &p, int q, int k, int dep){
        // 改掉下面层数就能过
        if(dep == -2) return;
        cnt[p = build()] = cnt[q] + 1; son[p][0] = son[q][0]; son[p][1] = son[q][1];
        // if(!dep) return;
        ins(son[p][(k >> dep) & 1], son[q][(k >> dep) & 1], k, dep-1);
    }
    int query(int l, int r, int k, int dep){
        if(l > r) printf("error! p=%d q=%d\n", l, r); 
        int val = (k >> dep) & 1;
        if(dep == -1) return 0;
        if(cnt[son[r][val ^ 1]] - cnt[son[l][val ^ 1]]) return (1 << dep) | query(son[l][val^1], son[r][val^1], k, dep-1);
        return query(son[l][val], son[r][val], k, dep-1);
    }
    void debug(int l, int r, int dep){
        if(dep == -1) return;
        printf("now l=%d r=%d dep=%d cnt=%d\n", l, r, dep, cnt[r] - cnt[l]);
        if(cnt[son[r][0]] - cnt[son[l][0]]) {printf("to l\n"); debug(son[l][0], son[r][0], dep-1);}
        if(cnt[son[r][1]] - cnt[son[l][1]]) printf("to r\n"), debug(son[l][1], son[r][1], dep-1);
        printf("end l=%d r=%d dep=%d\n", l, r, dep);
    }
} s1, s2;
int n, q, val[M];
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int in[M], out[M], fa[M][25], rk[M], dfncnt, dep[M];
void dfs(int u, int f){
    in[u] = ++dfncnt; rk[dfncnt] = u; fa[u][0] = f; dep[u] = dep[f] + 1;
    s1.ins(s1.rt[u], s1.rt[fa[u][0]], val[u], D);
    s2.ins(s2.rt[u], s2.rt[rk[in[u]-1]], val[u], D);
    for(int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dfs(v, u);
    } out[u] = rk[dfncnt];
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 20; i >= 0; i--) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return u == v ? u : fa[u][0];
}
inline int op1(int x, int z){
    // printf("in %d out %d\n", rk[in[x]-1], out[x]);
    // s2.debug(s2.rt[rk[in[x]-1]], s2.rt[out[x]], D);
    return s2.query(s2.rt[rk[in[x]-1]], s2.rt[out[x]], z, D);
}
inline int op2(int x, int y, int z){
    int l = lca(x, y);
    // printf("lca of %d and %d is %d\n", x, y, l);
    // 下方别套 in 
    return std::max(s1.query(s1.rt[fa[l][0]], s1.rt[x], z, D), s1.query(s1.rt[fa[l][0]], s1.rt[y], z, D));
}
int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    dfs(1, 0);
    // for(int i = 1; i <= s2.cnt1; i++){
    //     printf("%d ls=%d rs=%d cnt=%d\n", i, s2.son[i][0], s2.son[i][1], s2.cnt[i]);
    // }
    while(q--){
        int op; scanf("%d", &op);
        if(op == 1){
            int x, z; scanf("%d %d", &x, &z);
            printf("%d\n", op1(x, z));
        } else {
            int x, y, z; scanf("%d %d %d", &x, &y, &z);
            printf("%d\n", op2(x, y, z));
        }
    }
}