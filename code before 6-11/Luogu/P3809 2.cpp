#include <cstdio>
#include <algorithm>
#include <cstring>
const int M = 1000005;
int sa[M], rk[M]; char s[M];
void get_sa(char *s, int n){
	int m = 256;
	int *cnt = new int[256 << 1], *id = new int[n << 1];
//	memset(cnt, 0, 256 * sizeof(int)); memset(id, 0, n*2*sizeof(int));
	//id 是排好序的原数组的对应下标
	for(int i = 0; i < n; i++) ++cnt[rk[i] = s[i]];
	for(int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
	for(int i = n - 1; i; i--) sa[cnt[rk[i]]--] = i;
	for(int i = n-1; i; i--)
		printf("%d ", cnt[rk[i]]), sa[cnt[rk[i]]--] = i, printf("%d\n", cnt[rk[i]]);
	for(int i = 0; (1 << i) <= n; i++){
		int t = (1 << i);
		for(int j = 0; j < n; j++) id[j] = sa[j];
		for(int j = 0; j < n; j++) ++cnt[rk[id[j] + t]];
		for(int j = 1; j < m; j++) cnt[j] += cnt[j-1];
		for(int j = n-1; j; j--) sa[cnt[rk[id[j] + t]]--] = id[j];
		for(int j = 0; j < n; j++) id[j] = sa[j];
		for(int j = 0; j < n; j++) ++cnt[rk[id[j]]];
		for(int j = 1; j < m; j++) cnt[j] += cnt[j-1];
		for(int j = n-1; j; j--) sa[cnt[rk[id[j]]]--] = id[j];
		for(int j = 1; j <= n; j++) rk[sa[j]] = j;
		for(int j = 0; j < n; j++) printf("%d ", rk[j]);
		printf("\n");
		for(int j = 0; j < n; j++) printf("%d ", id[j]);
		printf("\n");
	}
//	for(int i = 0; i < n; i++) sa[rk[i] - 1] = i + 1;
	delete[] cnt, id;
} 
int main(){
	printf("hello\n");
	scanf(" %s", s); int n = strlen(s);
	printf("n=%d\n", n);
//	get_sa(s, n);
//	for(int i = 0; i < n; i++) printf("%d ", rk[i]);
//	printf("\n");
	for(int i = 0; i < n; i++) printf("%d ", sa[i]);
	system("pause");
	return 0;
}
//aabaaaab
