#include <cstdio>
#include <queue>
#define LL long long
using namespace std;
const int M = 5000005, N = 100005;
const long long inf = 100000000000005;
struct edge{
    int to, nxt, w;
}e[M << 1];
int head[N], cnt1;
void link(int u, int v, int w){
    e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
}
#define rs (o<<1|1)
#define ls (o<<1)
int n, m1, m2, in[M], out[M]; // m : 两棵树偏移量
// 往上指，[l,r] 连 x，表示出边
void build1(int o, int l, int r){
    if(l == r) {out[l] = o+m1; return;}
    int mid = l + r >> 1;
    link(ls+m1, o+m1, 0); link(rs+m1, o+m1, 0);
    build1(ls, l, mid); build1(rs, mid+1, r);
}
// [x, y] 连 t
void link1(int o, int l, int r, int x, int y, int t, int w){
    if(x <= l && r <= y) {link(o+m1, t, w); return;}
    int mid = l + r >> 1;
    if(x <= mid) link1(o<<1, l, mid, x, y, t, w);
    if(y > mid) link1(o<<1|1, mid+1, r, x, y, t, w);
}
// 往下指，x 连 [l, r]，表示入边
void build2(int o, int l, int r){
    if(l == r) {in[l] = o+m2; link(in[l], out[l], 0); return;}
    int mid = l + r >> 1;
    link(o+m2, ls+m2, 0); link(o+m2, rs+m2, 0);
    build2(ls, l, mid); build2(rs, mid+1, r);
}
// t 连 [l, r]
void link2(int o, int l, int r, int x, int y, int t, int w){
    if(x <= l && r <= y) {link(t, o+m2, w); return;}
    int mid = l + r >> 1;
    if(x <= mid) link2(o<<1, l, mid, x, y, t, w);
    if(y > mid) link2(o<<1|1, mid+1, r, x, y, t, w);
}
#undef ls
#undef rs
int Q, s;
struct node{
    long long dis; int i;
    bool operator < (const node &tmp) const {
        return dis > tmp.dis;
    }
} d[M];
bool vis[M]; priority_queue<node> q;
void dij(int t){
	for(int i = 1; i <= 15 * n; i++) d[i].dis = inf, d[i].i = i;
	d[t].dis = 0ll; q.push(d[t]);
	while(!q.empty()){
		int u = q.top().i; q.pop();
		if(vis[u]) continue; vis[u] = 1;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to;
			if(d[v].dis > d[u].dis + e[i].w){
				d[v].dis = d[u].dis + e[i].w;
				q.push(d[v]);
			}
		}
	}
}
int main(){
    scanf("%d %d %d", &n, &Q, &s);
    m1 = 1.5 * n; m2 = 6 * n;
    build1(1, 1, n); build2(1, 1, n);
    while(Q--){
        int op; scanf("%d", &op);
        if(op == 1){
            int u, v, w; scanf("%d %d %d", &u, &v, &w);
            link(out[u], in[v], w);
        } else {
            int x, l, r, w; scanf("%d %d %d %d", &x, &l, &r, &w);
            if(op == 2) link2(1, 1, n, l, r, out[x], w);
            else link1(1, 1, n, l, r, in[x], w);
        }
    }
    dij(in[s]);
    for(int i = 1; i <= n; i++) printf("%lld ", d[in[i]].dis == inf ? -1ll : d[in[i]].dis);
}