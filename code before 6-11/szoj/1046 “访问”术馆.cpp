#include <cstdio>
#include <iostream>
using namespace std;
const int M = 1005;
int w[M], t[M], dp[M][4005], cnt1, n, s, ww, tt, ans, c[M][2];
void build(int u){
//	printf("%d\n", u);
	scanf("%d %d", &tt, &ww); w[u] = ww; t[u] = tt * 2;
	if(!w[u]) build(c[u][0] = ++cnt1), build(c[u][1] = ++cnt1);
}
void dfs(int u){
	if(w[u]) {for(int i = 1; i <= w[u]; i++) dp[u][5*i] = i; return;}
	for(int i = 0, cc; i < 2; i++){
		dfs(cc = c[u][i]);
		for(int j = s; j >= 0; j--)
			for(int k = j; k >= 0; k--)
				dp[u][j + t[cc]] = max(dp[u][j], dp[u][j - k] + dp[cc][k]);
	}
	
}
int main(){
	scanf("%d", &s);
	build(1); dfs(1);
	for(int j = 0; j < s-t[1]; j++) ans = max(ans, dp[1][j]);
	printf("%d", ans);
	return 0;
}
