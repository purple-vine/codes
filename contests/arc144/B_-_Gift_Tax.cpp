#include <cstdio>
#define LL long long
using namespace std;
const int M = 300005;
int n, x, y, a[M];
bool check(int t){
    // printf("t=%d\n", t);
    LL ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > t) ans1 += 1ll * (a[i] - t) / y;
        else if(a[i] < t) ans2 += 1ll * (t - a[i] - 1) / x + 1;
    }
    // printf("%lld %lld\n", ans1, ans2);
    return ans1 >= ans2;
}
int main(){
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = 1e9, ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    printf("%d\n", ans);
}