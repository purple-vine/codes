#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
const int M = 100005, N = 1005;
int n, x, y, a[M]; bool f[N]; int p[N], cnt; LL ans = 1e18;
void pre(int n){
    for(int i = 2; i <= n; i++){
        if(!f[i]){
            p[++cnt] = i;
            for(int j = i; j <= n; j += i) f[j] = 1;
        }
    }
}
int dp[M][3];
LL check(int t){
    for(int i = 1; i <= n; i++){
        //
    }
}
int main(){
    scanf("%d %d %d", &n, &x, &y); pre(1000);
    for(int i = 1; i <= cnt; i++){
        ans =  min(ans, check(p[i]));
    }
}