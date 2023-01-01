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
    // printf("s=%d\n", s[u]);
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