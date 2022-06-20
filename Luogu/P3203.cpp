//time : 2022-06-19
//problem url : https://www.luogu.com.cn/problem/P3203
//status : AC
#include <cstdio>
#include <queue>
#define inf 10000005
using namespace std;
const int M = 200005;
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
int op, x, n, m, y, a[M], k[M];
struct LCT{
	#define ls(x) ch[x][0]
	#define rs(x) ch[x][1]
    #define isroot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)
	int sz[M], rt, tot, fa[M], ch[M][2];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + 1;}
	bool get(int x) {return x == rs(fa[x]);}
	void rotate(int x){ 
		int y = fa[x], z = fa[y], chk = get(x);
        if (!isroot(y)) ch[z][ch[z][1] == y] = x; //特殊的 xz 连边
		ch[y][chk] = ch[x][chk ^ 1]; if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y; //处理x另一方向的儿子 
		fa[y] = x; ch[x][chk ^ 1] = y; fa[x] = z; //yx父子关系对调 
		pushup(y); pushup(x); 
	}
	void splay(int x){//使 x 所在子树的根 
		while(!isroot(x)){
			int y = fa[x];
			if(!isroot(y)) rotate(get(x) == get(y) ? y : x);
			rotate(x);
		}
	}
	void access(int x){//构建 x 到根的路径
        int f = x;
        for(int y = 0; x; y = x, x = fa[x]){
            splay(x); rs(x) = y; pushup(x);
        }
        splay(f);
    }
	void modify(int x, int y){
		access(x); splay(x); fa[ch[x][0]] = 0; ch[x][0] = 0; 
		if(x + y <= n) fa[x] = x+y; pushup(x);
	}
	int query(int x){
		access(x); splay(x); return sz[x];
	}
}T;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]); 
		if(i + k[i] <= n) T.fa[i] = i + k[i];
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &op, &x); ++x;
		if(op == 1) printf("%d\n", T.query(x));
		else scanf("%d", &y), T.modify(x, y);
	}
} 