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
int siz[M], minn, n, a[M], s, ans, b[M], d[M], cnt[M];
void getroot(int u, int fa){
	siz[u] = 1; int m = 0;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue; getroot(v, u);
		siz[u] += siz[v]; m = max(m, siz[v]);
	} m = max(m, n - siz[u]);
	if(m <= minn) minn = m, root = u;
}
void dfs(int u, int fa){
	a[++s] = u; b[u] = b[fa]; cnt[b[u]]++;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa || vis[v]) continue;
		d[v] = d[u] + e[i].w; dfs(v, u);
	}
}
int get(int u){
	getroot(u, 0); ss = siz[u];
	minn = 1e9; root = -1; //printf("root of %d:%d\n", u, root);
	return getroot(u, 0), root;
}
bool cmp(int a, int b){
	return d[a] < d[b];
}
int calc(int u){
	a[s = 1] = b[u] = u; d[u] = 0;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		b[u] = v; d[v] = e[i].w; dfs(v, u);
	} b[u] = u;
	sort(a + 1, a + s + 1, cmp);
	int l = 1, r = s, ans = 0;
	while(l <= r){
		if(d[a[l]] + d[a[r]] <= k) ans += r-l-cnt[b[a[l]]], cnt[b[a[++l]]]--;
		else cnt[b[a[r--]]]--;
	} return cnt[b[a[l]]]++, /*printf("calc(%d) : %d\n", u, ans),*/ ans;
}
void deal(int u){
//	printf("deal %d\n", u);
	getroot(u, 0); ans += calc(u); vis[u] = 1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(vis[v]) continue;
		deal(get(v));
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++) scanf("%d %d %d", &u, &v, &w), link(u, v, w), link(v, u, w);
	scanf("%d", &k);
	deal(get(1)); printf("%d\n", ans);
}
