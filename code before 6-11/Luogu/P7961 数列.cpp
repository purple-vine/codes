#include <cstdio>
#define p 998244353
using namespace std;
const int M = 125;
int dp[M][M][M][M], C[M][M], ans;
void pre(int n){
	for(int i = 0; i <= n; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % p;
	}
} 
int cal(int t){
	int ans = 0;
	for(; t; t >>= 1) ans += t&1;
	return ans;
}
int n, m, K, v[M][M];
int main(){
	scanf("%d %d %d", &n, &m, &K); pre(100);
	for(int i = 1; i <= m+1; i++){
		scanf("%d", &v[i][1]); v[i][0] = 1;
		for(int j = 1; j <= n; j++)
			v[i][j] = 1ll * v[i][j-1] * v[i][1] % p;
	}
	for(int i = 0; i <= n; i++) dp[1][i][i][0] = v[1][i];
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= j; k++){
				for(int l = 0; l <= j; l++){
					for(int t = 0; t <= n - j; t++){
//						printf("%d %d %d %d -> %d %d %d %d (%d): %d %d %d\n", i, j, k, l, i+1, j+t, t+k/2, l+k%2, t, C[j+t][t], v[i+1][t], dp[i][j][k][l]);
						dp[i+1][j+t][t+k/2][l+k%2] = (dp[i+1][j+t][t+k/2][l+k%2] + 1ll * C[j+t][t] * v[i+1][t] % p * dp[i][j][k][l] % p) % p;
					}
				}
			}
		}
	}
	for(int k = 0; k <= n; k++){
		for(int l = 0; l <= n; l++){
//			printf("%d %d %d %d\n", k, l, l+cal(k), dp[m+1][n][k][l]);
			if(l + cal(k) <= K) ans = (ans + dp[m+1][n][k][l]) % p;
		}
	}
	printf("%d\n", ans);
}
