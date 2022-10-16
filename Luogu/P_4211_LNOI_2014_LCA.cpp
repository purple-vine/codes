#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int M = 50005, p = 201314;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
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
    long long s[M << 2], laz[M << 2];
    void pushdown(int o, int l, int r){
    	int mid = l + r >> 1;
    	s[o<<1] += (mid-l+1) * laz[o]; laz[o<<1] += laz[o];
    	s[o<<1|1] += (r-mid) * laz[o]; laz[o<<1|1] += laz[o];
    	laz[o] = 0;
    }
    void build(int o, int l, int r){
    	if(l == r) {s[o] = w[rnk[l]]; return;}
    	int mid = l + r >> 1;
    	build(o<<1, l, mid); build(o<<1|1, mid+1, r);
    	s[o] = s[o<<1] + s[o<<1|1];
    }
    void modify(int o, int l, int r, int x, int y, int t){
    	if(x <= l && r <= y) {s[o] += (r-l+1) * t; laz[o] += t; return;}
    	int mid = l + r >> 1; pushdown(o, l, r);
    	if(x <= mid) modify(o<<1, l, mid, x, y, t);
    	if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
    	s[o] = s[o<<1] + s[o<<1|1];
    }
    long long query(int o, int l, int r, int x, int y){
    	if(x <= l && r <= y) return s[o];
    	int mid = l + r >> 1; long long ans = 0ll; pushdown(o, l, r);
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
void add(int x, int y, int z){
	int tx = top[x], ty = top[y];
	while(tx != ty){
		if(dep[tx] > dep[ty]) s.modify(1, 1, n, dfn[tx], dfn[x], z), x = fa[tx];
		else s.modify(1, 1, n, dfn[ty], dfn[y], z), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	s.modify(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z); return;
}
int query(int x, int y){
	int tx = top[x], ty = top[y], ans = 0;
	while(tx != ty){
		if(dep[tx] > dep[ty]) ans += s.query(1, 1, n, dfn[tx], dfn[x]), x = fa[tx];
		else ans += s.query(1, 1, n, dfn[ty], dfn[y]), y = fa[ty];
		tx = top[x]; ty = top[y];
	}
	ans += s.query(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]));
    return ans;
}
struct tp{
    int id, z, t;
};
vector<tp> q[M]; long long ans[M];
void solve(int u){
    add(1, u, 1);
    for(tp t : q[u]){
        ans[t.id] += query(1, t.z) * t.t;
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++) {
        int f; scanf("%d", &f); link(f+1, i);
    }
    dfs1(1, 0); dfs2(1, 0, 1);
    for(int i = 1; i <= m; i++){
        int l, r, z; scanf("%d %d %d", &l, &r, &z);
        ++l; ++r; ++z;
        q[l-1].push_back({i, z, -1}); q[r].push_back({i, z, 1});
    }
    for(int i = 1; i <= n; i++) solve(i);
    for(int i = 1; i <= m; i++) printf("%lld\n", ans[i] % p);
}