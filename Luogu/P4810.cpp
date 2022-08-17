#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 300005;
int f[M][20], fa[M], n, val[M], v, d[M]; char op;
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x, int y){
    if((x = find(x)) != (y = find(y))) fa[y] = x;
}
void op1(int pl, int v){
    pl = find(pl);
    f[v][0] = pl; val[v] = v; d[v] = d[pl] + 1;
    for(int i = 1; i <= 19; i++) f[v][i] = f[f[v][i-1]][i-1];
}
void op2(int pl, int v){
    pl = find(pl);
    printf("%d\n", val[pl]);
    merge(v, f[pl][0]);
}
int lca(int u, int v){
	if(d[u] < d[v]) swap(u, v);
	for(int i = 19; i >= 0; i--) if(d[f[u][i]] >= d[v]) u = f[u][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i--) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return u == v ? u : f[u][0];
}
void op3(int v, int w, int num){
    merge(num, v); v = find(v); w = find(w);
    printf("%d\n", d[lca(v, w)]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++){
        // printf("i=%d\n", i);
        scanf(" %c %d", &op, &v);
        if(op == 'a'){
            op1(v, i);
        } else if(op == 'b') {
            op2(v, i);
        } else {
            int w; scanf("%d", &w);
            op3(v, w, i);
        }
        for(int j = 1; j <= n; j++) printf("%d-%d-%d ", j, f[find(j)][0], val[find(j)]); printf("\n");
    }
}