#include <cstdio>
#include <vector>
using namespace std;
const int M = 1e5 + 5, mod = 998244353;
int fa[M], n, sm[M], ans, siz[M], ec[M];
void init(int n) {
    for(int i = 1; i <= n; i++)
        fa[i] = i, sm[i] = 0, siz[i] = 1, ec[i] = 0;
}
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u != v) fa[u] = v, sm[v] += sm[u], siz[v] += siz[u];
}
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        vector<int> a(n), b(n);
        init(n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &b[i]);
        int cnt = 0, cnt2 = 0; 
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) ++cnt, sm[a[i]] = 1;
        }
        for(int i = 0; i < n; i++) merge(a[i], b[i]);
        for(int i = 0; i < n; i++) {
            ++ec[find(a[i])];
        } 
        int ans = 1;
        for(int i = 1; i <= n; i++) {
            if(fa[i] != i) continue;
            if(ec[i] != siz[i]) ans = 0;
            else if(sm[i] > 0) ans = 1ll * ans * n % mod;
            else ans = 1ll * ans * 2 % mod;
        }
        printf("%d\n", ans);
    }
}