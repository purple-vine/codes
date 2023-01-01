相当诈骗，然而赛时卡 D 没开。

题意有点长，懒得复述了。

[link to CF](https://codeforces.com/problemset/problem/1770/E) | [link to Luogu](https://www.luogu.com.cn/problem/CF1770E)

- $O(n^2)$ 枚举 $(u, v)$ 对一定不行，根据期望线性性，应当对每条边算其计入答案的期望次数。
- 把树变成有根树，对于 $(u, fa)$，如果 $u$ 子树内共有 $s_u$ 只蝴蝶，则这条边被经过 $s_u (k-s_u)$ 次。
- 考虑到每条边至多被蝴蝶经过一次，每个 $s_u$ 至多变化一次。
- 于是考虑实时维护 $\sum s_u (k-s_u)$ 的期望值。
- 处理到 $(u, fa)$ 时，设有蝴蝶从 $u \to v$ 的概率是 $q_{u,v}$，则 $q_{u, fa}$ 概率 $s_u \gets s_u-1$，另有 $q_{fa, u}$ 概率 $s_u \gets s_u+1$。
- 考虑把 $q$ 求出来。$q_{u,v}$ 成立需要 $v$ 处无蝴蝶、$u$ 处有蝴蝶、边定向为 $u \to v$。
- 实时维护 $p_u$ 表示 $u$ 点有蝴蝶的概率，则 $q_{u, v} = \frac{1}{2}(1-p_v) p_u$。
- 当处理 $(u, v)$ 时，$p_u, p_v \gets \frac{p_u+p_v}{2}$。
- 据此可 $O(1)$ 维护 $p$，即 $O(1)$ 维护 $q$，即 $O(1)$ 处理每条边对答案的贡献。所以做完了，复杂度 $O(n)$。

```cpp
#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 3e5 + 5, mod = 998244353;
int qpow(int a, int b){
    long long ans = 1ll;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
    return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int add(int a, int b) {a += b; return a >= mod ? a-mod : a;}
int del(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void addn(int &x, int y) {x += y; if(x >= mod) x -= mod;}
void deln(int &x, int y) {x -= y; if(x < 0) x += mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
void approx(int p, int q, int A) {
    int x = q, y = p, a = 1, b = 0;
    while (x > A) {
        swap(x, y); swap(a, b);
        a -= x / y * b;
        x %= y;
    }
    printf("%d/%d\n", x, a);
}
struct edge {
    int to, nxt;
} e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, p[M], pu[M], pv[M], s[M], dep[M], ans;
void dfs(int u, int fa) {
    s[u] = p[u]; dep[u] = dep[fa] + 1;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to; if(v == fa) continue;
        dfs(v, u);
        addn(s[u], s[v]); 
    }
    addn(ans, (1ll * s[u] * (m - s[u]) % mod + mod) % mod);
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int t; scanf("%d", &t);
        p[t] = 1;
    }
    for(int i = 1; i <= n-1; i++) {
        scanf("%d %d", &pu[i], &pv[i]);
        link(pu[i], pv[i]); link(pv[i], pu[i]);
    }
    dfs(1, 0); // printf("ans=%d\n", ans);
    // approx(mod, ans, 10);
    #define u pu[i]
    #define v pv[i]
    const int inv2 = inv(2);
    for(int i = 1; i <= n-1; i++) {
        if(dep[u] > dep[v]) swap(u, v);
        LL puv = 1ll * p[u] * (1 + mod - p[v]) % mod,
            pvu = 1ll * p[v] * (1 + mod - p[u]) % mod;
        LL tmp = 0;
        tmp -= 1ll * puv * s[v] % mod * (m - s[v]) % mod;
        tmp += 1ll * puv * (s[v]+1) % mod * (m - s[v] - 1) % mod;
        tmp -= 1ll * pvu * s[v] % mod * (m - s[v]) % mod;
        tmp += 1ll * pvu * (s[v]-1) % mod * (m - s[v] + 1) % mod;
        tmp += mod; tmp %= mod;
        p[u] = p[v] = 1ll * add(p[u], p[v]) * inv2 % mod;
        addn(ans, 1ll * tmp * inv2 % mod);
        ans += mod; ans %= mod;
        // printf("ans=%d\n", ans);
        // approx(mod, ans, 10);
    }
    printf("%d\n", 1ll * ans * inv(1ll * m * (m-1) / 2 % mod) % mod);
}
```