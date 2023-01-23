#include <cstdio>
using namespace std;
const int M = 1e5 + 5, mod = 1e9 + 7;
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    if(n == 1) {printf("0\n"); continue;}
    int ans = 1;
    for(int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
    ans = 1ll * ans * n % mod * (n-1) % mod;
    printf("%d\n", ans);
  }
}