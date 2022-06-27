#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int M = 30005;
int dp[2][M], t1, t2, t3, n, m, ans = 300005; bool op;
int main(){
	scanf("%d", &n); m = 5 * n;
	memset(dp, 0x3f, sizeof(dp));
	dp[1][0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", &t1, &t2, &t3);
		memset(dp[op], 0x3f, sizeof(dp[op]));
		if(t1) for(int i = m; i >= t1; i--)
				dp[op][i] = min(dp[op][i], dp[op^1][i-t1]);
		if(t2) for(int i = m; i >= 0; i--)
				dp[op][i] = min(dp[op][i], dp[op^1][i] + t2);
		if(t3) for(int i = m; i >= t3; i--)
				dp[op][i] = min(dp[op][i], dp[op^1][i-t3] + t3);
//		for(int i = 0; i <= m; i++) if(dp[op][i] != 0x3f3f3f3f) printf("%d:%d ", i, dp[op][i]);
//		printf("\n");
		op ^= 1;
	} op ^= 1;
	for(int i = 0; i <= m; i++) ans = min(ans, max(i, dp[op][i]));
	printf("%d\n", ans);
}
