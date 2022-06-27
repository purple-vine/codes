//按拓扑序：保证不走回以前走过的小组 
#include <cstdio>
#include <queue>
using namespace std;
const int M = 200005;
struct edge{
	int u, v, nxt;
}e[M];
int head[M], cnt1, deg[M];
void link(int u, int v){
	e[++cnt1].v = v; e[cnt1].u = u; deg[v]++;
	e[cnt1].nxt = head[u]; head[u] = cnt1;
}
int n, m, u, v, t[M], cnt; queue<int> q;
void tuopu(){
	for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop(); t[u] = cnt++;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].v; deg[v]--;
			if(deg[v] == 0) q.push(v);
		}
	}
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d %d", &u, &v), link(u, v);
	tuopu();
	for(int i = 1; i <= m; i++){
		u = t[e[i].u], v = t[e[i].v];
		if(u / 42 == v / 42) printf("R\n");
		else if(u / 42 / 42 == v / 42 / 42) printf("G\n");
		else printf("B\n");
	}
}
