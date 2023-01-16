#include <cstdio>
#include <map>
#include <queue>
#include <tuple>
using namespace std;
const int M = 6e5 + 5;
struct edge {
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v) {
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
queue<tuple<int, int> > q;
int fa[M], siz[M];
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
int main() {
  int n, m, k; scanf("%d %d %d", &n, &m, &k);
  vector<map<int, int> > e(n+1);
  for(int i = 1; i <= n; i++) fa[i] = i;
  for(int i = 1; i <= m; i++) {
    int u, v, w; scanf("%d %d %d", &v, &u, &w);
    if(e[u][w]) q.push({e[u][w], v});
    else e[u][w] = v;
  }
  while(!q.empty()) {
    int u, v; tie(u, v) = q.front(); q.pop();
    // printf("merge %d %d\n", u, v);
    u = find(u); v = find(v); if(u == v) continue;
    if(e[u].size() < e[v].size()) swap(u, v);
    for(auto t : e[v]) {
      int x, y; tie(y, x) = t;
      if(e[u][y]) q.push({e[u][y], x});
      else e[u][y] = x;
    }
    fa[v] = u; e[v].clear();
  }
  for(int i = 1; i <= n; i++) ++siz[find(i)];
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    // printf("%d %d\n", i, siz[i]);
    ans += 1ll * siz[i] * (siz[i] - 1) / 2;
  }
  printf("%lld\n", ans);
}