#include <cstdio>
#define int long long
#define LL long long
using namespace std;
const int M = 200005;
int n, q, s, t, a[M], b[M]; LL ans;
int calc(int m) {
    if(m > 0) return - 1ll * m * s;
    else return - 1ll * m * t;
}
signed main(){
    scanf("%lld %lld %lld %lld", &n, &q, &s, &t);
    ++n;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i] - a[i-1];
        if(i == 1) continue;
        ans += calc(b[i]);
    }
    while(q--) {
        int l, r, x; scanf("%lld %lld %lld", &l, &r, &x);
        ++l; ++r;
        if(l >= 2 && l <= n) ans -= calc(b[l]);
        if(2 <= r+1 && r+1 <= n) ans -= calc(b[r+1]);
        b[l] += x; b[r+1] -= x;
        if(l >= 2 && l <= n) ans += calc(b[l]);
        if(2 <= r+1 && r+1 <= n) ans += calc(b[r+1]);
        printf("%lld\n", ans);
    }
}