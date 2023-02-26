#include <cstdio>
#include <map>
using namespace std;
const int M = 2e5 + 5;
map<pair<int, int>, bool> vis;
int main() {
  int n; scanf("%d", &n);
  int x = 0, y = 0; vis[{0, 0}] = 1;
  for (int i = 1; i <= n; i++) {
    char p; scanf(" %c", &p);
    // printf("%c ", p);
    if(p == 'R') ++x;
    else if (p == 'L') --x;
    else if (p == 'U') ++y;
    else if (p == 'D') --y;
    // printf("%d %d\n", x, y);
    if (vis[{x, y}] == 1) return printf("Yes\n"), 0;
    vis[{x, y}] = 1;
  }
  printf("No\n");
}