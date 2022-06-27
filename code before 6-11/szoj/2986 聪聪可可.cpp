#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
#define inf 1000000005
using namespace std;
const int M = 40005;
struct edge{
	int to, nxt, w;
}e[M << 1];
int head[M], cnt1, u, v, w, dp[M][3], ans, n;
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w = w;
	e[cnt1].nxt = head[u]; head[u] = cnt1;
}
void dfs(int u, int fa){
	dp[u][0] = 1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to, w = e[i].w % 3; if(v == fa) continue; dfs(v, u);
		ans += dp[v][(3-w)%3] * dp[u][0] + dp[u][1] * dp[v][(5-w)%3] + dp[u][2] * dp[v][(4-w)%3]; 
		for(int j = 0; j < 3; j++)
			dp[u][(j + w) % 3] += dp[v][j];
	}
}
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i < n; i++) scanf("%lld %lld %lld", &u, &v, &w), link(u, v, w), link(v, u, w);
	dfs(1, 0);
	u = 2 * ans + n; v = n * n; int g = gcd(u, v);
	printf("%lld/%lld\n", u/g, v/g);
}
