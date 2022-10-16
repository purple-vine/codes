这道题的难点，恐怕在复杂度分析（

[link](https://luogu.com.cn/problem/P5901)

首先我们可以自由选择把询问放到上面或下面。放到上面，等价于对每个点求其子树内有多少某颜色的点；放到下面，等价于对每个点求其祖先中有多少某颜色的点。这种有可减性的针对子树或祖先的信息，可以利用差分离线一遍 dfs 一起统计。

那么明显，如果上面点少就挂到上面，否则挂到下面。现在对复杂度做分析。

称出现次数多于 $\sqrt n$ 的为“重颜色”，否则为“轻颜色”，则重颜色不超过 $\sqrt n$ 种。

1. 上面是重颜色，下面也是重颜色

不妨上面点数少于下面，则只有 $\sqrt n$ 种不同的 $r2$，上面最多覆盖 $n$ 个点，故总共最多拆出 $n \sqrt n$ 个询问。

2. 上面是重颜色，下面是轻颜色

上面的重颜色最多 $\sqrt n$ 种，所以每个点最多挂上 $\sqrt n$  种这种询问，总共最多 $n \sqrt n$ 个询问。

3. 上面是轻颜色，下面是重颜色

同上

4. 上面是轻颜色，下面也是轻颜色

一次操作最多给 $\sqrt n$ 个点挂询问，所以最多 $n \sqrt n$ 个询问。

我们可以均摊 $O(1)$ 回复每个小询问，所以总复杂度 $n \sqrt n$。

```cpp
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int M = 200005;
struct tp{
    int id, j;
};
vector<tp> qy1[M], qy2[M];
struct edge{
    int to, nxt;
}e[M];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, r, q, col[M], ans[M], cnt[M]; vector<int> bl[M];
map<pair<int, int>, int> k;
void dfs1(int u){
    for(tp t : qy1[col[u]]) ans[t.id] += cnt[t.j];
    ++cnt[col[u]];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs1(v);
    }
    --cnt[col[u]];
}
void dfs2(int u){
    ++cnt[col[u]];
    for(tp t : qy2[col[u]]) ans[t.id] -= cnt[t.j];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs2(v);
    }
    for(tp t : qy2[col[u]]) ans[t.id] += cnt[t.j];
}
int main(){
    scanf("%d %d %d", &n, &r, &q);
    scanf("%d", &col[1]);
    for(int i = 2; i <= n; i++) {
        int fa;
        scanf("%d %d", &fa, &col[i]);
        link(fa, i);
    }
    // int T = sqrt(n);
    for(int i = 1; i <= q; i++){
        int r1, r2; scanf("%d %d", &r1, &r2);
        if(k[make_pair(r1, r2)]) {ans[i] = -k[make_pair(r1, r2)]; continue;}
        if(bl[r1].size() < bl[r2].size()){
            qy2[r1].push_back({i, r2});
        } else {
            qy1[r2].push_back({i, r1});
        }
    }
    dfs1(1); dfs2(1);
    for(int i = 1; i <= q; i++) printf("%d\n", ans[i] > 0 ? ans[i] : ans[-ans[i]]);
}
```