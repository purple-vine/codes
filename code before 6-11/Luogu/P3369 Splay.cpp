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
void write(int x){
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
	return;
}
struct Splay{
	#define ls(x) ch[x][0]
	#define rs(x) ch[x][1]
	int sz[M], rt, tot, fa[M], ch[M][2], val[M], cnt[M];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + cnt[x];}
	bool get(int x) {return x == rs(fa[x]);}
	void clear(int x) {ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;}
	int build(int x) {sz[++tot] = 1; cnt[tot] = 1; val[tot] = x; return tot;}
	void rotate(int x){ 
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
	int rank(int k){
		int rk = 0, x = rt;
		while(1){
			if(x == 0) return -1;
			if(val[x] == k) {rk += sz[ls(x)] + 1; return splay(x, 0), rk;}
			if(k < val[x]) x = ls(x);
			else rk += cnt[x] + sz[ls(x)], x = rs(x);
		}
	}
	int kth(int k){
		int x = rt; if(sz[rt] < k) return -1;
		while(1){
			if(k > sz[ls(x)] && k <= sz[ls(x)] + cnt[x]) return splay(x, 0), val[x];
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
	int pre(){ //求根节点前驱并将其旋转至根 
		int x = ls(rt); if(!x) return x;
		while(rs(x)) x = rs(x);
		return splay(x, 0), x;
	}
	int nxt(){
		int x = rs(rt); if(!x) return x;
		while(ls(x)) x = ls(x);
		return splay(x, 0), x;	
	}
	void del(int k){
		rank(k);
		if(cnt[rt] > 1) {--cnt[rt]; pushup(rt); return;}
		if(!ls(rt) && !rs(rt)) {clear(rt); rt = 0; return;}
		if(!ls(rt)) {int r = rt; rt = rs(rt); fa[rt] = 0; clear(r); return;}
		if(!rs(rt)) {int r = rt; rt = ls(rt); fa[rt] = 0; clear(r); return;}
		int r = rt, x = pre(); fa[rs(r)] = x; rs(x) = rs(r); clear(r); pushup(rt);
	}
	int pre(int k) {insert(k); int ans = val[pre()]; del(k); return ans;}
	int nxt(int k) {insert(k); int ans = val[nxt()]; del(k); return ans;}
}tr;
int op, x, n;
int main(){
	n = read();
	while(n--){
//		tr.insert(-inf); tr.insert(inf);
		op = read(); x = read();
		if(op == 1) tr.insert(x);
		if(op == 2) tr.del(x);
		if(op == 3) write(tr.rank(x)), putchar('\n');
		if(op == 4) write(tr.kth(x)), putchar('\n');
		if(op == 5) write(tr.pre(x)), putchar('\n');
		if(op == 6) write(tr.nxt(x)), putchar('\n');
	}
} 
