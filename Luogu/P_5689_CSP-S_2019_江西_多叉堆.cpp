#include <cstdio>
using namespace std;
const int M = 300015, mod = 1000000007;
void add(int &x, int y) {if((x += y) >= mod) x -= mod;}
int addn(int x, int y) {return (x += y) >= mod ? x-mod : x;}
int qpow(int a, int b){
    int ans = 1;
    for(; ; b >>= 1) {if(b & 1) ans = 1ll * a * ans % mod; a = 1ll * a * a %  mod;}
    return ans;
}
int invn[M], fac[M], invfac[M];
void pre(int n) {
    invn[0] = fac[0] = invfac[0] = invn[1] = fac[1] = invfac[1] = 1;
    for(int i = 2; i <= n; i++) {
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod;
        fac[i] = 1ll * fac[i-1] * i % mod;
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
    }
}
int n, q, fa[M], lans, ans[M], siz[M];
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
    // printf("%d %d\n", u, v);
    // printf("%d %d %d %d\n", ans[u], ans[v], siz[u], siz[v]);
    fa[v] = u; // siz[u] += siz[v];
    // printf("* %d / %d * %d * %d / %d\n", ans[u], fac[siz[u]-1], fac[siz[u] + siz[v] - 1], ans[v], fac[siz[v]]);
    // printf("%d %d %d %d %d\n", ans[u], invfac[siz[u] - 1], fac[siz[u] + siz[v] - 1], ans[v], invfac[siz[v]]);
    ans[u] = 
    1ll * ans[u] 
        * invfac[siz[u] - 1] % mod 
        * fac[siz[u] + siz[v] - 1] % mod
        * ans[v] % mod
        * invfac[siz[v]] % mod;
    siz[u] += siz[v];
    // printf("ans[%d] = %d\n", u, ans[u]);
}
int main(){
    scanf("%d %d", &n, &q); pre(300000);
    for(int i = 1; i <= n; i++) fa[i] = i, ans[i] = 1, siz[i] = 1;
    while(q--) {
        int op; scanf("%d", &op);
        if(op == 2) {
            int x; scanf("%d", &x); x = (x + lans) % n + 1;
            printf("%d\n", lans = ans[find(x)]);
        } else {
            int x, y; scanf("%d %d", &x, &y);
            x = (x + lans) % n + 1; y = (y + lans) % n + 1;
            merge(find(y), find(x));
        }
    }
}