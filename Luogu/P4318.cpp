//time : 22-6-21
//problem url : https://www.luogu.com.cn/problem/P4318
//status : not submitted
#include <cstdio>
#include <map>
#include <cmath>
#define int long long
#define LL long long
using namespace std;
const int M = 1000005;
int mu[M], p[M], tt; bool f[M];
void pre(int n){
	f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
	} 
}
int T, n, m = 1000000;
LL sum(LL n){
    LL sqr = sqrt(n), ans = 0;
    for(LL i = 1; i <= sqr; i++)
        ans += 1ll * mu[i] * (n / i / i);
    return ans;
}
LL calc(LL n){
    LL l = 1, r = 2*n, ans = 0;
    while(l <= r){
        LL mid = l + r >> 1;
        if(sum(mid) >= n) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}
signed main(){
    scanf("%lld", &T); pre(1000000);
    while(T--){
        scanf("%lld", &n);
        printf("%lld\n", calc(n));
    }
}