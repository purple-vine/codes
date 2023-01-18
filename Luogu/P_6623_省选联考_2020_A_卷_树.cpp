#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int M = 5e5 + 5, m = 21;
int v[M]; vector<int> e[M];
int w[m][M]; // mod 2^i = j 的所有差分数组需要 xor 上 2^i
int sum;
int dfs(int u, int d) {
  int ans = v[u];
  for(int i = 0; i < m; i++) w[i][(d + v[u]) & ((1 << i) - 1)] ^= (1 << i);
  for(int i = 0; i < m; i++) ans ^= w[i][d & ((1 << i) - 1)];
  for(auto v : e[u]) {
    ans ^= dfs(v, d+1);
  }
  for(int i = 0; i < m; i++) ans ^= w[i][d & ((1 << i) - 1)];
  sum += ans;
  return ans;
}
signed main() {
  int n; scanf("%lld", &n);
  for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);
  for(int i = 2, f; i <= n; i++) {
    scanf("%lld", &f); e[f].push_back(i);
  }
  dfs(1, 0);
  printf("%lld\n", sum);
}