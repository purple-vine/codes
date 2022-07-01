题意：给定 $2n$ 个点和 $(u_1,v_1),\cdots,(u_m,v_m)$，选择让 $u_i$ 连 $v_i+n$ 或 $v_i$ 连 $u_i+n$，以最小化图中桥的个数。

有种技巧叫拆点，把一个点拆成入点和出点，看这个形式非常像拆点，于是先想想合并。

若有 $n$ 个点，连上所有 $u_i$ 和 $v_i$，是桥的边在原图中只能是桥（路径唯一），抛出结论：可以通过构造，让其他边均不是桥。

如果现在在看一个连通块，只需要通过把边重定向以使得这一块强连通，即可。

考虑去掉那些桥后一个一个连通块处理：顺着 dfs 树走下去，遇到返祖边向上定向，否则向下定向，即得。

以前听说过拆点这个想法，但这是第一次见到，甚至连可以合并两个点都没想到，只能说是发散思维的极大不足了。确实想到了某种 $i$ 与 $i+n$ 间奇怪的对应关系，但“桥”导致往 tarjan 上想，这是复杂化了问题。

```cpp
#include <cstdio>
using namespace std;
const int M = 5000005;
struct edge{
    int to, nxt;
}e[M];
int head[M], cnt1 = 1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, a[M], b[M], dir[M]; bool vis[M], vis1[M];
void dfs(int u, int f){
    if(vis1[u]) return; vis1[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt){
        // printf("u=%d i=%d\n", u, i);
        int v = e[i].to; if((i ^ 1) == f || vis[i]) continue;
        vis[i^1] = vis[i] = 1; dir[i] = 1; dir[i^1] = 0; dfs(v, i);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= m; i++) link(a[i], b[i]), link(b[i], a[i]);
    for(int i = 1; i <= n; i++) if(!vis1[i]) dfs(i, 0);
    for(int i = 1; i <= m; i++){
        printf("%d", dir[i << 1]);
    }
}
```