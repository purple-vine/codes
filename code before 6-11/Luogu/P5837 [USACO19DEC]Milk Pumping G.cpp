#include <cstdio>
#include <queue>
#include <cmath>
#define inf (1e9)
#define eps 1e-7
using namespace std;
const int M = 1005;
struct edge{
	int to, c, f, nxt;
}e[M];
int head[M], cnt1;
void link(int u, int v, int c, int f){
	e[++cnt1] = {v, c, f, head[u]};
	head[u] = cnt1;
}
int n, m, c, f, u, v; double ans = -1;
struct dat {int d, i; bool operator < (const dat &t) const {return d > t.d;}};
priority_queue<dat> q;
bool vis[M]; int dis[M];
int calc(int l){
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[1] = 0; q.push({0, 1});
	while(!q.empty()){
		int u = q.top().i; q.pop(); if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = e[i].nxt){
			if(e[i].f < l) continue;
			int v = e[i].to;
			if(dis[u] + e[i].c < dis[v])
				dis[v] = dis[u] + e[i].c, q.push({dis[v], v});
		}
	}
	return dis[n];
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d %d", &u, &v, &c, &f);
		link(u, v, c, f); link(v, u, c, f);
	}
	for(int i = 1; i <= 10; i++){
		int t = calc(i);
//		printf("%d %d\n", i, t);
//		int t = calc(i);
		ans = max(ans, 1.0 * i / t);
//		printf("%lf\n", 1.0 * i / t);
//		printf("%lf\n", ans);
	}
	printf("%d\n", floor(ans * 1000000));
}
