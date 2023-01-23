#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1e5 + 5;
vector<int> fac[M];
int a[M];
void work() {
  int n, m; scanf("%d %d", &n, &m);
  vector<int> b(m+1);
  for(int i = 1; i <= n; i++) 
    scanf("%d", &a[i]); 

  sort(a + 1, a + n + 1);
  int cnt = 0;
  auto add = [&](int x) -> void {
    for(auto s : fac[x]) {
      if(s > m) break;
      b[s]++;
      if(b[s] == 1) ++cnt;
    }  
  ;};
  auto del = [&](int x) -> void {
    for(auto s : fac[x]) {
      if(s > m) break;
      --b[s];
      if(b[s] == 0) --cnt;
    }
  } ;
  int ans = 0, mx = 998244353;
  for(int l = 1, r = 0; l <= n; l++) {
    while(r < n && cnt < m) add(a[++r]);
    if(cnt == m) mx = min(mx, a[r] - a[l]);
    del(a[l]);
  }
  printf("%d\n", mx == 998244353 ? -1 : mx);
}
void pre(int m) {
  for(int i = 1; i <= m; i++) 
    for(int j = i; j <= m; j += i) 
      fac[j].push_back(i);
}
int main() {
  int t; scanf("%d", &t);
  pre(1e5 + 1);
  while(t--) work();
}