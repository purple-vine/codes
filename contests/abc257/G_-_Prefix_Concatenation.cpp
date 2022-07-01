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
string s, t; int dp[M], m, n, nxt[M];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t; n = s.length(); m = t.length();
    s = s + '#' + t;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n+m; i++){
        int j = nxt[i-1];
        while(j > 0 && s[i] != s[j]) j = nxt[j-1];
        if(s[i] == s[j]) ++j;
        nxt[i] = j;
    }
    for(int i = 1; i <= m; i++){
        dp[i] = dp[i-nxt[n+i]] + 1;
    }
	printf("%d\n", dp[m] >= 0x3f3f3f3f ? -1 : dp[m]);
	return 0;
}
//aabaaaab