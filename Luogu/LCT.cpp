//time : 2022-06-18
//problem id : P
//status : not submitted
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
struct LCT{
	#define ls(x) ch[x][0]
	#define rs(x) ch[x][1]
    #define isroot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)
	int sz[M], rt, tot, fa[M], ch[M][2], val[M], cnt[M], laz[M];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + cnt[x];}
	void pushdown(int x) {if(!laz[x]) return; laz[ls(x)] ^= 1; laz[rs(x)] ^= 1; swap(ch[x][0], ch[x][1]); laz[x] = 0;}
	bool get(int x) {return x == rs(fa[x]);}
	void clear(int x) {ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;}
	int build(int x) {sz[++tot] = 1; cnt[tot] = 1; val[tot] = x; return tot;}
	void rotate(int x){ 
		pushdown(fa[x]); pushdown(x);
		int y = fa[x], z = fa[y], chk = get(x);
        if (!isroot(y)) ch[z][ch[z][1] == y] = x; //特殊的 xz 连边
		ch[y][chk] = ch[x][chk ^ 1]; if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y; //处理x另一方向的儿子 
		fa[y] = x; ch[x][chk ^ 1] = y; fa[x] = z; //yx父子关系对调 
		pushup(x); pushup(y); 
	}
	void update(int x){
		if(!isroot(x)) update(fa[x]);
		pushdown(x);
	}
	void splay(int x){ //使 x 所在子树的根 
		update(x);
		while(!isroot(x)){
			int y = fa[x];
			if(!isroot(y)) rotate(get(x) == get(y) ? y : x);
			rotate(x);
		}
	}
	void access(int x){ //构建 x 到根的路径
        int f = x;
        for(int y = 0; x; y = x, x = fa[x]){
            splay(x); rs(x) = y; pushup(x);
        }
        splay(f);
    }
	void makeroot(int x){
		access(x); splay(x); 
		laz[x] ^= 1; swap(ls(x), rs(x)); 
	}
	int findroot(int x){
		access(x); splay(x);
		int y = x;
		while(ls(y)) pushdown(y), y = ls(y);
		return splay(y), y; //保证 splay 复杂度
	}
	void split(int x, int y){
		makeroot(x); access(y); splay(y);
	}
	bool link(int x, int y){ //造出的 splay 以 y 为根
		makeroot(x); if(findroot(y) == x) return 0;
		fa[x] = y; return 1;
	}
	bool cut(int x, int y){
		split(x, y);
		if(findroot(y) != x || ls(y) != x) return 0;
		ls(y) = 0; pushup(y); splay(y); return 1;
	}
}tr;
int op, x, n, m, y;
int main(){
	scanf("%d %d", &n, &m);
} 