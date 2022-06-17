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
	int sz[M], rt, tot, fa[M], ch[M][2], val[M], cnt[M];
	void pushup(int x) {sz[x] = sz[ls(x)] + sz[rs(x)] + cnt[x];}
	bool get(int x) {return x == rs(fa[x]);}
	void clear(int x) {ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;}
	int build(int x) {sz[++tot] = 1; cnt[tot] = 1; val[tot] = x; return tot;}
	void rotate(int x){ 
		int y = fa[x], z = fa[y], chk = get(x);
        if (!isroot(y)) ch[z][ch[z][1] == y] = x; //特殊的 xz 连边
		ch[y][chk] = ch[x][chk ^ 1]; if(ch[x][chk ^ 1]) fa[ch[x][chk ^ 1]] = y; //处理x另一方向的儿子 
		fa[y] = x; ch[x][chk ^ 1] = y; fa[x] = z; //yx父子关系对调 
		pushup(x); pushup(y); 
	}
	void splay(int x){ //使 x 所在子树的根 
		while(!isroot(x)){
			int y = fa[x];
			if(!isroot(y)) rotate(get(x) == get(y) ? y : x);
			rotate(x);
		}
	}
	void access(int x){ //构建 x 到根的路径
        int y = x;
        for(int f = 0; x; x = f, f = fa[x]){
            splay(x); ch[x][1] = 0; pushup(x);
        }
        splay(y);
    }
}tr;
int op, x, n;
int main(){

} 