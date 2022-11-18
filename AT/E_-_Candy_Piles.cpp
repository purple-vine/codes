// agc002E
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int M = 1e5 + 10;
int a[M], n; bool sg[M][2];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    int p = 1;
    for(int i = 1; i <= n; i++) if(a[i] >= i) p = i;
    bool f1 = (a[p] - p + 1) % 2 == 0;
    int k = p; while(a[k+1] >= p && k+1 <= n) ++k;
    bool f2 = (k - p) % 2 == 1;
    if(f1 || f2) puts("First");
    else puts("Second");
    // printf("p=%d k=%d f1=%d f2=%d\n", p, k, f1, f2);
}