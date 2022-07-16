#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int M = 200005;
int q, n, a[M], t, ans1, ans2, k1[M], k2[M], p1[M], p2[M], cnt1, cnt2, ans, b[M];
signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        ans = ans1 = ans2 = cnt1 = cnt2 = 0;
        for(int i = 1; i <= n; i++){
            scanf("%1d", &a[i]);
            if(i > 1) ans1 += k1[i-1] = (a[i] ^ a[i-1]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%1d", &b[i]);
            if(i > 1) ans2 += k2[i-1] = (b[i] ^ b[i-1]);
        }
        if(ans1 != ans2 || a[1] != b[1] || a[n] != b[n]) {puts("-1"); continue;}
        // for(int i = 1; i < n; i++) printf("%d %d\n", k1[i], k2[i]);
        for(int i = 1; i < n; i++){
            if(k1[i]) p1[++cnt1] = i;
            if(k2[i]) p2[++cnt2] = i;
        }
        for(int i = 1; i <= ans1; i++) ans += abs(p1[i] - p2[i]);
        printf("%lld\n", ans);
    }
}