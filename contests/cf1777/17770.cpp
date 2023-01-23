#include <cstdio>
using namespace std;
const int M = 105;
int s[M];
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &s[i]);
      if(i > 1 && (s[i] % 2) == (s[i-1] % 2)) ++cnt;
    }
    printf("%d\n", cnt);
  }
}