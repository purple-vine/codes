#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1005, mod = 31011;
struct edge {
    int u, v, w;
} e[M << 1];
int L[M], R[M], fa[M], sm[M], dep[M];
int find(int x) {return fa[x] == x ? x : find(fa[x]);}
int merge(int x, int y) {
    if(dep[x] > dep[y]) swap(x, y);
    if((x = find(x)) != (y = find(y))) return fa[y] = x, dep[x] += dep[x] == dep[y], y;
    return 0;
}
int sum;
void dfs(int t, int x, int c) {
    // printf("%d %d %d\n", t, x, c);
    if(t > R[x]) return sum += c == sm[x], void();
    int u = find(e[t].u), v = find(e[t].v);
    if(u != v) {
        int tmp = merge(u, v); dfs(t+1, x, c+1);
        fa[tmp] = tmp;
    }
    dfs(t+1, x, c);
}
int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        e[i] = {u, v, w};
    }
    sort(e+1, e+m+1, [](edge a, edge b) -> bool {return a.w < b.w;});
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        int j = 1;
        if(e[i].w != e[i-1].w) R[cnt] = i-1, L[++cnt] = i;
        int u = find(e[i].u), v = find(e[i].v);
        if(u != v) merge(u, v), ++sm[cnt];
    }
    R[cnt] = m;
    int tmp = 0;
    for(int i = 1; i <= n; i++) tmp += fa[i] == i;
    if(tmp != 1) return printf("0\n"), 0;
    int ans = 1;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= cnt; i++) {
        sum = 0; dfs(L[i], i, 0); ans = 1ll * ans * sum % mod;
        for(int j = L[i]; j <= R[i]; j++) merge(e[j].u, e[j].v);
    }
    printf("%d\n", ans);
}