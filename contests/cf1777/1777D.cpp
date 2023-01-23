#include <cstdio>
#include <vector>
using namespace std;
const int M = 2e5 + 5, mod = 1e9 + 7;
vector<int> e[M];
int t[M], dep[M];
int ans;
void dfs(int u, int fa) {
  for(auto v : e[u]) {
    if(v == fa) continue;
    dep[v] = dep[u] + 1; dfs(v, u);
  }
  ans += t[dep[u]] - 1;
  ans %= mod;
}
int main() {
  int T; scanf("%d", &T);
  t[0] = 1;
  for(int i = 1; i <= 200000; i++) t[i] = t[i-1] * 2ll % mod;
  while(T--) {
    int n; scanf("%d", &n); ans = 0;
    for(int i = 1; i < n; i++) {
      int u, v; scanf("%d %d", &u, &v);
      e[u].push_back(v); e[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) e[i].clear();
  }
}