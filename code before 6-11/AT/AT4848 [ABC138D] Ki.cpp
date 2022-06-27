#include <cstdio>
#define int long long
using namespace std;
const int M = 200005;
int a[M << 1], in[M], out[M], cnt, dif[M];
struct edge{
	int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
	e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
void dfs(int u, int fa){
	in[u] = ++cnt;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa) continue;
		dfs(v, u);
	}
	out[u] = cnt;
}
int n, q, u, v, t;
signed main(){
	scanf("%lld %lld", &n, &q);
	for(int i = 1; i < n; i++){
		scanf("%lld %lld", &u, &v);
		link(u, v); link(v, u);
	}
	dfs(1, 0);
	while(q--){
		scanf("%lld %lld", &u, &t);
		dif[in[u]] += t; dif[out[u]+1] -= t;
	}
	for(int i = 1; i <= n; i++){
		dif[i] += dif[i-1];
	}
	for(int i = 1; i <= n; i++)
		printf("%lld ", dif[in[i]]);
}
