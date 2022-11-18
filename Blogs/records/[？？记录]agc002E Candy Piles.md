agc 的题好神啊。

学校里想了个思路，回家开题解，才发现自己的思路离谱至极，浪费了这道题后面的思考。

[link to atcoder](https://atcoder.jp/contests/agc002/tasks/agc002_e) [link to Luogu](https://www.luogu.com.cn/problem/AT_agc002_e)

题意：给定 $n$ 堆石子，二人博弈，操作二选一：

- 把所有有石子的堆取走一个石子
- 取完最大堆

求胜者。

注意到操作一不改变相对大小顺序，开始时排一遍序，每次操作相当于去掉最左边一堆，注意到每堆取走一个等价于把把基准线往上推 $1$。画出条形图，则操作 $1$ 去最左一列，操作 $2$ 去最下一行，对应了左下端点的右移与左移，那么左下端点到达条形图边界是必胜态，其它可以照样递推求得。

![](https://s2.ax1x.com/2019/10/13/uxite0.png)

（图源 Luogu 第一篇题解，其图源官方题解）

现在求出左下角的状态即可。

先想递推。因为每次往右或往下走，可以按行从上到下，每一行从右到左转移。归纳一下即证每个点状态与它右斜上方的点状态相同。

有两个方向可走时不好做，只有一个方向可走时是好做的。沿着 经过左下角的往右上的对角线 走到 不能走为止 的上一步，此时一定只能往一个方向走，此时平凡。

前一步的转化是较为自然的，后面考虑一维的想法是有趣但自然的，而此性质的发现事实上也并不困难。意外发现了学长退役前写的题解，扫清了一个思维障碍 orz

```cpp
// agc002E
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int M = 1e5 + 10;
int a[M], n; bool sg[M][2];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    int p = 1;
    for(int i = 1; i <= n; i++) if(a[i] >= i) p = i;
    bool f1 = (a[p] - p + 1) % 2 == 0;
    int k = p; while(a[k+1] >= p && k+1 <= n) ++k;
    bool f2 = (k - p) % 2 == 1;
    if(f1 || f2) puts("First");
    else puts("Second");
}
```