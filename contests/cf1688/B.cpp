#include <cstdio>
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int M = 200005;
int T, n, a[M], t[35] = {1};
int calc(int x){
    int ans = 0;
    for(int i = 0; i <= 31; i++){
        if(x % t[i] == 0) ans = i;
    }
    return ans;
}
signed main(){
    scanf("%lld", &T); for(int i = 1; i <= 32; i++) t[i] = t[i-1] * 2;
    while(T--){
        scanf("%lld", &n); int cnt = 0, t = 35;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            if(a[i] % 2 == 0){
                ++cnt;
                t = min(t, calc(a[i]));
            }
        }
        if(cnt == 0) printf("0\n");
        else if(cnt == n) printf("%lld\n", t + cnt - 1); 
        else printf("%d\n", cnt);
        memset(a, 0, sizeof(a));
    }
}