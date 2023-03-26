斜优 dp 绝世好题。

[link to Luogu](https://www.luogu.com.cn/problem/CF1067D) | [link to CF](https://codeforces.com/problemset/problem/1067/D)

题意：

> 有 $n$ 游戏，每个游戏有收益 $a_i$，升级后收益 $b_i$，成功率 $p_i$。每秒玩一个游戏，若成功获得收益并可将一个游戏升级。求玩 $t$ 秒最大期望收益。
> 
> $t \leq 10^{10}, a_i \leq b_i, n \leq 10^5$

首先发现可以应该先获得升级机会，然后疯狂点期望收益最大的游戏。

令 $f_t$ 表示剩 $t$ 秒、当前未升级时的情况，$v$ 代表最大的 $b_i p_i$，则

$$
\begin{aligned}
f_{t+1} &= \max\limits_{i=1}^{n} \{ p_i(a_i + t \cdot v) + (1-p_i) \cdot f_t \} \\
&=f_t + \max\limits_{i=1}^{n} \{ p_i(- f_t + t \cdot v) + a_i p_i \} \\
&= f_t + \max\limits_{i=1}^{n} \left \{ \begin{bmatrix} p_i \\ a_ip_i \end{bmatrix} \cdot \begin{bmatrix} -f_t+t v \\ 1 \end{bmatrix} \right \} \\
&= f_t + \max\limits_{i=1}^{n} \left \{ \begin{bmatrix} a_ip_i \\ -a_i \end{bmatrix} \times \begin{bmatrix} -f_t+t v \\ 1 \end{bmatrix} \right \}
\end{aligned}
$$

熟知用 $\begin{bmatrix} x_i \\ 1 \end{bmatrix}$ 与其余若干给定向量做点乘或叉乘取极值，若 $x_i$ 单调则决策点单调。

$$
\begin{aligned}
-f_t + tv & \leq  -f_{t+1} + (t+1)v \\
\iff f_{t+1} - f_t & \leq  v
\end{aligned}
$$

新增一次选择不会让期望增加 $t$ 以上，故原式显然成立。

$t$