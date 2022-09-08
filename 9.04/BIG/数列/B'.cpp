#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int M = 2005;
struct edge{
    int to, nxt, id;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v, int k){
    e[++cnt1] = {v, head[u], k}; head[u] = cnt1;
}
int fa[M], dep[M], id1[M];
void dfs1(int u, int f){
    fa[u] = f; dep[u] = dep[f] + 1;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dfs1(v, u); id1[v] = e[i].id;
    }
}
int n, m, u1[M], v1[M], cnt, d1[M];
namespace g1{ // 反图
    const int M = 2000005;
    struct edge{
        int to, nxt;
    }e[M << 1];
    int head[M], cnt2, deg[M];
    void link(int u, int v){
        e[++cnt2] = {v, head[u]}; head[u] = cnt2;
        ++deg[v];
    }
    int ans[M], cnt;
    priority_queue<int> q;
    void solve(){
        for(int i = 1; i <= m; i++)
            if(!deg[i]) q.push(i);
        while(!q.empty()){
            int u = q.top(); q.pop();
            ans[u] = m + 1 - ++cnt;
            for(int i = head[u]; i; i = e[i].nxt){
                int v = e[i].to; --deg[v];
                if(deg[v] == 0) q.push(v);
            }
        }
    }
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
int n, m, r, u, v, x, y, z, op; long long p;
struct sg{
	int s[M << 2], laz[M << 2];
	void pushdown(int o, int l, int r){
		int mid = l + r >> 1;
		s[o<<1] = (s[o<<1] + (mid-l+1) * laz[o] % p) % p; laz[o<<1] = (laz[o<<1] + laz[o]) % p;
		s[o<<1|1] = (s[o<<1|1] + (r-mid) * laz[o] % p) % p; laz[o<<1|1] = (laz[o<<1|1] + laz[o]) % p;
		laz[o] = 0;
	}
	void build(int o, int l, int r){
		if(l == r) {s[o] = w[rnk[l]]; return;}
		int mid = l + r >> 1;
		build(o<<1, l, mid); build(o<<1|1, mid+1, r);
		s[o] = (s[o<<1] + s[o<<1|1]) % p;
	}
	void modify(int o, int l, int r, int x, int y, int t){
		if(x <= l && r <= y) {s[o] = (s[o] + (r-l+1) * t % p) % p; laz[o] = (laz[o] + t) % p; return;}
		int mid = l + r >> 1; pushdown(o, l, r);
		if(x <= mid) modify(o<<1, l, mid, x, y, t);
		if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
		s[o] = (s[o<<1] + s[o<<1|1]) % p;
	}
	int query(int o, int l, int r, int x, int y){
		if(x <= l && r <= y) return s[o];
		int mid = l + r >> 1, ans = 0; pushdown(o, l, r);
		if(x <= mid) ans = (ans + query(o<<1, l, mid, x, y)) % p;
		if(y > mid) ans = (ans + query(o<<1|1, mid+1, r, x, y)) % p;
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
		if(dep[tx] > dep[ty]) s.modify(1, 1, n, dfn[tx], dfn[x], z), x = fa[tx];
		else s.modify(1, 1, n, dfn[ty], dfn[y], z), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	s.modify(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z); return;
}
int query1(int x, int y){
	int tx = top[x], ty = top[y], ans = 0;
	while(tx != ty){
		if(dep[tx] > dep[ty]) ans = (ans + s.query(1, 1, n, dfn[tx], dfn[x])) % p, x = fa[tx];
		else ans = (ans + s.query(1, 1, n, dfn[ty], dfn[y])) % p, y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	ans = (ans + s.query(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]))) % p; return ans;
}
int main(){
    freopen("ex_A2.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        if(t == 1) link(u, v, i), link(v, u, i);
        else u1[++cnt] = u, v1[cnt] = v, d1[cnt] = i;
    }
    dfs1(1, 0);
    for(int i = 1; i <= cnt1; i++){
        int u = u1[i], v = v1[i], id = d1[i];
        if(dep[u] > dep[v]) swap(u, v);
        while(dep[v] > dep[u]) g1::link(id, id1[v]), v = fa[v];
        while(u != v) {
            // printf("u=%d v=%d\n", u, v);
            g1::link(id, id1[u]); g1::link(id, id1[v]);
            // printf("%d %d\n", id, id1[u]); printf("%d %d\n", id, id1[v]);
            u = fa[u]; v = fa[v];
        }
    }
    g1::solve();
    for(int i = 1; i <= m; i++) printf("%d ", g1::ans[i]);
}
/*
9 13
3 6 0
3 2 1
1 2 1
8 3 1
7 9 0
5 6 0
6 7 1
4 6 1
4 7 0
2 5 1
2 4 1
3 9 1
5 4 0
*/