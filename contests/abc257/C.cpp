#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int M = 200005;
int n, a[M], b[M], s1[M], s2[M], cnt1, cnt2; long long ans = 0; bool s[M];
int main(){
    scanf("%d", &n); getchar();
    for(int i = 1; i <= n; i++) s[i] = getchar() == '1';
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(s[i] == 0) s1[++cnt1] = a[i];
        else s2[++cnt2] = a[i];
    }
    a[++n] = 1000000001;
    sort(s+1, s+n+1); sort(s1+1, s1+cnt1+1); sort(s2+1, s2+cnt2+1);
    for(int i = 1; i <= n; i++){
        ans = max(ans, (long long)(lower_bound(s1+1, s1+cnt1+1, a[i])-s1-1 + s2+cnt2+1 - lower_bound(s2+1, s2+cnt2+1, a[i]))); // a[i-1] < w < a[i]
        ans = max(ans, (long long)(lower_bound(s1+1, s1+cnt1+1, a[i])-s1-1 + s2+cnt2+1 - lower_bound(s2+1, s2+cnt2+1, a[i]))); // w = a[i]
        // printf("ans=%d %d %d\n", ans, lower_bound(s1+1, s1+cnt1+1, a[i])-s1-1 + s2+cnt2+1 - lower_bound(s2+1, s2+cnt2+1, a[i]), lower_bound(s1+1, s1+cnt1+1, a[i]) - s1 - 1 + s2+cnt2+1 - lower_bound(s2+1, s2+cnt2+1, a[i]));
    }
    printf("%lld\n", ans);
}