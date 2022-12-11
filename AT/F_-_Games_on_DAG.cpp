#include <cstdio>
#include <assert.h>
#include <cmath>
using namespace std;
const int M = 17, mod = 1000000007;
int add(int a, int b) {a += b; return a > mod ? a-mod : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void addn(int &x, int y) {x += y; if(x > mod) x -= mod;}
int c[M][1 << M], f[1 << M], e[M], lg[1 << M], t[M * M];
int n, m; 
int main(){
  scanf("%d %d", &n, &m);
  t[0] = 1;
  for(int i = 1; i < n*n; i++) t[i] = 1ll * t[i-1] * 2 % mod;
  for(int i = 0; i < n; i++) lg[1 << i] = i;
  for(int i = 1; i <= m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    --u; --v;
    e[u] |= 1 << v; c[u][1 << v] = 1;
  }
  auto chk = [](int x, int S) -> bool {
    int ans = 0;
    for(int i = 0; i < n; i++) if(S & (1 << i)) ans += ((e[x] >> i) & 1);
    return ans;
  } ;
  const int all = (1 << n) - 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 1 << n; j++) {
      int t = j & -j;
      c[i][j] = c[i][j ^ t] + c[i][t];
    }
  }
  auto valid = [](int t) -> bool {return (t & 1) == ((t >> 1) & 1);};
  f[0] = 1;
  for(int S = 1; S < 1 << n; S++) {
    if(!valid(S)) continue;
    f[S] = 1; // 所有点 sg=0
    for(int T = S; T; T = S & (T-1)) {
      if(!valid(T)) continue;
      int U = S ^ T, ans = 1;
      for(int i = T; i; i -= i & -i) {
        int s = lg[i & -i]; 
        ans = 1ll * ans * (t[c[s][U]] - 1) % mod;
      }
      for(int j = U; j; j -= j & -j) {
        int u = lg[j & -j]; 
        ans = 1ll * ans * t[c[u][T]] % mod;
      }
      addn(f[S], 1ll * f[T] * ans % mod);
    }
    // printf("%d:%d\n", S, f[S]);
  }
  int ans = t[m]; // printf("ans=%d\n", ans);
  ans -= f[all]; ans %= mod; ans += mod; ans %= mod;
  printf("%d\n", ans);
}
