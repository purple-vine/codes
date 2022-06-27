#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define debug(x) printf(x); 
const int M = 105, N = 1005;
struct sa{
	int sa[M], rk[M << 1], cnt[M], id[M], prerk[M << 1], h[M], val[M << 1], n; int s[M];
	void init(int *l){
		n = 1; s[1] = l[0]; 
		for(; l[n-1] != '\0'; n++) s[n] = l[n-1]; 
		--n;
	}
	bool cmp(int i, int j, int t) {return prerk[sa[j]] == prerk[sa[i]] && prerk[sa[j]+t] == prerk[sa[i]+t];}
	void get_sa(){
		int m = std::max(1841, n), p = 1841;
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
	int cmp(int *x, int *y, int n){
		for(int i = 0; i < n; i++) if(x[i] != y[i]) return x[i] < y[i] ? -1 : 1;
		return 0;
	}
	bool find(int *str, int len){
		int l = 1, r = n, ans = 0;
		while(l <= r){
			int mid = l + r >> 1, val = cmp(str, &s[sa[mid]], len);
			if(val == 0) return 1;
			else if(val < 0) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		int pl = sa[ans];
//		for(int i = 1; i <= len; i++) if(str[i-1] != s[pl+i-1]) return 0;
		return 0;
	}
}s[N];
int st[M], str[M][N], len[M], ll; int n;
bool check(int l){
	for(int i = 1; i <= ll-l+1; i++){
		memset(st, 0, sizeof(st)); 
		for(int k = 1; k <= l; k++) st[k] = str[1][i+k-1];
		bool f = 1;
		for(int k = 2; k <= n; k++)
			if(!s[k].find(st+1, i)) f = 0;
		if(f) return 1;
	}
	return 0;
}
int a[M];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &len[i]);
		for(int j = 1; j <= len[i]; j++) scanf("%d", &a[j]);
		len[i]--; for(int j = 1; j <= len[j]; j++) str[i][j] = a[j+1] -  a[j];
	}
	for(int i = 2; i <= n; i++) s[i].init(str[i]+1), s[i].get_sa();
	ll = len[1]; int l = 0, r = ll, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, l = mid+1;
		else r = mid-1;
	}
	printf("%d\n", ans+1);
	return 0;
}
//aabaaaab
