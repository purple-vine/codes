// CF1172D
#include <bits/stdc++.h>
const int M = 1005;
int main() {
  int n; scanf("%d", &n);
  std::vector<std::tuple<int, int, int, int> > ans;
  std::vector<int> a(n+1), b(n+1), p(n+1), q(n+1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]), q[b[i]] = i;
  for (int i = 1; i < n; i++) {
    auto swapa = [&](int u, int v) -> void {
      std::swap(p[a[u]], p[a[v]]), std::swap(a[u], a[v]);
    } ;
    auto swapb = [&](int u, int v) -> void {
      std::swap(q[b[u]], q[b[v]]), std::swap(b[u], b[v]);
    } ;
    int u = p[i], v = q[i];
    if (p[i] == i && q[i] == i) continue;
    ans.push_back({i, q[i], p[i], i});
    swapa(i, p[i]), swapb(i, q[i]);
  }
  printf("%d\n", ans.size());
  for (auto [a, b, c, d] : ans) 
    printf("%d %d %d %d\n", a, b, c, d);
}
/*
stupid mistakes:
  - 输入错位
*/