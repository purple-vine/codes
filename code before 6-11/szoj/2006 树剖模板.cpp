#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int M = 1000005;
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
void write(int x){
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0'); return;
}
struct edge{
	int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
	e[++cnt1].to = v; e[cnt1].nxt = head[u]; head[u] = cnt1;
}
int w[M], fa[M], dep[M], siz[M], son[M], top[M], dfn[M], rnk[M], out[M], cnt;
void dfs1(int u, int f){
	fa[u] = f; siz[u] = 1; son[u] = -1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == f) continue;
		dep[v] = dep[u] + 1; dfs1(v, u); siz[u] += siz[v]; 
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int f, int t){
	dfn[u] = ++cnt; rnk[cnt] = u; top[u] = t;
	if(son[u] != -1) dfs2(son[u], u, t);
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == f || v == son[u]) continue;
		dfs2(v, u, v);
	} out[u] = cnt;
}
int n, m, r, u, v, x, y, z, op;
struct sg{
	int s[M << 2], laz[M << 2];
	void pushdown(int o, int l, int r){
		int mid = l + r >> 1;
		s[o<<1] = (s[o<<1] + (mid-l+1) * laz[o]); laz[o<<1] = (laz[o<<1] + laz[o]);
		s[o<<1|1] = (s[o<<1|1] + (r-mid) * laz[o]); laz[o<<1|1] = (laz[o<<1|1] + laz[o]);
		laz[o] = 0;
	}
	void build(int o, int l, int r){
		if(l == r) {s[o] = w[rnk[l]]; return;}
		int mid = l + r >> 1;
		build(o<<1, l, mid); build(o<<1|1, mid+1, r);
		s[o] = (s[o<<1] + s[o<<1|1]);
	}
	void modify(int o, int l, int r, int x, int y, int t){
		if(x <= l && r <= y) {s[o] = (s[o] + (r-l+1) * t); laz[o] = (laz[o] + t); return;}
		int mid = l + r >> 1; pushdown(o, l, r);
		if(x <= mid) modify(o<<1, l, mid, x, y, t);
		if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
		s[o] = (s[o<<1] + s[o<<1|1]);
	}
	int query(int o, int l, int r, int x, int y){
		if(x <= l && r <= y) return s[o];
		int mid = l + r >> 1, ans = 0; pushdown(o, l, r);
		if(x <= mid) ans = (ans + query(o<<1, l, mid, x, y));
		if(y > mid) ans = (ans + query(o<<1|1, mid+1, r, x, y));
		return ans;
	}
}s;
void add1(int x, int y, int z){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] >= dep[ty]) s.modify(1, 1, n, dfn[tx], dfn[x], z), x = fa[tx];
		else s.modify(1, 1, n, dfn[ty], dfn[y], z), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	s.modify(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z); return;
}
signed main(){
	n = read(); m = read(); r = read();
	for(int i = 1; i <= n; i++) scanf("%lld", &w[i]);
	for(int i = 1; i < n; i++){
		u = read(); v = read(); link(u, v); link(v, u);
	}
	dfs1(r, 0); dfs2(r, 0, r); s.build(1, 1, n);
	while(m--){
		op = read();
		if(op == 1) x = read(), y = read(), z = read(), add1(x, y, z);
		else if(op == 2) x = read(), write(s.query(1, 1, n, dfn[x], dfn[x])), putchar('\n');
		else x = read(), write(s.query(1, 1, n, dfn[x], out[x])), putchar('\n');
	}
}
