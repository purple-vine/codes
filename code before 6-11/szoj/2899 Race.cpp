#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
#define inf 1000000005
using namespace std;
const int M = 200005;
struct edge{
	int to, nxt, w;
}e[M << 1];
struct tp{
	int d, l;
}dis[M];
int head[M], cnt1, f[1000505]; bool vis[M];
int u, v, w, k, root;
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w = w; e[cnt1].nxt = head[u]; head[u] = cnt1;
}
int siz[M], minn, n, s, m, q, ss, d[M], ans;
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
void dfs(int u, int fa, int dep){
	dis[++s] = {dep, d[u]};
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue;
		d[v] = d[u] + e[i].w; dfs(v, u, dep + 1);
	}
}
queue<int> t;
void deal(int u){
	vis[u] = 1; f[0] = 0;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		d[v] = e[i].w; s = 0; dfs(v, u, 1);
		for(int j = 1; j <= s; j++)
			if(dis[j].l <= q) ans = min(f[q - dis[j].l] + dis[j].d, ans);
		for(int j = 1; j <= s; j++)
			if(dis[j].l <= 1000005 && dis[j].d <= f[dis[j].l]) f[dis[j].l] = dis[j].d, t.push(dis[j].l);
	} calsiz(u, 0);
	while(!t.empty()) f[t.front()] = inf, t.pop();
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		deal(get(v, siz[v]));
	}
}
signed main(){
	scanf("%lld %lld", &n, &q);
	for(int i = 1; i < n; i++) scanf("%lld %lld %lld", &u, &v, &w), u++, v++, link(u, v, w), link(v, u, w);
	for(int i = 1; i < 1000505; i++) f[i] = inf;
	ans = inf + 1; deal(get(1, n));
	printf("%lld\n", ans == inf + 1 ? -1 : ans);
}
