#include <cstdio>
#include <algorithm>
#define inf 1000000000
using namespace std;
const int M = 1005;
int f[M][2], n, a[M], m, n1, ans = -inf;
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); n1 = unique(a + 1, a + n + 1) - a;
	f[n][0] = a[n]; f[n][1] = -a[n];
	for(int i = n1 - 1; i >= 1; i--){
		if(a[i + 1] - a[i] > m) {f[i][0] = a[i], f[i][1] = -a[i]; continue;}
		f[i][0] = inf; f[i][1] = -inf;
		for(int j = i + 1; j <= n1 && a[j] - a[i] <= m; j++){
			f[i][0] = min(f[i][0], f[j][1]);
			f[i][1] = max(f[i][1], f[j][0]);
		}
		f[i][0] += a[i]; f[i][1] -= a[i];
	}
	for(int i = 1; i <= n1 && a[i] <= m; i++) ans = max(ans, f[i][0]);
	printf("%d", ans);
} 
