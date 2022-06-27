#include <cstdio>
#define int long long
#define p 1000000007
using namespace std;
const int M = 100005;
int dp[1005][M], a[M], n, t;
signed main(){
	scanf("%lld %lld", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] %= t;
	dp[1][a[1] % t]++; dp[1][0]++;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < t; j++){
			dp[i+1][(j+a[i+1])%t] = (dp[i+1][(j+a[i+1])%t] + dp[i][j]) % p;
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % p;
		}
	}
	printf("%lld\n", dp[n][0] - 1);
}
