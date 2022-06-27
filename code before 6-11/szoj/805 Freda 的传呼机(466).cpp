#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 10005;
struct edge{
	int to, nxt, w;
}e[M << 1];
int head[M], cnt1, deg[M], n, m, Q, u, v, w;
void link(int u, int v, int w){
	e[++cnt1].to = v; e[cnt1].w = w; deg[v]++;
	e[cnt1].nxt = head[u]; head[u] = cnt1;
}
int f[M][35], d[M]; long long dis[M]; bool circle[M];
struct LCA{
	int rt;
	void dfs(int u, int fa, int *bl){
		f[u][0] = fa; d[u] = d[fa] + 1; bl[u] = rt;
		for(int i = 1; i <= 30; i++) f[u][i] = f[f[u][i - 1]][i - 1];
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to; if(v == fa || circle[v]) continue;
			dis[v] = dis[u] + e[i].w; dfs(v, u, bl);
		}
	}
	int lca(int u, int v){
		if(d[u] < d[v]) swap(u, v);
		for(int i = 30; i >= 0; i--) if(d[f[u][i]] >= d[v]) u = f[u][i];
		if(u == v) return u;
		for(int i = 30; i >= 0; i--) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
		return f[u][0];
	}
}t;
namespace subtask1{
	int u, v, s[M]; LCA t;
	void main(){
		t.dfs(1, 0, s);
		while(Q--){
			scanf("%d %d", &u, &v);
			printf("%d\n", dis[u] + dis[v] - 2 * dis[t.lca(u, v)]);
		}
	}
}
namespace subtask2{
	//归属于谁的子树 环结点与s[0]距离 结点对应在哪个l[]中 
	int bl[M], g[M], L, t[M]; LCA l[M];
	vector<int> s; queue<int> q; bool vis[M];
	void find(){ //找环 
		for(int i = 1; i <= n; i++) if(deg[i] == 1) q.push(i);
		while(!q.empty()){
			int u = q.front(); q.pop(); vis[u] = 1;
			for(int i = head[u]; i; i = e[i].nxt){
				int v = e[i].to; deg[v]--;
				if(deg[v] == 1) q.push(v);
			}
		}
		for(int i = 1; i <= n; i++) if(!vis[i]) s.push_back(i), circle[i] = 1;
	}
	void dfs(int u, int fa){ //标记环 
//		printf("in : %d %d\n", u, fa);
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to; //printf("u = %d v = %d\n", u, v);
			if(v == fa || !circle[v]) continue;
			if(v == s[0]) {L = g[u] + e[i].w; return;}
			g[v] = g[u] + e[i].w;
			dfs(v, u); //return;
		} //printf("out: %d %d\n", u, fa);
	}
	int calc(int u, int v){
		int s1 = bl[u], s2 = bl[v];
		if(s1 == s2) return dis[u] + dis[v] - 2 * dis[l[t[s1]].lca(u, v)];
		return min(abs(g[bl[u]] - g[bl[v]]), L - abs(g[bl[u]] - g[bl[v]])) + dis[u] + dis[v];
	}
	void main(){
		find();
//		for(int i : s) printf("%d ", i);
//		printf("\n");
		for(int i = 0; i < s.size(); i++){
			l[i].rt = s[i]; t[s[i]] = i; l[i].dfs(s[i], 0, bl);
		}
		dfs(s[0], 0);
		while(Q--){
			scanf("%d %d", &u, &v);
			printf("%d\n", calc(u, v));
		}
	}
}
int main(){
	scanf("%d %d %d", &n, &m, &Q);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &u, &v, &w); 
		link(u, v, w); link(v, u, w);
	}
	if(m == n - 1) subtask1::main();
	else if(m == n) subtask2::main();
}
/*
5 5 10
1 2 1 
1 3 1 
2 4 1 
2 5 1 
1 4 1

*/
