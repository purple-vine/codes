#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define inf 1000000005
using namespace std;
const int M = 40005;
struct edge{
	int to, nxt, w;
}e[M << 1];
int head[M], cnt1; bool vis[M], ans[M], f[10005005];
int u, v, w, k, root;
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w = w; e[cnt1].nxt = head[u]; head[u] = cnt1;
}
int siz[M], minn, n, dis[M], s, m, q[M], ss, d[M];
void calsiz(int u, int fa){
	siz[u] = 1; int m = 0;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue; calsiz(v, u);
		siz[u] += siz[v]; m = max(m, siz[v]);
	} m = max(m, ss - siz[u]);
	if(m <= minn) minn = m, root = u;
}
int get(int u, int siz){
	minn = 1e9; root = -1; ss = siz;
	return calsiz(u, 0), root;
}
void dfs(int u, int fa){
	dis[++s] = d[u];
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue;
		d[v] = d[u] + e[i].w; dfs(v, u);
	}
}
queue<int> t;
void deal(int u){
	vis[u] = 1; f[0] = 1; t.push(0);
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		d[v] = e[i].w; s = 0; dfs(v, u);
		for(int j = 1; j <= s; j++){
			for(int k = 1; k <= m; k++)
				if(dis[j] <= q[k]) ans[k] |= (f[q[k] - dis[j]]);
		}
		for(int j = 1; j <= s; j++)
			if(dis[j] <= 10000500 && !f[dis[j]]) f[dis[j]] = 1, t.push(dis[j]);
	} 
	while(!t.empty()) f[t.front()] = 0, t.pop();
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		deal(get(v, siz[v]));
	}
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i++) scanf("%d %d %d", &u, &v, &w), link(u, v, w), link(v, u, w);
	for(int i = 1; i <= m; i++) scanf("%d", &q[i]);
	deal(get(1, n));
	for(int i = 1; i <= m; i++) printf("%s\n", ans[i] ? "Yes" : "No");
}
