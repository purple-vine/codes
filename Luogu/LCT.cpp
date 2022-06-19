//time : 2022-06-18
//problem url : https://www.luogu.com.cn/problem/P3690
//status : WA
#include <cstdio>
#include <queue>
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define dprintf printf
#define debug() printf("fa:"); for(int i = 1; i <= n; i++) printf("%d ", T.fa[i]); printf("\n");\
printf("sons:"); for(int i = 1; i <= n; i++) printf("%d-%d ", T.ls(i), T.rs(i)); printf("\n");\
printf("vals:"); for(int i = 1; i <= n; i++) printf("%d-%d ", T.val[i], T.s[i]); printf("\n");
#define debug1() printf("fa:"); for(int i = 1; i <= n; i++) printf("%d ", fa[i]); printf("\n");\
printf("sons:"); for(int i = 1; i <= n; i++) printf("%d-%d ", ls(i), rs(i)); printf("\n");\
printf("vals:"); for(int i = 1; i <= n; i++) printf("%d-%d-%d ", val[i], s[i], laz[i]); printf("\n");
#else
#define debug() 
#define debug1()
#define dprintf
#endif
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
int op, x, n, m, y, a[M];
struct LCT{
	#define ls(x) ch[x][0]
	#define rs(x) ch[x][1]
    #define isroot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)
	int sz[M], rt, tot, fa[M], ch[M][2], val[M], cnt[M], laz[M], s[M];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + cnt[x]; s[x] = (s[ls(x)] ^ s[rs(x)] ^ val[x]);}
	void put(int x) {laz[x] ^= 1; swap(ls(x), rs(x));}
	void pushdown(int x) {if(!laz[x]) return; put(ls(x)); put(rs(x)); laz[x] = 0;}
	bool get(int x) {return x == rs(fa[x]);}
	void clear(int x) {ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;}
	int build(int x) {sz[++tot] = 1; cnt[tot] = 1; s[tot] = val[tot] = x; return tot;}
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
	void splay(int x){//使 x 所在子树的根 
		update(x);
		while(!isroot(x)){
			int y = fa[x];
			if(!isroot(y)) rotate(get(x) == get(y) ? y : x);
			rotate(x);
		}
	}
	void access(int x){//构建 x 到根的路径
        int f = x;
        for(int y = 0; x; y = x, x = fa[x]){
			// dprintf("y=%d x=%d\n", y, x);
            splay(x); rs(x) = y; pushup(x);
			debug1()
        }
        splay(f);
    }
	void makeroot(int x){//让 x 成为原树的根
		access(x); dprintf("makeroot access x=%d\n", x); debug1()
		splay(x); dprintf("makeroot splay x=%d\n", x); debug1()
		put(x);
	}
	int findroot(int x){
		access(x); splay(x);
		int y = x;
		while(ls(y)) pushdown(y), y = ls(y);
		return splay(y), y; //保证 splay 复杂度
	}
	void split(int x, int y){
		makeroot(x); dprintf("makeroot x=%d:\n", x); debug1()
		access(y); dprintf("access y=%d:\n", y); debug1()
		splay(y); dprintf("splay y=%d:\n", y); debug1()
	}
	bool link(int x, int y){//造出的 splay 以 y 为根
		makeroot(x); if(findroot(y) == x) return 0;
		fa[x] = y; return 1;
	}
	bool cut(int x, int y){
		makeroot(x);
		if(findroot(y) != x || fa[y] != x || ls(y)) return 0;
		rs(x) = fa[y] = 0; pushup(x); splay(x); return 1;
	}
	void modify(int x, int y){
		splay(x); val[x] = y; pushup(x);
	}
}T;
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) T.build(read());
	while(m--){
		scanf("%d %d %d", &op, &x, &y);
		if(op == 0) T.split(x, y), printf("%d\n", T.s[y]);
		else if(op == 1) T.link(x, y);
		else if(op == 2) T.cut(x, y);
		else T.modify(x, y);
		debug()
	}
} 