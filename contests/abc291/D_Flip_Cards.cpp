#include <cstdio>
using namespace std;
const int mod = 998244353, M = 2e5 + 5;
struct modint {
  int x;
  modint(int o = 0) {x = o;}
  modint &operator = (int o) {return x = o, *this;}
  modint &operator += (modint o) {return x = x+o.x >= mod ? x+o.x-mod : x+o.x, *this;}
  modint &operator -= (modint o) {return x = x-o.x < 0 ? x-o.x+mod : x-o.x, *this;}
  modint &operator *= (modint o) {return x = 1ll*x*o.x%mod, *this;}
  modint &operator ^= (int b) {
    modint a = *this, c = 1;
    for(; b; b >>= 1, a *= a) if(b & 1) c *= a;
    return x=c.x, *this;
  }
  modint &operator /= (modint o) {return *this *= o ^= mod-2;}
  friend modint operator + (modint a, modint b) {return a += b;}
  friend modint operator - (modint a, modint b) {return a -= b;}
  friend modint operator * (modint a, modint b) {return a *= b;}
  friend modint operator / (modint a, modint b) {return a /= b;}
  friend modint operator ^(modint a,int b) {return a ^= b;}
  friend bool operator == (modint a, int b) {return a.x == b;}
  friend bool operator != (modint a, int b) {return a.x != b;}
  bool operator ! () {return !x;}
  modint operator - () {return x ? mod-x : 0;}
  bool operator < (const modint &b) const {return x < b.x;}
};
inline modint qpow(modint x, int y) {return x ^ y;}
int a[M][2]; modint dp[M][2];
int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i][0], &a[i][1]);
  }
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (a[i][j] != a[i-1][k]) dp[i][j] += dp[i-1][k];
      }
    }
  }
  printf("%d\n", dp[n][0] + dp[n][1]);
}