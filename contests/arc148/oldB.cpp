#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 50005;
char s[M], ps[M]; int cnt[M], n, maxx, pl[M], cnt1, lpl;
int sa[M], rk[M], id[M], val[M], h[M], prerk[M];
bool cmp(int i, int j, int t) {return prerk[sa[j]] == prerk[sa[i]] && prerk[sa[j]+t] == prerk[sa[i]+t];}
void get_sa(char *s, int n){
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
int main(){
    scanf("%d", &n); scanf("%s", s+1); 
    for(int i = 1; i <= n; i++) ps[i] = s[n-i+1] == 'd' ? 'p' : 'd';
    get_sa(ps, n);
    for(int i = 1; i <= n; i++){
        if(s[i] == 'p' && !lpl) lpl = i;
        if(s[i] == 'p') cnt[i] = cnt[i-1] + 1;
        if(cnt[i] > maxx) pl[cnt1 = 1] = i, maxx = cnt[i];
        else if(cnt[i] == maxx) pl[++cnt1] = i;
    }
    sort(pl+1, pl+cnt1+1, [](int x, int y) {return rk[n-x+1] < rk[n-y+1];});
    // for(int i = 1; i <= cnt1; i++) printf("%d ", pl[i]);
    // printf("\n");
    int rpl = pl[1]; // printf("%d %d\n", lpl, rpl);
    if(lpl == 0) {printf("%s\n", s+1); return 0;}
    for(int i = 1; i < lpl; i++){
        printf("%c", s[i]);
    }
    for(int i = lpl; i <= rpl; i++){
        printf("%c", s[lpl + rpl - i] == 'd' ? 'p' : 'd');
    }
    for(int i = rpl+1; i <= n; i++){
        printf("%c", s[i]);
    }
}