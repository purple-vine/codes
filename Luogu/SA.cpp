#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define debug(x) printf(x); 
const int M = 1000005;
//sa:排名为 i 的后缀的开头  rk:以 i 开头的后缀的排名
//id:我们以什么顺序考虑这个数组，rk相当于要排序的数组，id 是排好序的 rk 的下标序列 
struct sa{
	int sa[M], rk[M << 1], cnt[M], id[M], prerk[M << 1], h[M], val[M << 1], n; char s[M];
	void init(char *l){
		n = 1;
		for(; l[n] != '\0'; n++) s[n] = l[n-1]; 
	}
	bool cmp(int i, int j, int t) {return prerk[sa[j]] == prerk[sa[i]] && prerk[sa[j]+t] == prerk[sa[i]+t];}
	void get_sa(){
		int m = std::max(256, n), p = 256;
		for(int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i; i--) sa[cnt[rk[i]]--] = i;
		for(int i = 0; (1 << i) <= n; i++){
			int t = (1 << i), k = 0; m = p; //printf("%d\n", m);
			for(int j = n; j > n - t; j--) id[++k] = j;
			for(int j = 1; j <= n; ++j)
				if (sa[j] > t) id[++k] = sa[j] - t;
			memset(cnt, 0, sizeof(cnt));
			for(int j = 1; j <= n; j++) ++cnt[val[j] = rk[id[j]]];
			for(int j = 1; j <= m; j++) cnt[j] += cnt[j-1];
			for(int j = n; j; j--) sa[cnt[val[j]]--] = id[j];
			memcpy(prerk, rk, sizeof(rk)); p = 0;
		    for(int j = 1; j <= n; j++){
		    	if(cmp(j, j-1, t)) rk[sa[j]] = p;
		    	else rk[sa[j]] = ++p;
			}
			if(p == n) break;
		}
		for(int i = 1, k = 0; i <= n; i++){
			if(k) --k;
			while(s[i+k] == s[sa[rk[i]-1] + k]) ++k;
			h[rk[i]] = i;
		} 
	} 
}s;
char str[M];
int main(){
	scanf(" %s", str+1);
	s.init(str+1); s.get_sa();
	for(int i = 1; i <= s.n; i++) printf("%d ", s.sa[i]);
	return 0;
}
//aabaaaab