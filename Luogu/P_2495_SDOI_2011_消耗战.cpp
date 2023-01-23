#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define int long long
#define LL long long
using namespace std;
const int M = 1e6 + 5;
const LL inf = 998244353998244353;
struct edge {
  int to, nxt, w;
} e[M << 1];
int head[M], cnt1;
void link(int u, int v, int w){
  e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
}
namespace LCA {
  int f[M][22], d[M], mx[M][22];
  void dfs(int u, int fa) {
    if(u == 1) memset(mx, 0x3f, sizeof(mx));
    f[u][0] = fa; d[u] = d[fa] + 1;
    for(int i = 1; i <= 20; i++) f[u][i] = f[f[u][i - 1]][i - 1], mx[u][i] = min(mx[u][i-1], mx[f[u][i-1]][i-1]);
    for(int i = head[u]; i; i = e[i].nxt){
      int v = e[i].to; if(v == fa) continue; mx[v][0] = e[i].w; dfs(v, u);
    }
  }
  int lca(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    for(int i = 20; i >= 0; i--) if(d[f[u][i]] >= d[v]) u = f[u][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    return u == v ? u : f[u][0];
  }
  int dis(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    int ans = inf;
    for(int i = 20; i >= 0; i--) if(d[f[u][i]] >= d[v]) ans = min(ans, mx[u][i]), u = f[u][i];
    return ans;
  }
}
int dfn[M], cnt; 
void dfs(int u, int fa) {
  dfn[u] = ++cnt;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to; if(v == fa) continue;
    dfs(v, u); 
  }
}
int dis(int u, int v) {
  // printf("dis %d %d = %d\n", u, v, LCA::dis(u, v));
  return LCA::dis(u, v);
}
vector<int> s[M]; // 虚树
LL dp[M]; bool vis[M];
int n;
LL solve(vector<int> &t) {
  static int st[M], top;
  vector<int> k;
  sort(t.begin(), t.end(), [](int a, int b) {return dfn[a] < dfn[b];});
  st[++top] = 1;
  for(auto u : t) {
    vis[u] = 1;
    if(u == 1) continue;
    int l = LCA::lca(u, st[top]);
    while(dfn[st[top]] > dfn[l]) {
      if(dfn[st[top-1]] <= dfn[l]) s[l].push_back(st[top]);
      else s[st[top-1]].push_back(st[top]);
      k.push_back(st[top]); --top;
    }
    if(st[top] != l) st[++top] = l;
    st[++top] = u;
  }
  while(top) {
    s[st[top-1]].push_back(st[top]);
    k.push_back(st[top]);
    --top;
  }
  auto dfs = [&](auto self, int u) -> void {
    dp[u] = 0;
    for(auto v : s[u]) {
      self(self, v);
      if(vis[v]) dp[u] += dis(u, v);
      else dp[u] += min(dp[v], 1ll * dis(u, v));
    }
    // printf("%d : %d\n", u, dp[u]);
  }; 
  dfs(dfs, 1);
  for(auto u : k) s[u].clear(), vis[u] = 0;
  k.clear();
  return dp[1];
}
signed main() {
  scanf("%lld", &n);
  for(int i = 1, u, v, w; i < n; i++) {
    scanf("%lld %lld %lld", &u, &v, &w);
    link(u, v, w); link(v, u, w);
  }
  LCA::dfs(1, 0); dfs(1, 0);
  int m; scanf("%lld", &m);
  while(m--) {
    int k; scanf("%lld", &k);
    vector<int> t;
    for(int i = 0, u; i < k; i++) scanf("%lld", &u), t.push_back(u);
    printf("%lld\n", solve(t));
  }
}