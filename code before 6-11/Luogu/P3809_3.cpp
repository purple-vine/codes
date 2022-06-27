#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(x) printf(x); 
const int M = 1000005;
int sa[M], rk[M], cnt[M], id[M]; char s[M];
void get_sa(char *s, int n){
	int m = 256;
	for(int i = 0; i < n; i++) ++cnt[rk[i] = s[i]];
	for(int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
	for(int i = n - 1; i >= 0; i--) sa[--cnt[rk[i]]] = i;
		for(int j = 0; j < n; j++) printf("%d ", sa[j]);
		printf("\n");
		for(int j = 0; j < n; j++) printf("%d ", rk[j]);
		printf("\n");
		for(int j = 0; j < n; j++) printf("%d ", id[j]);
		printf("\n");
	for(int i = 0; (1 << i) <= n; i++){
		int t = (1 << i);
		memset(cnt, 0, sizeof(cnt));
		for(int j = 0; j < n; j++) id[j] = sa[j];
		for(int j = 0; j < n; j++) ++cnt[rk[id[j] + t]];
		for(int j = 1; j < m; j++) cnt[j] += cnt[j-1];
//		for(int j = 0; j < m; j++) if(cnt[j]) printf("cnt[%d ] = %d\n", j, cnt[j]);
		printf("\n");
		for(int j = n-1; j >= 0; j--){
			printf("precnt = %d", cnt[rk[id[j]+t]]); --cnt[rk[id[j] + t]]; printf("nowcnt=%d\n", cnt[rk[id[j]+t]]);
			sa[cnt[rk[id[j] + t]]] = id[j];
			printf("id[j] = %d id[j]+t = %d cnt[rk[id[j]+t]]=%d\n", id[j], id[j]+t, cnt[rk[id[j]+t]]);
			printf("sa[--cnt[%d]] = sa[%d] = %d\n", rk[id[j] + t], cnt[rk[id[j] + t]], id[j]);
		}
		memset(cnt, 0, sizeof(cnt)); printf("\n");
		for(int j = 0; j < n; j++) id[j] = sa[j];
		for(int j = 0; j < n; j++) ++cnt[rk[id[j]]];
		for(int j = 1; j < m; j++) cnt[j] += cnt[j-1];
		for(int j = n-1; j >= 0; j--) sa[--cnt[rk[id[j]]]] = id[j], printf("sa[--cnt[%d]] = sa[%d] = %d\n", rk[id[j]], cnt[rk[id[j]]], id[j]);
		for(int j = 0; j < n; j++) rk[sa[j]] = j;
		for(int j = 0; j < n; j++) printf("%d ", sa[j]);
		printf("\n");
		for(int j = 0; j < n; j++) printf("%d ", rk[j]);
		printf("\n");
		for(int j = 0; j < n; j++) printf("%d ", id[j]);
		printf("\n");
	}
//	for(int i = 0; i < n; i++) sa[rk[i] - 1] = i + 1;
} 
int main(){
	printf("hello\n");
	scanf(" %s", s); int n = strlen(s);
	printf("n=%d\n", n);
	get_sa(s, n);
//	for(int i = 0; i < n; i++) printf("%d ", rk[i]);
//	printf("\n");
	for(int i = 0; i < n; i++) printf("%d ", sa[i] + 1);
	system("pause"); getchar();
	return 0;
}
//aabaaaab
