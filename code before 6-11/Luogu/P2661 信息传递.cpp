#include <cstdio>
#include <iostream>
using namespace std;
const int M = 200005;
struct edge{
	int to, nxt;
}e[M << 1];
int head[M], cnt1, ans = M << 2;
void link(int u, int v){
	e[++cnt1].to = v;
	e[cnt1].nxt = head[u];
	head[u] = cnt1;
}
int n, m, u, v, dfn[M], low[M], cnt, st[M], top, c[M], siz[M], cc; bool in[M];
void tarjan(int u){
	dfn[u] = low[u] = ++cnt; st[++top] = u; in[u] = 1;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to;
		if(!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if(in[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] != dfn[u]) return;
	++cc;
	do{
		c[st[top]] = cc; siz[cc]++; in[st[top]] = 0;
	} while(st[top--] != u);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {scanf("%d", &v); link(i, v);}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= cc; i++) if(siz[i] > 1) ans = min(ans, siz[i]);
	printf("%d\n", ans);
}
