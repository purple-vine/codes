#include <cstdio>
#include <iostream>
using namespace std;
const int M = 1000005;
int n, c, q, a[M], s, t;
int main(){
    scanf("%d %d %d", &n, &c, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while(q--){
        scanf("%d", &s);
        long long cnt = 0ll; int minn = 1e9, maxx = -1;
        for(int i = 1; i <= s; i++){
            scanf("%d", &t);
            minn  = min(minn, a[t]); maxx = max(maxx, a[t]);
            cnt += a[t];
        }
        printf("%lld\n", (-maxx + 2ll*minn - cnt + 1ll*(s-1)*c));
    }
    return 0;
}