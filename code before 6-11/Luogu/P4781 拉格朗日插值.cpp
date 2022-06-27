#include <cstdio>
#include <cmath>
#include <iostream>
#define int long long
#define p 998244353
using namespace std;
const int M = 5005;
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int inv(int k) {return qpow(k, p - 2);}
int x[M], y[M], n, kx, ky, ans, k;
signed main(){
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%lld %lld", &x[i], &y[i]);
	for(int i = 1; i <= n; i++){
		int s1 = y[i], s2 = 1;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			s1 = 1ll * s1 * (k - x[j]) % p;
			s2 = 1ll * s2 * (x[i] - x[j]) % p;
		}
		ans = ( ans + 1ll * s1 * inv(s2) % p + p) % p;
	}
	printf("%lld\n", ans);
}
