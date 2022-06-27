#include <cstdio>
#include <queue>
#define inf 10000005
using namespace std;
const int M = 100005;
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
int n, m, l, r;
struct Splay{
	#define ls(x) ch[x][0]
	#define rs(x) ch[x][1]
	int sz[M], rt, tot, fa[M], ch[M][2]; bool laz[M];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + 1;}
	void pushdown(int x) {if(laz[x]) laz[ls(x)] ^= 1, laz[rs(x)] ^= 1, swap(ch[x][0], ch[x][1]), laz[x] = 0;}
	bool get(int x) {return x == rs(fa[x]);}
	void clear(int x) {ch[x][0] = ch[x][1] = fa[x]  = sz[x] = 0;}
	void rotate(int x){ 
		pushdown(fa[x]); pushdown(x);
		int y = fa[x], z = fa[y], chk = get(x);
		ch[y][chk] = ch[x][chk ^ 1]; if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y; 
		fa[y] = x; ch[x][chk ^ 1] = y; fa[x] = z; 
		if(z) ch[z][y == ch[z][1]] = x;
		pushup(x); pushup(y); 
	}
	void splay(int x, int goal){
		while(fa[x] != goal){
			int y = fa[x], z = fa[y];
			if(z != goal) rotate(get(x) == get(y) ? y : x);
			rotate(x);
		} if(!goal) rt = x;
	}
	int kth(int k){
		int x = rt;
		while(1){
			pushdown(x);
			if(k > sz[ls(x)] && k <= sz[ls(x)] + 1) return splay(x, 0), x;
			if(k <= sz[ls(x)]) x = ls(x);
			else k -= sz[ls(x)] + 1, x = rs(x);
		}
	}
	int build(int l, int r, int f){
		if(l > r) return -1; int mid = l + r >> 1;
		if(mid < f) ls(f) = mid; else rs(f) = mid;
		fa[mid] = f; sz[mid] = 1;
		build(l, mid - 1, mid); build(mid + 1, r, mid);
		pushup(mid); return mid;
	}
	void work(int l, int r){
		l = kth(l); r = kth(r + 2);
//		printf("%d %d\n", l, r);
		splay(l, 0); splay(r, rt);
		laz[ls(r)] ^= 1;
	}
	void dfs(int t){
		pushdown(t);
		if(ls(t)) dfs(ls(t));
		if(2 <= t && t <= n + 1) printf("%d ", t - 1);
		if(rs(t)) dfs(rs(t));
	}
}tr;
int main(){
	n = read(); m = read();
	tr.rt = tr.build(1, n + 2, 0);
	while(m--){
		l = read(); r = read();
		tr.work(l, r);
	} tr.dfs(tr.rt);
} 
