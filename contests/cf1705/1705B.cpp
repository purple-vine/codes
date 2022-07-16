#include <cstdio>
#define LL long long
using namespace std;
const int M = 200005;
int t, n, a[M]; LL ans;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n); bool f = 1; ans = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            // printf("%d ", ans);
            if(i == n) continue;
            if(a[i] == 0) {if(!f) ans++;}
            else f = 0, ans += a[i];
        }
        printf("%lld\n", ans);
    }
}