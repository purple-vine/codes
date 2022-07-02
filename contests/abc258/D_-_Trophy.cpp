#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
const int M = 200005;
LL a[M], b[M], minn = 1e9, sum, ans = 2e18; int n, x;
int main(){
    scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a[i], &b[i]);
        sum += a[i] + b[i]; minn = min(minn, b[i]);
        if(i <= x) ans = min(ans, sum + (x-i) * minn);
    }
    printf("%lld\n", ans);
}