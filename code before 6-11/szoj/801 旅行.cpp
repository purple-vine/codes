#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 5005;
vector<int> e[M], ans, k;
int n, u, v, m, x, y, uu[M], vv[M], dfn[M], cnt;
bool operator < (const vector<int> &a, const vector<int> &b){
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i]) return a[i] < b[i];
	}
}
void dfs(int u, int fa){
	k.push_back(u);
	for(int v : e[u]){
		if(v == fa || (u == x && v == y) || (u == y && v == x) || dfn[v] == cnt) continue;
		dfn[v] = dfn[u]; dfs(v, u);
	}
}
void subtask1(){
	for(int i = 1; i <= n; i++) sort(e[i].begin(), e[i].end());
	cnt = 1; dfs(1, 0); for(int i : k) printf("%d ", i); return;
}
void subtask2(){
	for(int i = 1; i <= n; i++) sort(e[i].begin(), e[i].end());
	for(int i = 1; i <= m; i++){
		k.clear(); dfn[1] = cnt = i; x = uu[i]; y = vv[i]; dfs(1, 0);
		if(k.size() == n && (ans.size() == 0 || k < ans)) ans = k;
	} for(int i : ans) printf("%d ", i); return;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &uu[i], &vv[i]);
		e[uu[i]].push_back(vv[i]); e[vv[i]].push_back(uu[i]);
	}
	if(m == n - 1) subtask1();
	else subtask2();
}
