#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 200005;
int n, a[M], b[M];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b+1, b+n+1); LL ans = 0; for(int i = n/2+1; i <= n; i++) ans += 1ll * b[i];
    for(int i = 1; i <= n; i++) a[i] = lower_bound(b+1, b+n+1, a[i]) - b;
    int mxd = -1, mxp = -1, h = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > n/2) ++h;
        else --h;
        if(h >= mxd) mxd = h, mxp = i;
    }
    printf("%d %lld\n", mxp, ans);
}