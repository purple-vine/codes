#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
const int M = 1e5 + 5;
int m; LL a[M]; int dp[63][M];
int main() {
  int n; scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  sort(a+1, a+n+1);
  for(int i = 1; i <= n; i++) a[i] = a[n] - a[i];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for(int i = 0; i < 60; i++) {
    LL all = (1ll << i) - 1;
    sort(a+1, a+n+1, [&](LL x, LL y) -> bool {return (x & all) > (y & all);});
    int cnt1 = 0, cnt2 = 0;
    for(int j = 1; j <= n; j++) cnt1 += (a[j] >> i) & 1;
    for(int j = 0; j <= n; j++) {
      cnt2 += (a[j] >> i) & 1;
      int s1 = cnt2, s2 = j - cnt2, s3 = cnt1 - cnt2, s4 = n - j - cnt1 + cnt2;
      dp[i+1][s1+s2+s3] = min(dp[i+1][s1+s2+s3], dp[i][j] + s1 + s4);
      dp[i+1][s1] = min(dp[i+1][s1], dp[i][j] + s2 + s3);
    } 
  }
  printf("%d\n", dp[60][0]);
}