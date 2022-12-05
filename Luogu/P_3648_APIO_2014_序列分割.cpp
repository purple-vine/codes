#include <cstdio>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;
const int M = 1e5 + 5, N = 200;
LL k[M], b[M], x[M]; int s[M << 2];
#define f(i, t) (b[t] + k[t] * x[i])
void upd(int o, int l, int r, int t) {
    int mid = l + r >> 1;
    if(f(mid, s[o]) < f(mid, t)) swap(s[o], t);
    if(f(l, s[o]) < f(l, t)) upd(o<<1, l, mid, t);
    if(f(r, s[o]) < f(r, t)) upd(o<<1|1, mid+1, r, t);
}

pair<LL, int> query(int o, int l, int r, int p) {
    if(l == r) return {f(p, s[o]), s[o]};
    int mid = l + r >> 1;
    return max({f(p, s[o]), s[o]}, p <= mid ? query(o<<1, l, mid, p) : query(o<<1|1, mid+1, r, p));
}
void clr(int o, int l, int r) {
    s[o] = 0; if(l == r) return;
    int mid = l + r >> 1;
    clr(o<<1, l, mid); clr(o<<1|1, mid+1, r);
}
int n, K, a[M], path[N][M]; LL dp[N][M], sm[M];
int main() {
    scanf("%d %d", &n, &K);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sm[i] = a[i] + sm[i-1];
    for(int i = 1; i <= n; i++) x[i] = sm[i];
    for(int i = 1; i <= K; i++) {
        clr(1, 1, n);
        for(int j = 1; j <= n; j++) {
            auto tmp = query(1, 1, n, j);
            dp[i][j] = tmp.first; path[i][j] = tmp.second;
            k[j] = sm[j]; b[j] = -sm[j] * sm[j] + dp[i-1][j];
            upd(1, 1, n, j); 
        }
    }
    printf("%lld\n", dp[K][n]);
    int x = K, y = n;
    while(x != 0) {
        int t = path[x--][y];
        printf("%d ", y = path[x--][y]);
    }
}