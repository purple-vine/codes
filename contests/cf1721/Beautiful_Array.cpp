#include <cstdio>
#define LL long long
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        LL n, k, b; LL s;
        scanf("%lld %lld %lld %lld", &n, &k, &b, &s);
        if(k * b + n * (k-1) < s || s < k * b) {printf("-1\n"); continue;}
        LL res = s - k * b, tot = 0;
        for(int i = 1; i < n; i++){
            if(res > k-1) printf("%lld ", k-1), res -= k-1, tot += k-1;
            else printf("%lld ", res), tot += res, res = 0;
        }
        printf("%lld\n", s - tot);
    }
}