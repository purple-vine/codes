#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
const int M = 100005;
int mu[M], p[M], tt, summu[M]; LL s[M]; bool f[M];
void pre(int n){
	summu[1] = f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
		summu[i] = summu[i-1] + mu[i];
	} 
    for(int i = 1; i <= n; i++){
        for(int l = 1, r; l <= i; l = r+1){
            r = i/(i/l); s[i] += 1ll *(r-l+1) * (i/l);
        }
    }
}
LL solve(int n, int m){
    if(n > m) swap(n, m); LL ans = 0;
    for(int l = 1, r; l <= n; l = r+1){
        r = min(m/(m/l), n/(n/l));
        ans += (summu[r] - summu[l-1]) * s[n/l] * s[m/l];
    }
    return ans;
}
int T, n, m;
int main(){
    scanf("%d", &T); pre(50000);
    while(T--){
        scanf("%d %d", &n, &m);
        printf("%lld\n", solve(n, m));
    }
}