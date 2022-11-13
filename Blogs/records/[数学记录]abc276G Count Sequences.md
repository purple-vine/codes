题意：对满足以下条件的序列计数，膜 $998244353$：

- $0 \leq a_0 \leq a_1 \cdots \leq a_n \leq m$
- $a_i \not\equiv a_j \pmod 3 $

这题的难点在于发现它是简单题。

想了一上午生成函数啊（

不等于很难处理，所以做一遍差分，令 $n$ 自增 $1$，题意转化为：$\sum b_i = m$ 且 $b_i \not\equiv 0$ 对 $i \in [2,n-1]$ 成立。

<del> 然后就会发现等价于求 $[x^m] \left ( \dfrac{1}{1-x} \right)^2 \left ( \dfrac{1}{1-x}-\dfrac{1}{1-x^3} \right )^{n-2}$，然后怎么算呢，我也不会啊hh </del>

首先，数字的个数是一定的，这意味着其实可以只关注膜 $3$ 余数。

为了处理回剩余数，应把多于的 $3$ 分配到剩下数。

能发现中间的数的取值只有 $1/2$，这意味着枚举几个 $2$ 是完全可接受的。

此时同时枚举第一个数，最后一个数便会随之确定。

做完了。这是黄？我不信。

```cpp
#include <cstdio>
using namespace std;
const int M = 1e7+5, mod = 998244353;
int qpow(int a, int b){
    long long ans = 1ll;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
    return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
int fac[M], invfac[M], invn[M];
void pre(int n = M - 3){
    fac[0] = invfac[0] = fac[1] = invfac[1] = invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod,
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int n, m, ans;
int main(){
    pre(); scanf("%d %d", &n, &m);
    ++n;
    for(int i = 0; i <= n-2; i++) {
        int j = n - 2 - i;
        for(int s = 0; s < 3; s++) {
            int t = (m - 2*i - j - s) % 3;
            if(t < 0) continue;
            int res = m - 2*i - j - t - s; res /= 3;
            add(ans, 1ll * C(n-2, i) * C(res + n - 1, n - 1) % mod);
        }
    } 
    printf("%d\n", ans);
}
```

--------------

upd 11/13

在 Luogu 上看到 [一个生成函数题解](https://www.luogu.com.cn/blog/Unique-Hanpi/abc276g-ti-xie)，最后的式子也化到了自己卡住那步，把后面的来补全一下。

要求的即为 

$$ 
\begin{aligned}
& [x^m] \left ( \dfrac{x^2+x}{1-x^3} \right )^{n-2} \cdot \dfrac{1}{(1-x)^2} \\
= & [x^{m-n+2}] \dfrac{(x+1)^{n-2}}{(1-x^3)^{n-2}} \cdot \dfrac{1}{(1-x)^2} \\
\end{aligned}
$$

$\dfrac{1}{(1-x)^2}$ 相当于对前面的东西弄个二维前缀和，而 

$$
\begin{aligned}
(x+1)^{n-2} &= \sum \limits_{m \geq 0} \binom{n-2}{m} x^m \\
\dfrac{1}{(1-x^3)^{n-2}} &= \sum\limits_{m \geq 0} \binom{n-3+m}{m}x^{3m}
\end{aligned}
$$

先把两者中的一者卷个 $\dfrac{1}{(1-x)^2}$ 再和另一者卷起来即可，因为只需要一项，不需要 NTT，总时间复杂度线性。