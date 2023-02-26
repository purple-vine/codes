#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int a[505];
int main() {
  int n; scanf("%d", &n);
  set<int> s;
  for (int i = 1; i <= 5 * n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 5 * n + 1);
  int ans = 0;
  for(int i = n + 1; i <= 4 * n; i++) ans += a[i];
  printf("%lf\n", 1.0 * ans / 3 / n);
}