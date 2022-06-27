#include <cstdio>
#include <vector>
#define p 998244353
using namespace std;
const int M = 200005;
struct edge{
	int to, nxt;
}e[M * 2];
int head[M], cnt1, u, v, ans = 1, cnt[M], n;
void link(int u, int v){
	e[++cnt1].to = v;
	e[cnt1].nxt = head[u];
	head[u] = cnt1;
}
int u1, d1, u2, d2, u3, v3;
void dfs1(int u, int fa, int dep){
	if(dep > d1) d1 = dep, u1 = u;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa) continue;
		dfs1(v, u, dep + 1);
	}
}
vector<int>r, t;
void dfs2(int u, int fa, int dep){
	r.push_back(u); if(dep > d2) d2 = dep, u2 = u, t = r;
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa) continue;
		 dfs2(v, u, dep + 1);
	} r.pop_back();
}
void dfs3(int u, int fa, int dep, int &cnt){
	if(dep == d2 / 2) {cnt++; cnt %= p; return;}
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].to; if(v == fa) continue;
		dfs3(v, u, dep + 1, cnt);
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &u, &v);
		link(u, v); link(v, u);
	}
	dfs1(1, 0, 1); dfs2(u1, 0, 1);
	if(d2 % 2 == 1){
		u3 = t[(d2 - 1) / 2]; int j = 1;
		for(int i = head[u3]; i; i = e[i].nxt, j++){
			int v = e[i].to; dfs3(v, u3, 1, cnt[j]);
			ans =  ans * (cnt[j] + 1ll) % p;
		}
		for(int i = 1; i <= j; i++) ans -= cnt[i];
		printf("%d\n", ans - 1);
	}
	else{
		u3 = t[d2 / 2 - 1]; v3 = t[d2 / 2];
		dfs3(u3, v3, 1, cnt[1]); dfs3(v3, u3, 1, cnt[2]);
		printf("%d\n", 1ll * cnt[1] * cnt[2] % p);
	}
}
