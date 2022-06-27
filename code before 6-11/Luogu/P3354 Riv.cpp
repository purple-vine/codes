#include <cstdio>
#include <iostream>
using namespace std;
const int M = 105;
//根 最近的伐木场编号 u与其子树共建伐木场数 f:不一定选 
int f[M][M][M], g[M][M][M], n, k, w[M], v, d;
struct edge{
	int to, nxt, w;
}e[M];
int head[M], cnt1, fa[M], s, dep[M];
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w =  w;
	e[cnt1].nxt = head[u]; head[u] = cnt1;
}
void dfs(int u, int d){
	fa[++s] = u; dep[u] = d;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; dfs(v, d + e[i].w);
		for(int t = 1; t <= s; t++){
			int ff = fa[t];
			for(int j = k; j >= 0; j--){
				f[u][ff][j] += f[v][ff][0];
				g[u][ff][j] += f[v][u][0];
				for(int x = 1; x <= j; x++){
					f[u][ff][j] = min(f[u][ff][j], f[u][ff][j - x] + f[v][ff][x]);
					g[u][ff][j] = min(g[u][ff][j], g[u][ff][j - x] + f[v][u][x]);
				}	
			}
		}
	}
	for(int i = 1; i <= s; i++){
		int ff = fa[i];
		f[u][ff][0] += w[u] * (dep[u] - dep[ff]);
		for(int j = 1; j <= k; j++){
			f[u][ff][j] = min(g[u][ff][j - 1], f[u][ff][j] + w[u] * (dep[u] - dep[ff]));
		}
	} s--;
}
int main(){
	scanf("%d %d", &n, &k);
//	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d", &w[i], &v, &d);
		link(v, i, d);
	}
	dfs(0, 0); printf("%d\n", f[0][0][k]);
}
