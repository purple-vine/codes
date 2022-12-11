博弈论好题，做完感觉加深了对 SG 函数的理解！

题意：

> 给定一张 DAG，问该 DAG 的 $2^m$ 张导出子图中有多少张满足 $SG[1]=SG[2]$
> 
> 注：此为转换后题意
> 
> $n \leq 15$

考虑推出 SG 的过程，执行一遍拓扑排序，取 $\operatorname{mex}$。

按 $SG$ 函数值把点分层，则一个 $x$ 层点需要连所有 $y < x$ 层点各至少一个。

dp 中重要的是找到答案的一个递推式的形式，发现任意合法答案都能用这种子小形式表达出来。

对于 CSPS2022 T3，发现一个合法的连通块是从多点往上到共同 lca 的路径并，据此分开考虑空 / 全部连到 lca 处。

$n$ 这么小，子集枚举是少不了了。那么需要 $f_S$ 表示只考虑集合 $S$ 中的点，且 $1,2$ $SG$ 值相同。然后会发现从后往前枚举是行不通了，因为 $1,2$ 可能连向任意点，需要存任意点的 $SG$，于是考虑从后往前，每次批量把 $SG=0$ 的点加进来。

形式化地，假设现在枚举到 $S$，钦定 $S$ 的子集 $U$ 的 $SG=0$，$T=S/U$，则以下条件应当被满足：

- $1,2$ 属于一个集合
- $U$ 集合内部不能连边
- $U \to T$ 任意连边，$T$ 中任一点与 $U$ 中有连边

预处理 $c_{x,S}$ 表示 $x$ 到 $S$ 集合连边总数，则第三条件的贡献为 $\displaystyle\prod_{t \in T} (2^{c_{t,U}}-1)\prod_{u \in U} 2^{c_{u,T}}$，乘上 $f_T$ 即可贡献给 $f_S$。总复杂度 $O(n 3^n)$。

部分借鉴于 [官方题解](https://img.atcoder.jp/agc016/editorial.pdf)

```cpp
#include <cstdio>
#include <assert.h>
#include <cmath>
using namespace std;
const int M = 17, mod = 1000000007;
int add(int a, int b) {a += b; return a > mod ? a-mod : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void addn(int &x, int y) {x += y; if(x > mod) x -= mod;}
int c[M][1 << M], f[1 << M], e[M], lg[1 << M], t[M * M];
int n, m; 
int main(){
  scanf("%d %d", &n, &m);
  t[0] = 1;
  for(int i = 1; i < n*n; i++) t[i] = 1ll * t[i-1] * 2 % mod;
  for(int i = 0; i < n; i++) lg[1 << i] = i;
  for(int i = 1; i <= m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    --u; --v;
    e[u] |= 1 << v; c[u][1 << v] = 1;
  }
  auto chk = [](int x, int S) -> bool {
    int ans = 0;
    for(int i = 0; i < n; i++) if(S & (1 << i)) ans += ((e[x] >> i) & 1);
    return ans;
  } ;
  const int all = (1 << n) - 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 1 << n; j++) {
      int t = j & -j;
      c[i][j] = c[i][j ^ t] + c[i][t];
    }
  }
  auto valid = [](int t) -> bool {return (t & 1) == ((t >> 1) & 1);};
  f[0] = 1;
  for(int S = 1; S < 1 << n; S++) {
    if(!valid(S)) continue;
    f[S] = 1; // 所有点 sg=0
    for(int T = S; T; T = S & (T-1)) {
      if(!valid(T)) continue;
      int U = S ^ T, ans = 1;
      for(int i = T; i; i -= i & -i) {
        int s = lg[i & -i]; 
        ans = 1ll * ans * (t[c[s][U]] - 1) % mod;
      }
      for(int j = U; j; j -= j & -j) {
        int u = lg[j & -j]; 
        ans = 1ll * ans * t[c[u][T]] % mod;
      }
      addn(f[S], 1ll * f[T] * ans % mod);
    }
    // printf("%d:%d\n", S, f[S]);
  }
  int ans = t[m]; // printf("ans=%d\n", ans);
  ans -= f[all]; ans %= mod; ans += mod; ans %= mod;
  printf("%d\n", ans);
}
```