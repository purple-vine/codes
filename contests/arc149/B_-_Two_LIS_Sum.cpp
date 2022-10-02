#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 300005;
int a[M], b[M], pl[M], n, dp[M];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &pl[a[i]]);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        *lower_bound(dp + 1, dp + n + 1, pl[i]) = pl[i];
    printf("%d\n", n + (lower_bound(dp + 1, dp + n + 1, 0x3f3f3f3f) - (dp + 1)));
}