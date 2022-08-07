#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
const int M = 200005;
LL a[M], fl[M][2], fr[M][2], L, R, n, ans1[M], ans2[M];
int main(){
    scanf("%lld %lld %lld", &n, &L, &R);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++){
        fl[i][0] = fl[i-1][0] + L;
        fl[i][1] = min(fl[i-1][1], fl[i-1][0]) + a[i];
        // printf("%lld-%lld ", fl[i][0], fl[i][1]);
        ans1[i] = min(fl[i][0], fl[i][1]);
    }
    for(int i = n; i >= 1; i--){
        fr[i][0] = fr[i+1][0] + R;
        fr[i][1] = min(fr[i+1][0], fr[i+1][1]) + a[i];
        // printf("%lld-%lld ", fr[i][0], fr[i][1]);
        ans2[i] = min(fr[i][0], fr[i][1]);
    }
    LL ans = 1e18;
    for(int i = 0; i <= n; i++){
        ans = min(ans, ans1[i] + ans2[i+1]);
    }
    printf("%lld\n", ans);
}