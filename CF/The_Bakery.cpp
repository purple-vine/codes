#include <cstdio>
// #define int long long
#define inf 1e9
using namespace std;
const int M = 1e5 + 5;
int g[M], f[M], cnt[M], ans, L = 1, R = 0, a[M];
void add(int x) {ans += !cnt[x]++;}
void subt(int x) {ans -= !--cnt[x];}
int calc(int l, int r) {
    while(R < r) add(a[++R]);
    while(L > l) add(a[--L]);
    while(R > r) subt(a[R--]);
    while(L < l) subt(a[L++]);
    // printf("ans of [%d,%d] is %d\n", l, r, ans);
    return ans;
}
void solve(int l, int r, int sl, int sr) {
    if(l > r || sl > sr) return;
    int mid = l + r >> 1, pl = 0;
    for(int i = sl; i <= sr; i++) {
        if(i > mid) continue;
        int tmp = g[i-1] + calc(i, mid);
        if(f[mid] < tmp) f[mid] = tmp, pl = i;
    }
    solve(l, mid-1, sl, pl); solve(mid+1, r, pl, sr);
}
signed main(){
    int n, k; scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= k; i++) {
        for(int i = 1; i <= n; i++) g[i] = f[i], f[i] = 0;
        solve(1, n, 1, n);
        // for(int i = 1; i <= n; i++) printf("%d ", f[i]);
        // printf("\n");
    }
    printf("%d\n", f[n]);
}