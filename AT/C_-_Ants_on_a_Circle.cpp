// agc013C
#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
const int M = 1e5 + 5;
LL n, l, t, ans[M], cnt; 
int main() {
    scanf("%lld %lld %lld", &n, &l, &t);
    for(int i = 0; i < n; i++) {
        LL x, s; scanf("%lld %lld", &x, &s);
        if(s == 1) {
            cnt += (x + t) / l; cnt = (cnt % n + n) % n;
        } else {
            cnt -= ceil(1.0 * (t-x) / l); cnt = (cnt % n + n) % n;
        }
        ans[i] = ((x + (s == 1 ? t : -t)) % l + l) % l;
    }
    sort(ans, ans+n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", ans[(i + cnt) % n]);
    }
}