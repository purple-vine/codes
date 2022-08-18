#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 50;
LL n, k; int q; LL sum1[M], sum2[M], sum[M], step[M], num[M];
int getdep(LL x){
//	int tot = 1, sum = k;
    for(int i = 1; i <= 30; i++) {
		if(sum[i-1] >= x) return i;
//		tot += sum; sum *= k;
	}
    return 0;
}
int dep(LL x){
//	int tot = k-1;
	for(int i = 1; i <= 30; i++){
		if(sum2[i] >= x) return i;
//		tot *= k;
	} return 0;
}
LL solve(LL x, LL y){
    if(k == 1) return max(x, y) - min(x, y);
    int depx = getdep(x), depy = getdep(y), ans = 0;
//    printf("depx = %d  depy = %d\n", depx, depy);
    if(x != 1) x += (k-2) * sum[depx - 2];
    if(y != 1) y += (k-2) * sum[depy - 2];
    while(x != y){
    	if(x < y) swap(x, y);
    	x /= k; ++ans;
	}
//    printf("x=%lld  y=%lld\n", x, y);
//    if(depx < depy) swap(x, y);
//    LL ansx = 0ll, ansy = 0ll;
//    while(dep(x) > dep(y)) x /= k, ansx++;
//	if(dep(x) != dep(y)) x /= k, ++ansx;
//    printf("x=%lld y=%lld\n", x, y);
//    while(x != y) x /= k, y /= k, ansy++;
//    if(x != y) ++ansy;
    // int d = x == y ? x : x/k;
//    printf("ansx=%lld ansy=%lld\n", ansx, ansy);
//    return 2*ansy + ansx;
	return ans;
}
int main(){
    scanf("%lld %lld %d", &n, &k, &q);
    sum[0] = num[0] = 1ll; step[0] = k; //step[1] = k-1;
    for(int i = 1; i <= 30; i++)
        num[i] = num[i-1] * 2, step[i] = step[i-1] * k, sum[i] = sum[i-1] + step[i-1];
    sum2[1] = k-1;
    for(int i = 1; i <= 30; i++)
    	sum2[i] = sum2[i-1] * k;
//    for(int i = 1; i <= 30; i++) printf("%lld ", sum[i]); printf("\n");
    while(q--){
        LL x, y;
        scanf("%lld %lld", &x, &y);
        printf("%lld\n", solve(x, y));
    }
}