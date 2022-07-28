先解释一下为什么已有 13 篇题解还要交：仔细翻过了一遍题解区，发现没有一篇与自己的相同，使用组合数减少枚举量的，所以打算来交一篇。

题意：给定 $l$，$r$，求所有 $l$ 与 $r$ 间的数，满足写成二进制后 $0$ 的个数不小于 $1$ 的个数。

首先这种统计数位信息的一定是数位 dp 或推式子题。但是你会发现，如果想要推式子，限制非常多，所以可以使用数位 dp 自动分讨。

首先，我们需要把二进制提取出来。


```cpp
int solve(int n){
    cnt = 0; memset(f, 0, sizeof(f)); // 不清空记搜数组，由于用的是之前的限制，会出大问题，然而不清有 50 分……
    for(; n; n >>= 1) a[++cnt] = n & 1;
    reverse(a+1, a+cnt+1);
    int ans = 0;
    // do something
    return ans;
}
```

首先设计状态。由于“小于等于”比较难控制，我选择了“恰好”。

```cpp
int f[M][M][2];
int dp(int n, int m, bool l){ //填到 n 位，后恰好 m 个 0，l 为 1 表示前面都是顶着限制填的
    if(f[n][m][l]) return f[n][m][l]; // 如果搜过了就不用搜了
    if(m < 0) return 0; // 如果 m 都已经小于 0 了，就不用往后走了
    if(cnt - n + 1 < m) return 0; // 我用 cnt 表示当前在搜的数，如果后面的全填上 0 都不够，就应该立刻返回
    if(n == cnt + 1) return m == 0; // 这里是搜索的终点
    // do something
    return f[n][m][l] = ans; 
}
```

这里 $n$ 的范围极小，不会超过 $\log_2 r < 32$，于是可以放心把 $l$ 也放入记搜数组。

接着考虑如何计算答案。

```cpp
int ans = 0;
if(l) {
    if(a[n] == 0) ans += dp(n+1, m-1, 1); // 限制是 0 的情况，只能填 0，同时这仍是顶着限制的
    else ans += dp(n+1, m-1, 0) + dp(n+1, m, 1); // 限制是 1，可以选择 0 或 1，如果选了 0，就不会再顶着限制了
} else {
    ans += dp(n+1, m-1, 0) + dp(n+1, m, 0); // 前者填 0，后者填 1
}
```

当你运行代码时，你会发现它的输出大大多于了标准输出。

观察样例解释，原来是忽略了前导 0。

你可能会想修改状态解决问题。但是转而想，如果第一位就是 0，也就不用考虑限制了。于是就只用挑一些数位放上 0 了。这是一个组合数问题。

组合数预处理：

```cpp
int c[M][M];
void pre(int n = 200){
    c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= n; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}
```

计算此部分的答案：

```cpp
// 下面一句处理第一位是 0 的情况，i 表示共填几位，j 表示其中几个 0，第一位一定是 1
for(int i = 2; i < cnt; i++) for(int j = (i+1)/2; j < i; ++) ans += c[i-1][j]; // i 减 1 是因为最高位不能填 0
```

最后加上前面第一位是 1 时的答案

```cpp
// 从 2 开始是因为第一位是 1
for(int i = (cnt+1)/2; i <= cnt-1; i++) ans += dp(2, i, 1);
```

分析复杂度。每个 $f_{i,j,k}$  最多只被搜索一次，这仅有 $32 \cdot 32 \cdot 2$ 不到的计算量。看似我们对每个 $j$ 都搜了一次，但是，这并不会让复杂度更劣，反之，这让代码更易理解。

upd：后来自己意识到在 dp 时，如果 l 是 0，可以直接返回组合数。但亲测不会优化时间（30ms -> 39ms），不过这在数字够大时会有明显优化。

完整代码：

```cpp
//time : 22-7-26 21:28
//problem url : https://www.luogu.com.cn/problem/P6218
//status : not submitted
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 205;
int f[M][M][2], n, l, r, a[M], cnt;
int c[M][M];
int dp(int n, int m, bool l){ //填到 n 位，后恰好 m 个 0，l 为 1 表示前面都是顶着限制填的
    if(f[n][m][l]) return f[n][m][l];
    if(m < 0) return 0;
    if(cnt - n + 1 < m) return 0; 
    // if(m == cnt - n + 1 && !l) return 1;
    if(n == cnt + 1) return m == 0;
    if(!l) return c[cnt-n+1][m];
    int ans = 0;
    if(l) {
        if(a[n] == 0) ans += dp(n+1, m-1, 1); // 限制是 0 的情况，只能填 0
        else ans += dp(n+1, m-1, 0) + dp(n+1, m, 1); // 限制是 1，可以选择 0 或 1
    } else {
        ans += dp(n+1, m-1, 0) + dp(n+1, m, 0); // 前者填 0，后者填 1
    }
    // printf("%d %d %d %d\n", n, m, l, ans);
    return f[n][m][l] = ans; 
}
void pre(int n = 200){
    c[0][0] = c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= n; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}
int solve(int n){
    cnt = 0; memset(f, 0, sizeof(f));
    for(; n; n >>= 1) a[++cnt] = n & 1;
    reverse(a+1, a+cnt+1);
    int ans = 0;
    // 下面一句处理第一位是 0 的情况，i 表示共填几位，j 表示其中几个 0，第一位一定是 1
    for(int i = 2; i < cnt; i++) for(int j = (i+1)/2; j < i; j++) ans += c[i-1][j];
    // printf("%d\n", ans);
    // 从第二位填起，第一位一定是 1
    for(int i = (cnt+1)/2; i <= cnt-1; i++) ans += dp(2, i, 1);
    return ans;
}
int main(){
    int n; pre();
	// while(~scanf("%d", &n)){
	// 	printf("%d\n", solve(n) + 1);
    //     memset(f, 0, sizeof(f));
	// }
    scanf("%d %d", &l, &r);
    // printf("%d %d %d\n", solve(r), solve(l-1), solve(r) - solve(l-1));
    printf("%d\n", solve(r) - solve(l-1));
}
```