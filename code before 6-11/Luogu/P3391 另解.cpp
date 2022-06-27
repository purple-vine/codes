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
	int sz[M], rt, tot, fa[M], ch[M][2], val[M], cnt[M]; bool laz[M];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + cnt[x];}
	void pushdown(int x) {if(!laz[x]) return; laz[ls(x)] ^= 1; laz[rs(x)] ^= 1; swap(ch[x][0], ch[x][1]); laz[x] = 0;}
	bool get(int x) {return x == rs(fa[x]);}
	void clear(int x) {ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;}
	int build(int x) {sz[++tot] = 1; cnt[tot] = 1; val[tot] = x; return tot;}
	void rotate(int x){ 
		pushdown(fa[x]); pushdown(x);
		int y = fa[x], z = fa[y], chk = get(x);
		ch[y][chk] = ch[x][chk ^ 1]; if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y; //处理x另一方向的儿子 
		fa[y] = x; ch[x][chk ^ 1] = y; fa[x] = z; //yx父子关系对调 
		if(z) ch[z][y == ch[z][1]] = x; //xz连边 
		pushup(x); pushup(y); 
	}
	void splay(int x, int goal){ //使x为goal儿子 
		while(fa[x] != goal){
			int y = fa[x], z = fa[y];
			if(z != goal) rotate(get(x) == get(y) ? y : x);
			rotate(x);
		} if(!goal) rt = x;
	}
	int kth(int k){
		int x = rt; if(sz[rt] < k) return -1;
		while(1){
			pushdown(x);
			if(k > sz[ls(x)] && k <= sz[ls(x)] + cnt[x]) return splay(x, 0), x;
			if(k <= sz[ls(x)]) x = ls(x);
			else k -= sz[ls(x)] + cnt[x], x = rs(x);
		}
	}
	void insert(int k){
		if(!rt) {rt = build(k); return;} 
		int x = rt, y = 0;
		while(1){
			if(val[x] == k) {++cnt[x]; pushup(x); pushup(y); splay(x, 0); return;}
			y = x; x = ch[x][val[x] < k];
			if(!x){
				x = build(k); fa[x] = y; ch[y][val[y] < k] = x;
				pushup(x); pushup(y); splay(x, 0); break;
			}
		}
	}
	void work(int l, int r){
		l = kth(l); r = kth(r + 2);
		splay(l, 0); splay(r, rt);
		laz[ls(r)] ^= 1;
	}
	void dfs(int t){
		pushdown(t);
		if(ls(t)) dfs(ls(t));
		if(1 <= val[t] && val[t] <= n) printf("%d ", val[t]);
		if(rs(t)) dfs(rs(t));
	}
}tr;
int main(){
	n = read(); m = read();
	for(int i = 0; i <= n + 1; i++) tr.insert(i);
	while(m--){
		l = read(); r = read();
		tr.work(l, r);
	} tr.dfs(tr.rt);
} 
