#include <cstdio>
#define int long long
using namespace std;
const int M = 100005;
int T, x, t[35] = {1ll};
int calc1(int x){
    int ans = 0;
    for(int i = 0; i <= 31; i++){
        if(t[i] <= x) ans = i;
    }
    return ans;
}
int calc2(int x){
    int ans = 0;
    for(int i = 0; i <= 31; i++){
        if(x % t[i] == 0) ans = i;
    }
    return ans;
}
signed main(){
    scanf("%lld", &T);
    for(int i = 1; i <= 32; i++) t[i] = t[i-1] * 2;
    while(T--){
        scanf("%lld", &x);
        if(x == 1) {printf("3\n"); continue;}
        int a = calc1(x), b = calc2(x);
        // printf("a=%lld b=%lld\n", a, b);
        if(a == b) printf("%lld\n", t[a] + 1);
        else printf("%lld\n", t[b]);
    }
}