#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 1000005;
int n, a[M], ans; long long sum[M]; double avg[M];
int main(){
    freopen("ex_A2.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + 1ll * a[i];
        avg[i] = 1.0 * sum[i] / i;
    }
    for(int i = 1; i <= n; i++){
        int t = ceil(avg[i]), pl = lower_bound(a+1, a+n+1, t) - a;
        if(abs(a[pl] - avg[i]) < 1e-6) ++pl;
        ans = max(ans, i - pl + 1);
    }
    printf("%d\n", ans);
    return 0;
}