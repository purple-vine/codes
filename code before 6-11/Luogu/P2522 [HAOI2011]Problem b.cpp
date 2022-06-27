#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
int mu[M], p[M], tt, summu[M]; bool f[M];
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
}
int calc(int n, int m, int k){
	int ans = 0;
	n /= k; m /= k; if(m > n) swap(n, m);
	for(int l = 1, r; l <= m; l = r+1){
		r = min(n/(n/l), m/(m/l));
		ans += (summu[r] - summu[l-1]) * (n/l) * (m/l); 
	}
//	printf("calc(%d %d %d) = %d\n", n, m, k, ans);
	return ans;
}
int solve(int a, int b, int c, int d, int k){
	return calc(b, d, k) - calc(b, c-1, k) - calc(a-1, d, k) + calc(a-1, c-1, k);
}
int n;
int main(){
	scanf("%d", &n); pre(50000);
	while(n--){
		int a, b, c, d, k;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		printf("%d\n", solve(a, b, c, d, k));
	}
}
