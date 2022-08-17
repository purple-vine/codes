#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m;
namespace subtask2{
	const int M = 1000005;
	struct gragh{
		struct edge{
		    int to, nxt;
		}e[M << 2];
		int head[M], cnt1, deg[M];
		void link(int u, int v){
		    e[++cnt1] = {v, head[u]}; head[u] = cnt1; ++deg[v];
		}
	}g1, g2;
	int n, m, sl[M]; queue<int> q; vector<int> lim[M];
	bool vis[M];
	bool cmp(const int &x, const int &y){
	    return sl[x] < sl[y];
	}
	void untie(int u){
	    if(vis[u]) return; vis[u] = 1;
	    for(int v : lim[u]) untie(v);
	    printf("%d ", u); return;
	}
	int main(){
//		freopen("dictionary6.in", "r", stdin);
//		freopen("1.out", "w", stdout);
//	    scanf("%d %d", &n, &m);
	    for(int i = 1; i <= m; i++){
	        int u, v; scanf("%d %d", &u, &v); g1.link(u, v), g2.link(v, u);
	        lim[v].push_back(u);
	    }
	    for(int i = 1; i <= n; i++) if(g1.deg[i] == 0) q.push(i);
	    int cnt = 0;
	    while(!q.empty()){
	        int u = q.front(); q.pop(); ++cnt;
	        sort(lim[u].begin(), lim[u].end(), cmp);
	        sl[u] = u; if(lim[u].size()) sl[u] = min(sl[u], lim[u][0]);
	        for(int i = g1.head[u]; i; i = g1.e[i].nxt){
	            int v = g1.e[i].to; --g1.deg[v];
	            if(g1.deg[v] == 0) q.push(v);
	        }
	    }
	    if(cnt < n) {puts("-1"); return 0;}
	    for(int i = 1; i <= n; i++) untie(i);
	}
}
namespace subtask1{
    const int M = 1005;
    struct gragh{
		struct edge{
		    int to, nxt;
		}e[M << 2];
		int head[M], cnt1, deg[M];
		void link(int u, int v){
		    e[++cnt1] = {v, head[u]}; head[u] = cnt1; ++deg[v];
		}
	}g1;
	queue<int> q; vector<int> lim[M], sons[M];
	bool vis[M];
	void untie(int u){
//		printf("in %d\n", u);
	    if(vis[u]) return; vis[u] = 1;
	    for(int v : sons[u]) untie(v);
	    printf("%d ", u); return;
	}
	int main(){
		// freopen("dictionary6.in", "r", stdin);
		// freopen("1.out", "w", stdout);
//	    scanf("%d %d", &n, &m);
	    for(int i = 1; i <= m; i++){
	        int u, v; scanf("%d %d", &u, &v); g1.link(u, v);
	        lim[v].push_back(u);
	    }
	    for(int i = 1; i <= n; i++) if(g1.deg[i] == 0) q.push(i);
	    int cnt = 0;
	    while(!q.empty()){
	        int u = q.front(); q.pop(); ++cnt;
            for(int v : lim[u]) for(int vv : sons[v]) sons[u].push_back(vv);
            for(int v : lim[u]) sons[u].push_back(v);
	        sort(sons[u].begin(), sons[u].end());
	        // sl[u] = u; if(lim[u].size()) sl[u] = min(sl[u], lim[u][0]);
	        for(int i = g1.head[u]; i; i = g1.e[i].nxt){
	            int v = g1.e[i].to; --g1.deg[v];
	            if(g1.deg[v] == 0) q.push(v);
	        }
	    }
	    if(cnt < n) {puts("-1"); return 0;}
	    for(int i = 1; i <= n; i++) untie(i);
	}
}
int main(){
	scanf("%d %d", &n, &m);
	if(n > 1000) subtask2::main();
	else subtask1::main();
}