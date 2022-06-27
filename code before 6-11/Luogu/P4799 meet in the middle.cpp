#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 45;
long long a[M], b[M], t[M], m, k1, k2, ans; int n, k;
void dfs1(int x, long long s){
	if(s > m) return;
	if(x == k + 1) {a[++k1] = s; return;}
	dfs1(x + 1, s + t[x]); dfs1(x + 1, s);
}
void dfs2(int x, long long s){
	if(s > m) return;
	if(x == n + 1) {b[++k2] = s; return;}
	dfs2(x + 1, s + t[x]); dfs2(x + 1, s);
}
int main(){
	scanf("%d %lld", &n, &m); k = n >> 1;
	for(int i = 1; i <= n; i++) scanf("%lld", &t[i]);
	dfs1(1, 0); dfs2(k+1, 0);
	sort(b+1, b+k2+1);
	for(int i = 1; i <= k1; i++){
		ans += upper_bound(b+1, b+k2+1, m-a[i]) - b - 1;
	} 
	printf("%lld\n", ans);
}
