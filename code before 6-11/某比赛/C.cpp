#include <cstdio>
#include <map>
using namespace std;
map<int, bool>t;
const int M = 55;
int n, k, a[M], m[M], ans; bool f[M];
void dfs(int num, int c){
	if(c == k + 1){
		if(!t[num]) t[num] = 1, ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(f[i]) continue;
		f[i] = 1;
		dfs(num * m[i] + a[i], c + 1);
		f[i] = 0;
	}
}
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] < 10) m[i] = 10;
		else m[i] = 100;
	}
	dfs(0, 1);
	printf("%d\n", ans);
}
