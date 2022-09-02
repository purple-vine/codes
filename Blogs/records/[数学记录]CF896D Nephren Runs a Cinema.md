题意：给定 $n=x+y+z$，求满足以下要求的长度为 $n$ 的序列的数目：序列由 $x$ 个 $1$，$y$ 个 $-1$，$z$ 个 $0$ 组成，序列任意前缀和非负，和在 $[l,r]$ 之间。

考虑确定 $z$ 和序列和的方案数。

看做卡特兰数类似折线图考虑。则在不能过线的前提下要到 $(x+1,y-x)$。

过线等价于经过 $y=x-1$。将经过后的路径翻折后经过 $(x+y+1,x-1)$。方案数是 $C_{x+y}^{x}-C_{x+y}^{x-1}$。

$$
l \leq y-x \leq r \\
x+y = n-z \\
\Rightarrow x \in \left [\frac{n-z-r}{2},\frac{n-z-l}{2} \right ] \\
\begin{aligned}
S & = \sum \limits_{z=0}^{n-r} C_{n}^{z} \cdot \sum_{x=\lceil \frac{n-z-r}{2} \rceil} ^ {\lfloor \frac{n-z-l}{2} \rfloor} (C_{n-z}^{x}-C_{n-z}^{x-1}) \\
 & = \sum \limits_{z=0}^{n-r} C_{n}^{z} \cdot (C_{n-z}^{\lfloor \frac{n-z-l}{2} \rfloor }-C_{n-z}^{\lceil \frac{n-z-r}{2} \rceil - 1})
\end{aligned}
$$
$\square$

这里不保证 $p$ 是质数。分离与膜数互质与不互质的地方并重载即可。

代码慢慢写，应该也不难写。