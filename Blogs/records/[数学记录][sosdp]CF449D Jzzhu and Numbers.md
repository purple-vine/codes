前几天做 arc 时连做两道高维前缀和，今天去看 dp 题单时发现这东西居然叫 sos dp，来刷一下板子。

粘一篇 [找到的 blog](https://www.cnblogs.com/cyl06/p/SOSDP.html)，感觉引入那里非常自然！

[link to CF](https://codeforces.com/problemset/problem/449/D) | [link to Luogu](https://www.luogu.com.cn/problem/CF449D)

> 给定一个长度为 $n$ 的序列，求选出一个子序列，这些数按位与为 $0$ 的方案数。
> 
> $n,a_i \leq 2^{20}$

首先显然正着不好做。数字太多了，按位与的信息量也很大，明显不可能存下来，因此要反着做。可以考虑的是反演或容斥。

现在尝试钦定一些位为 $1$。则根据容斥原理能写出 $ans = \sum 2^{f(S)} \cdot (-1)^{|S|}$，其中 $f(S)$ 代表钦定集合 $S$ 中的位为 $1$ 时的方案数。

接下来只用统计 $S \in i$ 的 $i$，取完补集后 $\~i \in \~S$（本地没事，cnblogs 上会炸，就是取反符号），这是高维前缀和板子，直接 FWT 上去即可。

这才 `*2400` 吗？可能是我初学 FWT 罢。

```cpp
#include <cstdio>
using namespace std;
const int M = 21, mod = 1000000007;
int sum[1 << M], a[1 << M], n, pw[1 << M];
void addn(int &x, int y) {if((x += y) >= mod) x -= mod;}
int main(){
    scanf("%d", &n); int all = (1 << 20) - 1;
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = 1ll * pw[i-1] * 2 % mod;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ++sum[all ^ a[i]];
    for(int i = 0; i < 20; i++) 
        for(int j = 0; j < 1 << 20; j++)
            if(j & (1 << i)) sum[j] += sum[j ^ (1 << i)];
    int ans = 0;
    for(int i = 0; i < 1 << 20; i++) {
        addn(ans, (__builtin_popcount(all ^ i) & 1) ? (mod - pw[sum[i]]) : pw[sum[i]]);
    }
    printf("%d\n", ans);
    
}
```