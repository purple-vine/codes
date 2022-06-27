#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define m(a) memset(a, 0, sizeof(a))
#define inf 2050000005
using namespace std;
const int M = 1000005, N = 500005;
int low[N], dfn[N], cnt, st[N], top, cnts;
int dis1[N], disn[N], p[N], s[N], cntp, ans; bool in[M], f[M]; //p:ÍØÆËÐò s:¸üÐÂÐò 
int u, v, w, m, k, P, n, dp[N][55];
void clear(){
	m(low); m(dfn); m(st); m(dis1); m(disn); m(in); m(s); m(p); m(dp);
	ans = cnts = cntp = top = cnt = u = v = w = k = P = n = 0;
}
struct gragh{
	struct edge {int to, nxt, w;} e[M];
	int head[N], cnt1, deg[N];
	void link(int u, int v, int w){
		e[++cnt1].w = w; e[cnt1].to = v;
		e[cnt1].nxt = head[u]; head[u] = cnt1; deg[v]++;
	}
	struct node {int dis, i; bool operator < (const node &tmp) const{return dis > tmp.dis;};} d[N];
	priority_queue<node> q; bool vis[N];
	void dij(int t, int dis[]){
		for(int i = 1; i <= n; i++) d[i].dis = inf, d[i].i = i;
		d[t].dis = 0; q.push(d[t]); dp[t][0] = 1;
		while(!q.empty()){
			int u = q.top().i; q.pop(); if(vis[u]) continue;
			for(int i = head[u]; i; i = e[i].nxt){
				int v = e[i].to;
				if(d[v].dis > d[u].dis + e[i].w) d[v].dis = d[u].dis + e[i].w, q.push(d[v]);
			} vis[u] = 1;
		} for(int i = 1; i <= n; i++) dis[i] = d[i].dis;
	}
	void tarjan(int u){
		dfn[u] = low[u] = ++cnt; st[++top] = u; in[u] = 1;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to;
			if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
			else if(in[v]) low[u] = min(low[u], dfn[v]);
		}
		if(dfn[u] == low[u]){
			++cnts; int siz = 0;
			do {
				in[st[top]] = 0; siz++; f[st[top]] = 1;
			} while(st[top--] != u);
			if(siz == 1) f[u] = 0;
		}
	}
	queue<int> qq;
	void tuopu(){
		for(int i = 1; i <= n; i++) if(deg[i] == 0) qq.push(i);
		while(!qq.empty()){
			int u = qq.front(); qq.pop(); p[u] = ++cntp;
			for(int i = head[u]; i; i = e[i].nxt){
				int v = e[i].to; deg[v]--;
				if(deg[v] == 0) qq.push(v);
			}
		}
	}
	bool judge(){
		for(int i = 1; i <= n; i++){
			if(f[i] && dis1[i] + disn[i] <= dis1[n] + k) return 0;
		}
		return 1;
	}
	void clear(){
		m(e); m(head); m(vis); m(deg); cnt1 = 0;
		while(q.size()) q.pop(); while(qq.size()) qq.pop();
	}
}g1, g2, g3;
bool cmp(int a, int b){
	if(dis1[a] != dis1[b]) return dis1[a] < dis1[b];
	return p[a] < p[b];
}
void work(){
	scanf("%d %d %d %d", &n, &m, &k, &P);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &u, &v, &w);
		if(w == 0) g3.link(u, v, w);
		g1.link(u, v, w); g2.link(v, u, w);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) g3.tarjan(i);
	g2.dij(n, disn); for(int i = 1; i <= n; i++) dp[i][0] = 0; g1.dij(1, dis1);
	if(!g3.judge()) {printf("-1\n"); return;}
	g3.tuopu(); for(int i = 1; i <= n; i++) s[i] = i;
	sort(s + 1, s + n + 1, cmp);
	for(int i = 0; i <= k; i++){
		for(int j = 1; j <= n; j++){
			int u = s[j];
			for(int kk = g1.head[u]; kk; kk = g1.e[kk].nxt){
				int v = g1.e[kk].to, t = dis1[u] + i - dis1[v] + g1.e[kk].w;
				if(t <= k) dp[v][t] = (dp[v][t] + dp[u][i]) % P;
			}
		}
	}
	for(int i = 0; i <= k; i++) ans = (ans + dp[n][i]) % P;
	printf("%d\n", ans);
	clear(); g1.clear(); g2.clear(); g3.clear();
}
int t;
int main(){
	scanf("%d", &t);
	while(t--) work();
} 
