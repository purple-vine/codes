#include <cstdio>
#include <algorithm>
#include <cstring>
#define m(a) memset(a, 0, sizeof(a));
using namespace std;
const int M = 200005;
struct edge{
	int to, nxt;
}e[M * 2];
int head[M], cnt1, c[M], fa[M], l[M], top;
void link(int u, int v){
	e[++cnt1].to = v;
	e[cnt1].nxt = head[u];
	head[u] = cnt1;
}
void dfs1(int u, int f){
	int s = 0; fa[u] = f;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == f) continue; dfs1(v, u); s++;
	}
	if(s == 0) l[++top] = u;
}
int cnt, t, n, a[M], b[M], u, v, s1[M * 10], s2[M * 10], cc;
bool up(int u, int cc){
	if(c[u]) return 1; c[u] = cc;
	if(s2[a[u]]) cnt--, s2[a[u]]--; else s1[a[u]]++, cnt++;
	if(s1[b[u]]) cnt--, s1[b[u]]--; else s2[b[u]]++, cnt++;
	if(cnt == 0) return 1;
	if(u != 1) up(fa[u], cc);
	else{
		if(u != 1) l[++top] = fa[u];
		return 0;
	}
}
void mem(){
	m(e); m(head); m(s1); m(s2); m(a); m(b); m(c); m(head); m(fa); m(l);
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i < n; i++) scanf("%d %d", &u, &v), link(u, v), link(v, u);
		dfs1(1, 0); bool f = 0;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= top; i++){
			if(!up(l[i], ++cc)) {printf("No\n"); f = 1; break;}
			memset(s1, 0, sizeof(s1)); memset(s2, 0, sizeof(s2));
		}
		if(!f) printf("Yes\n"); mem();
	}
	
}
