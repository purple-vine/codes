#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int M = 200005;
int a[M], s[M], n, p, q, r;
signed main(){
    scanf("%lld %lld %lld %lld", &n, &p, &q, &r);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), s[i] = s[i-1] + a[i];
    for(int i = 1; i <= n; i++){
        int pl1 = i, pl2 = 0, pl3 = 0, pl4 = 0;
        pl2 = lower_bound(s+1, s+n+1, s[pl1-1] + p) - s;
        if(s[pl2] != s[pl1-1] + p) continue;
        pl3 = lower_bound(s+1, s+n+1, s[pl2] + q) - s;
        if(s[pl3] != s[pl2] + q) continue;
        pl4 = lower_bound(s+1, s+n+1, s[pl3] + r) - s;
        if(s[pl4] != s[pl3] + r) continue;
        printf("Yes\n", pl1, pl2, pl3 , pl4);
        return 0;
    }
    printf("No\n");
}