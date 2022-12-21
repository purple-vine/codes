#include <cstdio>
using namespace std;
const int M = 1e5 + 5;
int fa[M], n, m;
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
    u = find(u); v = find(v); if(u != v) fa[u] = v;
}
int k = 0;
int qpow(int a, int b, int p){
    int ans = 1ll;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
    return ans;
}
int s[M], p;
int main() {
    scanf("%d %d %d", &n, &m, &p);
    if(n == 1) return printf("%d\n", 1 % p), 0;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        merge(u, v);
    } 
    for(int i = 1; i <= n; i++) ++s[find(i)];
    for(int i = 1; i <= n; i++) k += s[i] != 0;
    if(k == 1) return printf("%d\n", 1 % p), 0;
    int ans = qpow(n, k-2, p);
    for(int i = 1; i <= n; i++) if(s[i]) ans = 1ll * ans * s[i] % p;
    printf("%d\n", ans);
}