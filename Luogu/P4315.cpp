#include <cstdio>
#include <iostream>
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
	int to, nxt, w;
}e[M];
int head[M], cnt1;
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].nxt = head[u]; head[u] = cnt1; e[cnt1].w = w;
}
int w[M], fa[M], dep[M], siz[M], son[M], top[M], dfn[M], rnk[M], out[M], cnt, ww;
void dfs1(int u, int f){
	fa[u] = f; siz[u] = 1; son[u] = -1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == f) continue; w[v] = e[cnt1].w;
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
int n, m, r, u, v, x, y, z;
struct sg{
	int s[M << 2], laz1[M << 2], laz2[M << 1];
	void pushdown(int o, int l, int r){
		int mid = l + r >> 1;
        if(laz1[o] != 0){
            s[o<<1] += laz1[o]; laz1[o<<1] += laz1[o];
            s[o<<1|1] += laz1[o]; laz1[o<<1|1] += laz1[o];
            laz1[o] = 0;
        }
        if(laz2[o] != 0){
            s[o<<1] = laz2[o]; laz1[o<<1] = 0;
            s[o<<1|1] = laz2[o]; laz1[o<<1|1] = 0;
            laz2[o] = 0;
        }
	}
	void build(int o, int l, int r){
		if(l == r) {s[o] = w[rnk[l]]; return;}
		int mid = l + r >> 1;
		build(o<<1, l, mid); build(o<<1|1, mid+1, r);
		s[o] = max(s[o<<1], s[o<<1|1]);
	}
	void modify1(int o, int l, int r, int x, int y, int t){
        pushdown(o, l, r);
		if(x <= l && r <= y) {s[o] += t; laz1[o] += t; return;}
		int mid = l + r >> 1;
		if(x <= mid) modify1(o<<1, l, mid, x, y, t);
		if(y > mid) modify1(o<<1|1, mid+1, r, x, y, t);
		s[o] = max(s[o<<1], s[o<<1|1]);
	}
    void modify2(int o, int l, int r, int x, int y, int t){
        pushdown(o, l, r);
		if(x <= l && r <= y) {s[o] = t; laz1[o] = 0; laz2[o] = t; return;}
		int mid = l + r >> 1;
		if(x <= mid) modify2(o<<1, l, mid, x, y, t);
		if(y > mid) modify2(o<<1|1, mid+1, r, x, y, t);
		s[o] = max(s[o<<1], s[o<<1|1]);
	}
	int query(int o, int l, int r, int x, int y){
        pushdown(o, l, r);
		if(x <= l && r <= y) return s[o];
		int mid = l + r >> 1, ans = 0;
		if(x <= mid) ans += query(o<<1, l, mid, x, y);
		if(y > mid) ans += query(o<<1|1, mid+1, r, x, y);
		return ans;
	}
	void debug(int o, int l, int r){
		printf("%d: l = %d  r = %d  s = %d\n", o, l, r, s[o]);
		if(l == r) return;
		int mid = l + r >> 1;
		debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
	}
}s;
void add1(int x, int y, int z){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] > dep[ty]) s.modify1(1, 1, n, dfn[tx], dfn[x], z), x = fa[tx];
		else s.modify1(1, 1, n, dfn[ty], dfn[y], z), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	s.modify1(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z); return;
}
void add2(int x, int y, int z){
    int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] > dep[ty]) s.modify2(1, 1, n, dfn[tx], dfn[x], z), x = fa[tx];
		else s.modify2(1, 1, n, dfn[ty], dfn[y], z), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	s.modify2(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z); return;
}
int query1(int x, int y){
	int tx = top[x], ty = top[y], ans = 0;
	while(tx != ty){
		if(dep[tx] > dep[ty]) ans += s.query(1, 1, n, dfn[tx], dfn[x]), x = fa[tx];
		else ans += s.query(1, 1, n, dfn[ty], dfn[y]), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	ans += s.query(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y])); return ans;
}
char op[10];
signed main(){
	n = read();
	for(int i = 1; i < n; i++){
		u = read(); v = read(); ww = read(); link(u, v, ww); link(v, u, ww);
	}
	dfs1(r, r); dfs2(r, r, r); s.build(1, 1, n);
	while(m--){
		scanf(" %s", op);
		if(op[0] == 'A') x = read(), y = read(), z = read(), add1(x, y, z);
		else if(op[0] == 'C' && op[1] == 'O') x = read(), y = read(), z = read(), add2(x, y, z);
		else if(op[0] == 'C' && op[1] == 'h') x = read(), z = read(), s.modify1(1, 1, n, , z);
		else x = read(), write(s.query(1, 1, n, dfn[x], out[x])), putchar('\n');
	}
}