#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define debug(x) printf(x); 
const int M = 2000005;
int sa[M], rk[M << 1], cnt[M], id[M], prerk[M << 1], h[M]; char s[M];
void get_sa(char *s, int n){
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
} 
int main(){
	scanf("%s", s+1); int n = strlen(s+1);
	for(int i = 1; i <= n; i++) s[i+n] = s[i];
	n <<= 1; get_sa(s, n);
	for(int i = 1; i <= n; i++) if(sa[i] <= n/2) printf("%c", s[sa[i] + n/2 - 1]);
	return 0;
}
//aabaaaab
