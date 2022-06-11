//time : 2022-05-28 12:04
//problem id : CF623B
//status : AC
//from : https://www.luogu.com.cn/training/178674
#include <cstdio>
#include <iostream>
#include <vector>
#define int long long
#define inf (1e18+5)
#define LL long long
using namespace std;
const int M = 1000005;
LL dp[M][3], x, y, a[M], n;
LL calc(int t){
    // printf("in %d\n", t);
    for(int i = 1; i <= n; i++){
        if((a[i]+1) % t == 0 || (a[i]-1) % t == 0) 
            dp[i][0] = dp[i-1][0] + y;
        else if(a[i] % t == 0) dp[i][0] = dp[i-1][0];
        else dp[i][0] = inf;
        
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + x;

        if((a[i]+1) % t == 0 || (a[i]-1) % t == 0) 
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + y;
        else if(a[i] % t == 0) dp[i][2] = min(dp[i-1][2], dp[i-1][1]);
        else dp[i][2] = inf;
        // printf("%lld %lld %lld\n", dp[i][0], dp[i][1], dp[i][2]);
    }
    return min(dp[n][0], min(dp[n][1], dp[n][2]));
}
LL ans = inf;
void chk(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i != 0) continue;
        ans = min(ans, calc(i));
        while(n % i == 0) n /= i;
    }
    if(n > 1) ans = min(ans, calc(n));
}
signed main(){
    scanf("%lld %lld %lld", &n, &x, &y);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    chk(a[1]); chk(a[1]-1); chk(a[1]+1);
    chk(a[n]); chk(a[n]-1); chk(a[n]+1);
    printf("%lld\n", ans);
}