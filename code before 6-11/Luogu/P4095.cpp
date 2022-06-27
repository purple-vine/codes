#include <cstdio>
#include <iostream>
#include <cstring> 
using namespace std;
const int M = 1005, N = 1005;
int l[N][M], r[N][M], ans[N][M], q, d, e, a[M], b[M], c[M], m = 1000, n;
int v[M][N], w[M][N], cnt[N];
void deal(int *dp, int *v, int *w, int n){
	for(int j = 1; j <= n; j++)
		for(int i = m; i >= 0; i--)
			if(i >= v[j]) dp[i] = max(dp[i], dp[i - v[j]] + w[j]);
}
void merge(int *dp, int *f1, int *f2){
	for(int i = 0; i <= m; i++)
		for(int j = 0; j <= i; j++)
			dp[i] = max(dp[i], f1[j] + f2[i - j]);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	for(int t = 1; t <= n; t++){
		memcpy(l[t], l[t - 1], sizeof(l[t - 1]));
		int tot = 0;
		for(int s = 1; tot + s <= c[t]; s <<= 1)
			v[t][++cnt[t]] = s * a[t], w[t][cnt[t]] = s * b[t], tot += s;
		if(c[t] != tot) v[t][++cnt[t]] = (c[t] - tot) * a[t], w[t][cnt[t]] = (c[t] - tot) * b[t];
		deal(l[t], v[t], w[t], cnt[t]);
	}
	for(int t = n; t >= 1; t--){
		memcpy(r[t], r[t + 1], sizeof(r[t + 1]));
		deal(r[t], v[t], w[t], cnt[t]);
	}
	for(int i = 1; i <= n; i++)
		merge(ans[i], l[i - 1], r[i + 1]);
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= 10; j++) printf("%d ", l[i][j]);
//		printf("\n");
//	} printf("\n");
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= 10; j++) printf("%d ", r[i][j]);
//		printf("\n");
//	} printf("\n");
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= 10; j++) printf("%d ", ans[i][j]);
//		printf("\n");
//	} printf("\n");
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &d, &e);
		printf("%d\n", ans[d + 1][e]);
	}
}
