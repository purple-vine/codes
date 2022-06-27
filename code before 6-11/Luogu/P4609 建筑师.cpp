#include <cstdio> 
#include <iostream>
using namespace std;
const int M = 50005, N = 205, mod = 1000000007;
int t, n, a, b, s[M][N], c[N][N];
void pre(int n = 50000, int m = 200){
	s[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			s[i][j] = (s[i-1][j-1] + 1ll * (i-1) * s[i-1][j] % mod) % mod;
	}
	c[0][0] = 1;
	for(int i = 0; i <= m; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
		}
	}
}
signed main(){
	pre();
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &n, &a, &b);
		printf("%lld\n", 1ll * s[n-1][a+b-2] * c[a+b-2][a-1] % mod);
	}
}
