#include <cstdio>
using namespace std;
const int M = 305, N = 90005, mod = 998244353;
int f[M][N], n, a[M], S, t[M], ans, ans1;
int add(int a, int b) {return (a += b) > mod ? a-mod : a;}
int qpow(int a, int b, int p){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
signed main(){
	scanf("%lld", &n);
	t[0] = 1;
	for(int i = 1; i <= n; i++) t[i] = add(t[i-1], t[i-1]);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), S += a[i];
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = i; j >= 0; j--){
			for(int k = 0; k <= S; k++){
				f[j+1][k+a[i]] = add(f[j+1][k+a[i]], f[j][k]);
			}
		}
	}
	int minn = (S >> 1) + (S & 1);
//	printf("%d\n", minn);
	for(int i = 0; i <= n; i++){
		for(int j = minn; j <= S; j++){
//			if(f[i][j]) printf("f[%d][%d] * 2^%d = %d\n", i, j, n-i, f[i][j]*t[n-i]);
			ans = add(ans, 1ll * f[i][j] * t[n-i] % mod);
		}
		if(S % 2 == 0) ans1 = add(ans1, f[i][S >> 1]);
	}
	ans -= ans1;
//	printf("ansnow:%d\n", ans);
//	int k = 0;
//	for(int i = 0; i <= n; i++){
//		for(int j = 0; j <= sum[n]; j++){
//			if(f[i][j]) printf("f[%d][%d] = %d\n", i, j, f[i][j]);
//			k += f[i][j];
//		}
//	}
	printf("%lld\n", (qpow(3, n, mod) - 1ll * ans * 3 % mod + mod) % mod);
}
/*
6
1
3
2
3
5
2
*/
