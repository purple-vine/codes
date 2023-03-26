看 [这篇](https://www.cnblogs.com/BrianPeng/p/17103976.html) 看懂的，感觉比洛谷题解的两篇具体不少。

来写一下翻译。看懂后觉得官方题解更简练的，但显然我还是新手。思维走过的道路是无可替代的。

-----------------

> 题意：$n$ 面的骰子每次随机一个面，对 $i \in [1, m]$ 求得到全部面的次数的 $i$ 次方的期望。
> 
> $n, m \leq 2 \cdot 10^5$，取膜 $998244353$。

设出恰好 $i$ 轮得到所有面的 PGF $\displaystyle f(x) = \sum_{i \geq 0} p_i x^i$。考虑 

$$
\begin{aligned}
f(e^x) &= \sum_{i \geq 0} p_i \sum_{j \geq 0} \dfrac{(xi)^j}{j!} \\
&= \sum_{j \geq 0} \dfrac{x^j}{j!} \sum_{i \geq 0} p_i i^j
\end{aligned}
$$

则提取 $[\dfrac{x^i}{i!}]$ 即为所求 $i$ 次幂期望。

（感觉利用复合 $e^x$ 来取 $i$ 次幂是相当 pratical 的，所以懒得去揣测如何想到这样复合了，不如直接当作结论。）

（没有多想，但是觉得直接把 $i$ 次幂的期望值塞进 GF 中很好找到这个结论。）

因此所需的仅为找到 $f(x)$。

容易想到将 $p_i$ 作前缀和得到 $a_i$ 以去掉恰好的限制，$\{a_i\}$ 的 OGF 乘上 $(1 - x)$ 差分回来。

投掷骰子形成的是颜色序列，因此应求其 EGF

单颜色出现 $i$ 次的概率的 EGF 是 

$$
\sum_{i > 0} \dfrac{1}{n^i} \dfrac{x^i}{i!} = e^{\frac{x}{n}} - 1
$$

令 $F(x)$ 为 $\{a_i\}$ 的 EGF，则

$$
\begin{aligned}
F(x) 
& = (e^{\frac{x}{n}}-1)^n \\
& = \sum_{i = 0}^n \binom{n}{i} (-1)^{n-i} e^{\frac{xi}{n}}
\end{aligned}
$$

考虑到 EGF 中的 $e^{kx}$ 即为 OGF 中的 $\frac{1}{1-kx}$，

$$
f(x) = (1 - x) \sum_{i = 0}^n \binom{n}{i} (-1)^{n-i} \dfrac{1}{1 - \frac{ix}{n}}
$$

值得注意的是，此时已经是有限和的形式。

记得 $f(x)$ 与 $F(x)$ 并不是同一序列的 OGF 与 EGF，这里乘回了先前的 $(1-x)$。

此时求和的每一项都是形如 $\dfrac{c_i}{1 - d_i x}$ 的有理分式，可以直接通过分治求出形式为 $\dfrac{p(x)}{q(x)}$ 的 $f(x)$。因为只有次数低于 $m+1$ 的项是被关心的，此时再求逆得到 $f(x)$ 的各项系数。

注意到 $i![x^i] e^{kx} = [x^i] \dfrac{1}{1-kx}$，现在已经得到

$$
f(x) = \sum_{i = 0}^m p_i x^i
$$

计算 

$$
\sum_{i = 0}^m \dfrac{p_i}{1 - i x}
$$

的各项系数即可。这同样可以通过分治乘得到。

综上，这题结束了。复杂度据说是 $O(n \log^2 n + m \log m)$，分治乘的复杂度我不会算。

代码等明天写。