#include <cstdio>
using namespace std;
const int N = 500005, M = 500005;
int fa[M], n, k, ans;
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
	u = find(u); v = find(v); if(u != v) fa[u] = v;
}
bool judge(int u, int v) {return find(u) == find(v);}
bool eat_relation(int x, int y){
	if(x == y) return 0;
	int xa = x, xb = x+n, xc = xb+n;
	int ya = y, yb = y+n, yc = yb+n;
	if(judge(xa, ya) || judge(xa, yc)) return 0;
	merge(xa, yb);  merge(xb, yc);  merge(xc, ya); return 1;
}
bool same_relation(int x, int y){
	if(x == y) return 1;
	int xa = x, xb = x+n, xc = xb+n;
	int ya = y, yb = y+n, yc = yb+n;
	if(judge(xa, yb) || judge(xa, yc)) return 0;
	merge(xa, ya); merge(xb, yb); merge(xc, yc); return 1;
}
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i <= 50000; i++) fa[i] = i;
	for(int i = 1; i <= k; i++){
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if(x > n || y > n) continue;
		if(op == 1) ans += eat_relation(x, y);
		else ans += same_relation(x, y);
//		printf("%d\n", ans);
	}
	printf("%d\n", k - ans);
}
