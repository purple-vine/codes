#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1000005;
long long n, a[M], sum[M];
bool check(long long t, int st){
    int pl = st;
    for(int k = 1; k <= 3; k++){
        int to = lower_bound(sum+1, sum+2*n+1, sum[pl-1]+t) - sum + 1;
        pl = to;
    }
    return pl <= n+st;
}
bool check(long long tt){
    for(int i = 1; sum[i] <= sum[n]/3; i++){
        if(check(tt, i)) return 1;
    }
    return 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) a[i+3*n] = a[i+2*n] = a[i+n] = a[i];
    for(int i = 1; i <= 4*n; i++) sum[i] = sum[i-1] + a[i];
    // for(int i = 1; i <= 3*n; i++) printf("%d:%d ", i, sum[i]);
    long long l = 1, r = sum[n], ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    printf("%lld\n", ans);
    return 0;
}