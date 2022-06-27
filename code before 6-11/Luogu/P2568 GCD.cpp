#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 10000005;
int mu[M], p[M], tt, summu[M]; bool f[M];
void pre(int n){
	summu[1] = f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n || k < 0) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
		summu[i] = summu[i-1] + mu[i];
	} 
}
LL calc(int n, int m, int k){
	LL ans = 0;
	n /= k; m /= k; if(m > n) swap(n, m);
	for(int l = 1, r; l <= m; l = r+1){
		r = min(n/(n/l), m/(m/l));
		ans += 1ll * (summu[r] - summu[l-1]) * (n/l) * (m/l); 
	}
	return ans;
}
int n; long long ans;
int main(){
	scanf("%d", &n); pre(n);
//	for(int i = 1; i <= 100; i++) printf("%d ", mu[i]);
	for(int i = 1; i <= tt; i++) ans += 1ll * calc(n, n, p[i]);
	printf("%lld\n", ans);
}
