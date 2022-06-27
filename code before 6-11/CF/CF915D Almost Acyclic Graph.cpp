#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int M = 505;
struct edge{
	int to, nxt;
}e[M * M];
int head[M], cnt1, n, u, v, deg[M], m, d[M];
void link(int u, int v){
	e[++cnt1].to = v; e[cnt1].nxt = head[u];
	head[u] = cnt1; deg[v]++;
}
queue<int> q; int cnt; bool ans;
bool check(){
	cnt = 0;
	for(int i = 1; i <= n; i++) if(d[i] == 0) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop(); cnt++;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to; d[v]--;
			if(d[v] == 0) q.push(v);
		}
	} return cnt == n;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d %d", &u, &v), link(u, v);
	for(int i = 1; i <= n; i++){
		memcpy(d, deg, sizeof(deg)); d[i]--; ans |= check();
	} printf("%s\n", ans ? "YES" : "NO");
}
