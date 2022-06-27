#include <cstdio>
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
const int M = 2505;
struct edge{
	int to, nxt, w;
}e[M << 1];
int head[M], cnt1, u, v, ww, n, k, dp[M][M];
int a[M], b[M], c[M], siz[M], w[M];
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w = w;
	e[cnt1].nxt = head[u]; head[u] = cnt1;
}
void dfs1(int u, int ww, int f){
	siz[u] = 1; w[u] = ww;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == f) continue;
		dfs1(v, e[i].w, u); siz[u] += siz[v];
	}
	a[u] = -2; b[u] = 2*k + 2*siz[u] - n;
	c[u] = siz[u]*n - k*siz[u] - siz[u]*siz[u];
}
int calc(int u, int k){
	return (a[u] * k * k + b[u] * k + c[u]) * w[u];
}
void dfs2(int u, int f){
	dp[u][0] = dp[u][1] = 0;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == f) continue; dfs2(v, u);
		for(int j = min(k, siz[u]); j >= 0; j--)
			for(int l = 0; l <= min(j, siz[v]); l++) if(dp[u][j-l] != -1 && dp[v][l] != -1){
//				if(u == 2) printf("dp[%d][%d] = dp[%d][%d](%d) + dp[%d][%d](%d)\n", u, j, u, j-l, dp[u][j-l], v, l, dp[v][l]);
				dp[u][j] = max(dp[u][j], dp[u][j - l] + dp[v][l]);
			}
	}
	for(int i = 0; i <= k; i++) if(dp[u][i] != -1) dp[u][i] += calc(u, i);
//	printf("%d: ", u);
//	for(int i = 0; i <= k; i++) printf("%d ", dp[u][i]);
//	printf("\n");
}
signed main(){
	scanf("%lld %lld", &n, &k);
	memset(dp, -1, sizeof(dp));
	for(int i = 1; i < n; i++){
		scanf("%lld %lld %lld", &u, &v, &ww);
		link(u, v, ww); link(v, u, ww);
	}
	dfs1(1, 0, 0); dfs2(1, 0);
	printf("%lld\n", dp[1][k]);
}
