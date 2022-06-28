[link](https://atcoder.jp/contests/abc257/tasks/abc257_g)

题意简述：给定两个串 $s,t$，求至少用 $s$ 的几个前缀才能拼出 $t$。$|s|,|t| \leq 1e5$。

考虑 dp。设 $dp_i$ 表示至少用 $s$ 的几个前缀才能拼出 $t$ 的前 $i$ 个字符。转移方程：$dp_i=dp_j+1 \ \text{if} \ t_{j,j+1 \cdots i} = s_{1,2,\cdots i-j}$。这看着是个 $O(n^2)$ 的式子，考虑优化。

把 $dp_i$ 打出来看看规律。

```
1 1 1 2 2 3 3 3
```

发现 $dp_i$ 单调不降。

浅证：若 $dp_{i+1}<dp_i$，让拼成 $dp_{i+1}$ 的最后一个字符串去掉一个字母，显然仍是一个前缀，可以变成 $dp_i$ 的情况，矛盾。

所以只需对每个 $i$ 找出最小的 $j$ 满足 $t_{j,\cdots,i}$ 是 $s$ 的前缀，即可。这看着很像 kmp 的 `next` 数组。把 $s\#t$ 作为一个整体进行自我匹配，即得。

```cpp
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
```