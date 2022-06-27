#include <cstdio>
#include <iostream>
#include <algorithm>
#define inf 1000000005
using namespace std;
const int M = 40005;
struct edge{
	int to, nxt, w;
}e[M << 1];
int head[M], cnt1; bool vis[M];
int u, v, w, k, root;
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w = w; e[cnt1].nxt = head[u]; head[u] = cnt1;
}
int siz[M], minn, n, dis[M], s, ans;
void getroot(int u, int fa){
	siz[u] = 1; int m = 0;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue; getroot(v, u);
		siz[u] += siz[v]; m = max(m, siz[v]);
	} m = max(m, n - siz[u]);
	if(m <= minn) minn = m, root = u;
}
int get(int u){
	minn = 1e9; root = -1; getroot(u, 0); //printf("root of %d:%d\n", u, root);
	return getroot(u, 0), root;
}
void dfs(int u, int fa, int dep){
	dis[++s] = dep;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue;
		dfs(v, u, dep + e[i].w);
	}
}
int calc(int u, int k){
	if(k < 0) return 0;
	s = 0; dfs(u, 0, 0); sort(dis + 1, dis + s + 1);
	int l = 1, r = s, ans = 0;
	while(l <= r){
		if(dis[l] + dis[r] <= k) ans += r - l, l++;
		else r--;
	} return /*printf("calc(%d, %d) : %d\n", u, k, ans),*/ ans;
}
void deal(int u){
//	printf("deal %d\n", u);
	getroot(u, 0); ans += calc(u, k); vis[u] = 1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		ans -= calc(v, k - 2 * e[i].w);
		deal(get(v));
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++) scanf("%d %d %d", &u, &v, &w), link(u, v, w), link(v, u, w);
	scanf("%d", &k);
	deal(get(1)); printf("%d\n", ans);
}
