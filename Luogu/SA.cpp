//time : 2022-06-27 11:51
//problem url : https://atcoder.jp/contests/abc257/tasks/abc257_g
//status : not submitted
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int M = 1000005;
struct sa{
	int sa[M], rk[M << 1], cnt[M], id[M], prerk[M << 1], h[M], val[M << 1], n; char s[M];
    int f[M][25];
	void init(const char *l){
		n = 1;
		for(; l[n] != '\0'; n++) s[n] = l[n-1]; 
        --n;
	}
	bool cmp(int i, int j, int t) {return prerk[sa[j]] == prerk[sa[i]] && prerk[sa[j]+t] == prerk[sa[i]+t];}
	void get_sa(){
		int m = std::max(256, n), p = 256;
		for(int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i; i--) sa[cnt[rk[i]]--] = i;
		for(int i = 0; (1 << i) <= n; i++){
			int t = (1 << i), k = 0; m = p;
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
            if(rk[i] == 1) continue;
			if(k) --k;
			while(s[i+k] == s[sa[rk[i]-1] + k]) ++k;
			h[rk[i]] = k;
		} 
        for(int i = 1; i <= n; i++) printf("%d ", sa[i]); printf("\n");
        for(int i = 1; i <= n; i++) printf("%d ", rk[i]); printf("\n");
        for(int i = 1; i <= n; i++) printf("%d ", h[i]);
        printf("\n");
        int k = 20;
        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; i++) f[i][0] = h[i];
        for(int j = 1; j <= k; j++){
            for(int i = 1; i <= n; i++)
                f[i][j] = min(f[i+(1<<j-1)][j-1], f[i][j-1]);
        }
	} 
    int lcp(int x, int y){
        printf("x=%d y=%d\n", x, y);
        x = rk[x]; y = rk[y]; int u = min(x, y) + 1, v = max(x, y);
        int k = log2(v-u+1);
        printf("x=%d y=%d u=%d v=%d ans=%d\n", x, y, u, v, min(f[u][k], f[v - (1<<k) + 1][k]));
		return min(f[u][k], f[v - (1<<k) + 1][k]);
    }
}s, t;
string ss, tt; int dp[M], m, n;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ss >> tt; n = ss.length(); ss = ss + '#' + tt;
    s.init(ss.c_str()); m = tt.length(); s.get_sa();
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= m; i++){
        dp[i] = dp[i - s.lcp(n, n+i+1)] + 1;
    }
	printf("%d\n", dp[m]);
	return 0;
}
//aabaaaab