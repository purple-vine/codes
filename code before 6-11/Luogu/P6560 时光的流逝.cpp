#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int M = 100005;
vector<int> e[M], e1[M]; 
int n, m, t, cnt, u, v, deg[M];
queue<int> q; int ans[M];
void solve(int u){
	q.push(u); memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++){
		deg[i] = e[i].size();
		if(deg[i] == 0) ans[i] = -1, q.push(i);
	}
	if(ans[u] != -1) ans[u] = -1, q.push(u);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : e1[u]){
			if(ans[v] != 0) continue;
			deg[v]--;
			if(ans[u] == -1) ans[v] = 1, q.push(v);
			else if(deg[v] == 0) ans[v] = -1, q.push(v);
		}
	}
}
int main(){
	scanf("%d %d %d", &n, &m, &t);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &u, &v);
		e[u].push_back(v), e1[v].push_back(u);
	}
	while(t--){
		scanf("%d %d", &u, &v);
		solve(v); printf("%d\n", ans[u]);
//		for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
//		printf("\n");
	}
} 
