//给定一个长度为 n 的字符串，以及一个常数 k，求出现次数至少为 k 次的最长子串，以及所有满足这个性质的子串中左端点的最右可能。 
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#define clr(x) memset(x, 0, sizeof(x))
#define debug(x) printf(x); 
const int M = 1000005;
int sa[M], rk[M << 1], cnt[M], id[M], prerk[M << 1], h[M], s[M];
void get_sa(int *s, int n){
	int m = std::max(256, n);
	for(int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
	for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for(int i = n; i; i--) sa[cnt[rk[i]]--] = i;
	for(int i = 0; (1 << i) <= n; i++){
		int t = (1 << i);
		memset(cnt, 0, sizeof(cnt));
		for(int j = 1; j <= n; j++) id[j] = sa[j];
		for(int j = 1; j <= n; j++) ++cnt[rk[id[j] + t]];
		for(int j = 1; j <= m; j++) cnt[j] += cnt[j-1];
		for(int j = n; j; j--) sa[cnt[rk[id[j] + t]]--] = id[j];
		memset(cnt, 0, sizeof(cnt));
		for(int j = 1; j <= n; j++) id[j] = sa[j];
		for(int j = 1; j <= n; j++) ++cnt[rk[id[j]]];
		for(int j = 1; j <= m; j++) cnt[j] += cnt[j-1];
		for(int j = n; j; j--) sa[cnt[rk[id[j]]]--] = id[j];
		memcpy(prerk, rk, sizeof(rk));
	    for(int p = 0, j = 1; j <= n; j++){
	    	if(prerk[sa[j]] == prerk[sa[j-1]] && prerk[sa[j]+t] == prerk[sa[j-1]+t])
	    		rk[sa[j]] = p;
	    	else rk[sa[j]] = ++p;
		}
	}
	for(int i = 1, k = 0; i <= n; i++){
		if(k) --k;
		while(s[i+k] == s[sa[rk[i]-1] + k]) ++k;
		h[rk[i]] = k;
	}
//	for(int i = 1; i <= n; i++) printf("%d ", sa[i]); printf("\n");
//	for(int i = 1; i <= n; i++) printf("%d ", rk[i]); printf("\n"); 
//	for(int i = 1; i <= n; i++) printf("%d ", h[i]); printf("\n"); 
} 
int n; int hs[M], l1, r1, k; //hs需要最小值
int main(){
//	freopen("1.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
	if(k == 1) {printf("%d 0\n", n); return 0;}
	get_sa(s, n); int l = 1, r = n, ans = 0, pl = 0;
	l1 = 1; r1 = 0;
	for(int i = 1; i <= n; i++){
		while(l1 <= r1 && h[hs[r1]] >= h[i]) r1--;
		hs[++r1] = i;
		while(hs[r1] - hs[l1] + 1 > k - 1) l1++; //hs 中留 k-1 项 
		int t = h[hs[l1]];
		if(t > ans) ans = t;
//		printf("i=%d pl=%d t=%d\n", i, maxpl, t);
//		printf("hs:"); for(int i = l1; i <= r1; i++) printf("%d ", h[hs[i]]); printf("\n");
//		printf("sas:"); for(int i = l2; i <= r2; i++) printf("%d ", sa[sas[i]]); printf("\n");
	}
	if(ans == 0) printf("none\n");
	else printf("%d\n", ans);
	return 0;
} 
