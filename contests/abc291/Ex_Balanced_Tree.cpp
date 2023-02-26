#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 2e5 + 5;
vector<int> e[M]; 
#define lowbit(x) (x & -x)
int cl[M], n, m;
int v[M];
void upd(int u, int x) { for(; u <= n; u += lowbit(u)) v[u] += x; }
int query(int u) { int res = 0; for (; u; u -= lowbit(u)) res += v[u]; return res; }
struct ev {
  int x, y, z, t;
} ;
int siz[M]; bool vis[M];
vector<ev> anc[M], q[M];
int rt, fa[M];
// 重新计算子树大小并连边
void dfs(int u, int fa, int mn = 1e9, int mx = -1e9) { 
  mn = min(mn, u), mx = max(mx, u);
  anc[u].push_back({mn, mx, rt}), q[rt].push_back({mn, mx, cl[u], 0});
  siz[u] = 1;  
  for (auto v : e[u]) {
    if(v == fa || vis[v]) continue;
    dfs(v, u, mn, mx); siz[u] += siz[v];
  }
}
int ss, mx, pl;
// 计算重心
void get(int u, int fa) {
  int m = 0; siz[u] = 1;
  for (auto v : e[u]) {
    if(v == fa || vis[v]) continue;
     get(v, u); siz[u] += siz[v]; m = max(m, siz[v]);
  }
  m = max(m, ss - siz[u]); if(m < mx) mx = m, pl = u;
  // printf("%d : %d %d %d\n", u, m, siz[u], ss);
}
// 返回重心
inline int get(int u) {
  ss = siz[u]; mx = 1e9; get(u, 0); return pl;
}
// 直接传入重心
void build(int u) {
  vis[u] = 1; rt = u; dfs(u, 0);
  for (auto v : e[u]) {
    if(vis[v]) continue;
    int rt = get(v); fa[rt] = u; build(rt);
  }
}
int ans[M], mn[M];
void solve() {
  siz[1] = n; build(get(1)); 
  for (int i = 1; i <= n; i++) {
    printf("%d ", fa[i] == 0 ? -1 : fa[i]);
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    e[v].push_back(u), e[u].push_back(v);
  }
  solve();
}