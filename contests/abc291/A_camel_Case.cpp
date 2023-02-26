#include <cstdio>
#include <cstring>
using namespace std;
char s[105];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if('A' <= s[i] && s[i] <= 'Z') printf("%d\n", i);
  }
}