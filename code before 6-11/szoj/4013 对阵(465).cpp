#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int M = 1005, N = 20005;
int dp[N], n, m, s, a[M][M], anss, f[M][M];
int main(){
	scanf("%d %d %d", &s, &n, &m);
	for(int i = 1; i <= s; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[j][i]), a[j][i] = 2 * a[j][i] + 1;
	for(int i = 1; i <= n; i++) sort(a[i]+1, a[i]+s+1);
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 0; j--)
			for(int k = 1; k <= s; k++) if(j >= a[i][k])
				dp[j] = max(dp[j], dp[j - a[i][k]] + i * k);
//		for(int i = 0; i <= m; i++) printf("%d ", dp[i]);
//		printf("\n");
	}
	for(int i = 0; i <= m; i++) anss = max(anss, dp[i]);
	printf("%d\n", anss);
}
