#include <cstdio>
#include <algorithm>
#include <assert.h>
#define int long long
#define LL long long
using namespace std;
const int M = 2000005;
LL a[M], n, k, it[M], tim[M], laz;
bool check(LL t){
    LL ans = 0ll;
    for(int i = 1; i <= n; i++){
        ans += min(t, a[i]);
    }
    return ans <= k;
}
signed main(){
    scanf("%lld %lld", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    LL l = 0, r = 1e12, ans;
    while(l <= r){
        LL mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    // printf("ans=%lld\n", ans);
    LL t = 0;
    for(int i = 1; i <= n; i++){
        t += min(ans, a[i]);
        a[i] = max(a[i]-ans, 0ll);
    }
    k -= t;
    // printf("k=%lld\n", k);
    assert(k < n);
    int pl = 1;
    for(int i = 1; i <= n; i++){
        if(!k) break;
        if(a[i]) --a[i], --k;
    }
    for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
}