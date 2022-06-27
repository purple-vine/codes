#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
int fa[M], siz[M], w[M], n, m, q, x, y, ans, dep[M];
int find(int u) {
	if(fa[u] == u) {dep[u] = 0; return u;}
	int t = find(fa[u]); dep[u] = dep[fa[u]] + 1; return t;
}
void merge(int u, int v, int ww){
	u = find(u); v = find(v); if(u == v) return;
	if(siz[u] > siz[v]) swap(u, v);
	fa[u] = v; siz[v] += siz[u]; w[u] = ww;
}
int main(){
	n = read(); m = read(); q = read();
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1; //以此纪念 并查集不初始化siz 
	for(int i = 1; i <= m; i++){
		int t = m - i + 1;
		for(int j = 1; (j + 1) * t <= n; j++){
			merge(j * t, (j + 1) * t, i);
		}
	}
	while(q--){
		x = read(); y = read();
		find(x); find(y);
		if(dep[x] < dep[y]) swap(x, y);
		while(dep[x] > dep[y]) {ans = max(ans, w[x]); x = fa[x];}
		while(x != y){
			ans = max(ans, max(w[x], w[y]));
			x = fa[x]; y = fa[y];
		} printf("%d\n", ans); ans = 0;
	}
}
