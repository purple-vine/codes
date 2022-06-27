#include <cstdio>
#include <vector>
using namespace std;
const int M = 100005;
struct bcj{
	int n, fa[M], siz[M];
	void init(int n_){
		n = n_; for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int u, int v){
		u = find(u); v = find(v);
		if(u != v) fa[u] = v, siz[v] += siz[u];
	}
}s1, s2;
int n, x[M], y[M], m = 100000; vector<int> xy[M];
bool vis[M]; long long ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &x[i], &y[i]);
		xy[x[i]].push_back(y[i]);
	}
	s1.init(m); s2.init(m);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j < xy[i].size(); j++) s1.merge(xy[i][0], xy[i][j]);
	for(int i = 1; i <= n; i++){
		int yy = s1.find(y[i]);
		if(vis[x[i]]) continue; vis[x[i]] = 1;
//		if(visx[xx] || visy[yy]) continue;
		ans += 1ll * s1.siz[yy]; //visx[xx] = visy[yy] = 1;
	}
	printf("%lld\n", ans - n);
}
