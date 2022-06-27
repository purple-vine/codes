#include <cstdio>
#include <queue>
#define inf (10000000005)
using namespace std; 
const int M = 1005, N = 10005;
int n, m, cnt[M], k; long long dis[M], d[M];
struct graph{
	struct edge{
		int to, nxt; long long w;
	}e[N << 1];
	int head[M], cnt1;
	void link(int u, int v, long long w){
		e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
	}
}g1, g2; 
struct pai{int x; long long y; bool operator < (pai t) const {return y > t.y;}};
struct pir{int x; long long y; bool operator < (pai t) const {return y + dis[y] > t.y + dis[t.y];}};
bool vis[M]; priority_queue<pai> q;
void dij(int s){
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[s] = 0ll; q.push({s, 0ll});
	while(!q.empty()){
		int u = q.top().x; q.pop();
		for(int i = g2.head[u]; i; i = g2.e[i].nxt){
			int v = g2.e[i].to;
			if(dis[v] > dis[u] + g2.e[i].w){
				dis[v] = dis[u] + g2.e[i].w;
				q.push({v, dis[v]});
			}
		} vis[u] = 1;
	}
}
void A_star(int x = n){
	q.push({x, 0});
	while(!q.empty()){
		int u = q.top().x; long long y = q.top().y; q.pop(); cnt[u]++;
		if(u == 1 && cnt[1] <= k) printf("%lld\n", y);
		for(int i = g1.head[u]; i; i = g1.e[i].nxt){
			int v = g1.e[i].to;
			if(cnt[v] < k) q.push({v, y+g1.e[i].w});
		}
	}
}
int u, v, w;
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &u, &v, &w);
		g1.link(u, v, w); g2.link(v, u, w);
	}
	dij(1); A_star(n);
	for(int i = cnt[1] + 1; i <= k; i++) printf("-1\n");
}
