在随机跳一点 CF 的紫题做。为什么随机一跳就是 CNR。

感觉这能 *2900 有点震撼。不过我不是也没独立做出来嘛。

尝试只为行或列构造，很容易想到直接逐一交换，但是这样会破坏另一维的结构。

怎么做呢，怎么做呢。你忽然注意到这是个方阵诶，可以试着递归弄掉一行一列。

那每次只能放第一行与第一列并起来的部分。目测空间还是挺大的，那就把要到第一行的那位和要到第一列去的那位拎出来一起满足。

定睛一看 —— 还真可以？让他们第一格就互相传送不就行了？然后还会自然有人把他们的位置填补上！

![img](https://img2023.cnblogs.com/blog/2840104/202303/2840104-20230326155641769-1572960047.png)

做完了。判一下不用传送的情况。

这个做法很依赖 $n \times n$ 的性质。看到方阵，想着递归还是挺对的。感觉有点厉害。~~这不是 MO 常见对行列较小值归纳怎么我都做不出来。~~

仔细一想，它在降低单点还原对其它点的影响。同时处理一行一列的思想是最精彩的。

其实一句话就能说完做法 ：递归同时弄掉一行一列。

代码简洁而富有对称性。

```cpp
#include <bits/stdc++.h>
const int M = 1005;
int main() {
  int n; scanf("%d", &n);
  std::vector<std::tuple<int, int, int, int> > ans;
  std::vector<int> a(n+1), b(n+1), p(n+1), q(n+1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]), q[b[i]] = i;
  for (int i = 1; i < n; i++) {
    auto swapa = [&](int u, int v) -> void {
      std::swap(p[a[u]], p[a[v]]), std::swap(a[u], a[v]);
    } ;
    auto swapb = [&](int u, int v) -> void {
      std::swap(q[b[u]], q[b[v]]), std::swap(b[u], b[v]);
    } ;
    int u = p[i], v = q[i];
    if (p[i] == i && q[i] == i) continue;
    ans.push_back({i, q[i], p[i], i});
    swapa(i, p[i]), swapb(i, q[i]);
  }
  printf("%d\n", ans.size());
  for (auto [a, b, c, d] : ans) 
    printf("%d %d %d %d\n", a, b, c, d);
}
/*
stupid mistakes:
  - 输入错位
*/
```