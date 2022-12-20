#include <cstdio>
// #define int long long
#define inf 1e9
using namespace std;
const int M = 1e5 + 5;
int g[M], f[M], cnt[M], ans, L = 1, R = 0, a[M];
#define lowbit(x) (x & -x)
int s[M], n;
void upd(int x, int t){
    for(; x <= n; x += lowbit(x)) s[x] += t;
} 
int query(int x){
    int ans = 0;
    for(; x >= 1; x -= lowbit(x)) ans += s[x];
    return ans;
}
void add(int x) {ans += query(n) - query(x); upd(x, 1);}
void subt(int x) {ans -= query(n) - query(x); upd(x, -1);}
int calc(int l, int r) {
    while(R < r) {
        ans += query(a[++R]); upd(a[R], 1);
        // printf("[%d, %d] : %d\n", L, R, ans);
    }
    while(L > l) {
        ans += R-L+1; ans -= query(a[--L]); upd(a[L], 1);
        // printf("[%d, %d] : %d\n", L, R, ans);
    }
    while(R > r) {
        upd(a[R], -1); ans -= query(a[R--]); 
        // printf("[%d, %d] : %d\n", L, R, ans);
    }
    while(L < l) {
        upd(a[L], -1); ans += query(a[L++]); ans -= R-L+1; 
        // printf("[%d, %d] : %d\n", L, R, ans);
    }
    // printf("ans of [%d,%d] is %d\n", l, r, ans);
    return ans;
}
void solve(int l, int r, int sl, int sr) {
    if(l > r || sl > sr) return;
    int mid = l + r >> 1, pl = 0;
    for(int i = sl; i <= sr; i++) {
        if(i > mid) continue;
        int tmp = g[i-1] + calc(i, mid);
        if(f[mid] > tmp) f[mid] = tmp, pl = i;
    }
    solve(l, mid-1, sl, pl); solve(mid+1, r, pl, sr);
}
signed main(){
    int k; scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) f[i] = inf;
    for(int i = 1; i <= k; i++) {
        for(int i = 1; i <= n; i++) g[i] = f[i], f[i] = inf;
        solve(1, n, 1, n);
        // for(int i = 1; i <= n; i++) printf("%d ", f[i]);
        // printf("\n");
    }
    printf("%d\n", f[n]);
}