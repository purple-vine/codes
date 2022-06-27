#include <cstdio>
#include <cstring>
using namespace std;
const int M = 55;
int dp[M][M][5][2], n, K, ans, t; char c[M][M];
char get(){
	char cc = getchar();
	while(cc != '.' && cc != 'H') cc = getchar();
	return cc;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &K);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				c[i][j] = get();
				if(c[i][j] == 'H') continue;
				if(i == 1 && j == 2)
					dp[i][j][0][1] = 1;
				if(i == 2 && j == 1)
					dp[i][j][0][0] = 1;
				//0:down 1:right
				for(int k = 0; k <= K; k++){
					dp[i][j][k][0] += dp[i - 1][j][k][0];
					dp[i][j][k][1] += dp[i][j - 1][k][1];
					dp[i][j][k + 1][0] += dp[i - 1][j][k][1];
					dp[i][j][k + 1][1] += dp[i][j - 1][k][0];
				}
			}
		}
		for(int i = 0; i < 2; i++)
			for(int j = 0; j <= K; j++) ans += dp[n][n][j][i];
		printf("%d\n", ans);
//		for(int i = 1; i <= n; i++)
//			for(int j = 1; j <= n; j++)
//				for(int k = 0; k <= K; k++)
//					for(int l = 0; l < 2; l++)
//						if(dp[i][j][k][l]) printf("i:%d j:%d k:%d l:%d val:%d\n", i, j, k, l, dp[i][j][k][l]);
		memset(dp, 0, sizeof(dp)); ans = 0;
	}
}
/*
1
3 3
...
.H.
...
*/
