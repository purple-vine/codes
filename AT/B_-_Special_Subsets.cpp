//url : https://atcoder.jp/contests/arc114/tasks/arc114_b
#include <cstdio>
using namespace std;
const int M = 200005, mod = 998244353;
int fa[M], n, f[M], ans, t[M]; bool vis[M];
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v) {if((u = find(u)) != (v = find(v))) fa[u] = v;}
int main(){
    scanf("%d", &n); t[0] = 1;
    for(int i = 1; i <= n; i++) fa[i] = i, t[i] = 1ll * t[i-1] * 2 % mod;
    for(int i = 1; i <= n; i++) scanf("%d", &f[i]), merge(i, f[i]);
    for(int i = 1; i <= n; i++) ans += !vis[find(i)], vis[find(i)] = 1;
    printf("%d\n", t[ans] - 1);
}