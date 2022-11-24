NOIp 前随机一道题来补。

[link to Luogu](https://www.luogu.com.cn/problem/P4284)

NOIp2022 rp++

题意：

> 给定一棵树，每个点 $p_i$ 概率被直接激活，每条边 $p_{\{u,v\}}$ 概率被激活，被激活的点可以顺着被激活的边激活其它点，求所有点被激活的概率和。
> 
> $n \leq 5 \cdot 10^5$，保留小数输出。

这种树上题也只能是树形 dp 了，现在思考怎么计算这个贡献。

一个点能通过三种方式被激活：自己本身已被激活、通过子节点被激活、通过被激活的父节点被激活。

设一个点被激活的概率是 $q_i$，则它被直接激活的概率是 $p_i$，被子节点激活的概率容易通过递推算出，具体转移为 $q_u \gets q_v \ (1-q'_u) \ p_{\{u,v\}}$。

现在来看通过父节点被激活，那么首先要从父节点中去除 $u$ 可能的贡献。

已知 $q_{fa} = q'_{fa} + q_u \ (1-q'_{fa}) \ p_{\{u,v\}}$，则可以解出 $q'_{fa} = \dfrac{q_{fa}-q_u p_{\{u,v\}}}{1-q_u p_{\{u,v\}}}$。这就是父节点被激活且不通过 $u$ 的概率。用这个概率进行像上一个转移一样的转移即可。

拜谢 [第二篇题解](https://www.luogu.com.cn/blog/partychicken/solution-p4284)，思路讲得挺顺畅的，也给出了一个比第一篇题解好理解的去当前节点父节点概率的算法。

补完了。rp++;

其实感觉真不是特别难，最多概率的运算难一些，但是每一步都很自然。而且这个背景真心不错，百分数也很贴合实际。

学到了 up and down 的技巧，很开心！

是不是要说一下那句老话：

题出的好！难度适中，覆盖知识点广，题目又着切合实际的背景，解法比较自然。<del>给出题人点赞！</del>

```cpp
#include <cstdio>
#include <cmath>
using namespace std;
const int M = 5e5 + 5;
struct edge{
    int to, nxt, w;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v, int w){
    e[++cnt1] = {v, head[u], w}; head[u] = cnt1;
}
int n, p[M]; double q[M], ans[M];
void dfs1(int u, int fa) {
    q[u] = p[u] / 100.0;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to; if(v == fa) continue; dfs1(v, u);
        q[u] += q[v] * (1 - q[u]) * e[i].w / 100.0;
    }
}
void dfs2(int u, int fa) {
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to, w = e[i].w;
        if(v == fa) continue;
        if(fabs(1 - q[v] * w / 100.0) < 1e-8) {dfs2(v, u); continue;}
        double tmp = (q[u] - (q[v] * w / 100.0)) / (1 - (q[v] * w / 100.0));
        q[v] += tmp * (1 - q[v]) * w / 100.0;
        dfs2(v, u);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        link(u, v, w); link(v, u, w);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    dfs1(1, 0);
    dfs2(1, 0);
    double tot = 0; 
    for(int i = 1; i <= n; i++) tot += q[i];
    printf("%.6lf\n", tot);
    return 0;
}
```