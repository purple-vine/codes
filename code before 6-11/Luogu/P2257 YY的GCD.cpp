#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 10000005;
int mu[M], p[M], tt, sum[M]; bool f[M];
void pre(int n){
	f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			LL k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
	} 
	for(int i = 1; i <= tt; i++)
		for(int j = 1; 1ll*p[i]*j <= n; j++)
			sum[p[i]*j] += mu[j];
	for(int i = 2; i <= n; i++) sum[i] += sum[i-1];
}
LL calc(int n, int m){
	LL ans = 0; if(m > n) swap(n, m);
	for(int l = 1, r; l <= m; l = r+1){
		r = min(n/(n/l), m/(m/l));
		ans += 1ll * (sum[r] - sum[l-1]) * (n/l) * (m/l); 
	}
	return ans;
}
int n, t, m; long long ans;
int main(){
	scanf("%d", &t); pre(10000000);
	while(t--){
		scanf("%d %d", &n, &m);
		printf("%lld\n", calc(n, m));
	}
}
