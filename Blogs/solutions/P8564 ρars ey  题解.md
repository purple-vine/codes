首先看到这道题的人都知道这是树上背包。背包的部分可以略讲。这道题的重点是，为什么树上背包加上合并信息时的上下界优化可以做到 $O(n^2)$？

```cpp
// O(n^2)
for(int k = siz[u] + siz[v]; k >= 0; k--){
    dp[u][k] = inf;
    for(int j = max(k - siz[u], 1); j <= min(siz[v], k); j++){
        dp[u][k] = min(dp[u][k], dp[u][k - j] + dp[v][j]);
    }
}
siz[u] += siz[v];
```

```cpp
// O(n^3)
for(int k = siz[u] + siz[v]; k >= 0; k--){
    dp[u][k] = inf;
    for(int j = 1; j <= siz[v] && j <= k; j++){
        dp[u][k] = min(dp[u][k], dp[u][k - j] + dp[v][j]);
    }
}
siz[u] += siz[v];
```

分析下者复杂度上界是 $O(n^3)$ 是显然的。上层循环、下层循环的复杂度上界是 $O(n)$，加上 dfs 的 $O(n)$，是 $O(n^3)$。

构造一条链即可卡到理论复杂度上界：对于深度为 $m$ 的节点，其运算量为 $O(m^2)$。

究其原因，是每次把 $v$ 中的信息完整合并到 $u$ 时，总会有一些多余情况，或者说，无法直接合并的情况。比如，$k-j \leq siz_u$ 时，$dp_{u,k-j}$ 才已经经过计算。现在通过调整循环范围优化掉这里。

复杂度我也只能给个偏感性理解：

当把 $v$ 合并到 $u$ 上时，因为 $u$ 中原来没有含 $v$ 的信息，所以每次合并不会重复合并一对点的信息。又因为现在循环范围内每一次合并都合法，所以最多合并了 $O(n^2)$ 对点的信息，所以复杂度是 $O(n^2)$。

[真正严谨的证明](https://www.cnblogs.com/ouuan/p/BackpackOnTree.html)

大开眼界。我初二时自己想到了如此优化上下界，但是却无法证明其复杂度。直到今天，$O(n^3)$ 的树上背包被卡，$O(n^2)$ 能过，才去了解了其复杂度。

-------------------

但是要交题解，还是把背包思路与转移说一下

我们发现一个节点的子树中留的数具体是什么是不重要的，重要的是数目，所以设出状态 $dp_{u,i}$ 表示以 $u$ 为根的子树留 $i$ 个节点的最小花费。

首先假设 $u$ 不删去。这个问题就是一个树上背包，如果只考虑 $v'$ 前的子树时对 $u$ 的影响是 $dp'_{u,i}$，转移式形如 $dp_{u,i+j} \gets dp'_{u,i} + dp_{v,j}$。这个显然能压到一维，但是要倒序枚举 $i+j$。

代码其实不大难写

```cpp
#include <cstdio>
#include <algorithm>
#include <iostream>
#define inf (1e18)
using namespace std;
const int M = 5005;
long long dp[M][M], n, f[M];
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1, siz[M];
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
// dp[u][i] : 以 u 为根留 i 数
void dfs(int u, int fa){
    for(int i = 0; i <= n; i++) dp[u][i] = inf;
    dp[u][0] = 0; // 首先让 dp_u 不考虑 u
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        dfs(v, u);
        for(int k = siz[u] + siz[v]; k >= 0; k--){
            dp[u][k] = inf; // v 中不能用 0 转移，所以不能直接采用原来的答案
            for(int j = max(k - siz[u], 1); j <= min(siz[v], k); j++){
                dp[u][k] = min(dp[u][k], dp[u][k - j] + dp[v][j]);
            }
        }
        siz[u] += siz[v];
    }
    ++siz[u];
    for(int i = siz[u]; i >= 1; i--) dp[u][i] = dp[u][i-1];
    dp[u][0] = inf; dp[u][1] = f[siz[u] - 1]; dp[u][siz[u]] = 0;
    for(int j = 2; j <= siz[u]; j++){
        dp[u][1] = min(dp[u][1], dp[u][j] + f[j-1]); // 现在考虑对 u 操作
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%d", &f[i]);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    dfs(1, 0);
    printf("%lld\n", dp[1][1]);
}
```