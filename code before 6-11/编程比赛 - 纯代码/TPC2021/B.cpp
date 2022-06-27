#include <cstdio>
#include <algorithm>
#include <cstring>
#define m(a) memset(a, 0, sizeof(a))
using namespace std;
const int M = 500005;
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
int n, m, t, fa[M], ans, m1, u, v, w, cnt1;
struct edge{
	int u, v, w;
	bool operator == (const edge &tmp) const{
		return u == tmp.u && v == tmp.v && w == tmp.w;
	}
}e[M * 2];
bool cmp(edge a, edge b){
	if(a.u != b.u) return a.u < b.u;
	else if(a.v != b.v) return a.v < b.v;
	return a.w < b.w;
}
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
	u = find(u); v = find(v);
	if(u != v) fa[v] = u; 
}
int main(){
	t = read();
	while(t--){
		n = read(); m = read();
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++){
			u = read(); v = read(); w = read();
			if(w == 0) ans++, merge(u, v);
			else e[++cnt1] = {u, v, w}, e[++cnt1] = {v, u, w};
		}
		for(int i = 1; i <= cnt1; i++){
			u = find(e[i].u); v = find(e[i].v); w = e[i].w;
			if(u != v)  e[++m1] = {u, v, w};
		}
		sort(e + 1, e + m1 + 1, cmp);
		for(int i = 1; i <= m1; i++){
			u = e[i].u; v = e[i].v;
			if(e[i] == e[i - 1]){
				merge(u, v);
				for(; e[i] == e[i - 1] && i <= n; i++) ans++;
				ans++;
			}
		}
		for(int i = 1; i <= m1; i++){
			u = e[i].u; v = e[i].v;
			if(find(u) != find(v)) merge(u, v), ans++;
		}
		printf("%d\n", ans);
		cnt1 = m1 = ans = 0;
	}
	return 0;
}
/*
1
4 4
1 2 0
1 3 1
2 3 1
1 4 1
*/
