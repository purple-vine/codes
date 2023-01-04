#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500005, M = 5000005;
struct edge {
    int u, v;
} e[M << 1];
int fa[M], n, k, ans, a[M], rk[M], m;
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
	u = find(u); v = find(v); if(u != v) fa[u] = v;
}
bool judge(int u, int v) {return find(u) == find(v);}
void solve(int x, int y) {
    // printf("! %d %d\n", x, y);
    merge(x+m, y); merge(x, y+m);
}
int main(){
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            e[i] = {u, v};
        }
        for(int i = 1; i <= 2*m; i++) fa[i] = i;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]), rk[a[i]] = i;
        for(int i = 1; i <= m; i++) {
            e[i].u = rk[e[i].u], e[i].v = rk[e[i].v];
            if(e[i].u > e[i].v) swap(e[i].u, e[i].v);
        }
        if(m > 3 * n - 6) {printf("NO\n"); continue;}
        for(int i = 1; i <= m; i++) {
            int u1 = e[i].u, v1 = e[i].v;
            if(v1 == u1 + 1 || (u1 == 1 && v1 == n)) continue;
            for(int j = i+1; j <= m; j++) {
                int u2 = e[j].u, v2 = e[j].v;
                if(v2 == u2 + 1 || (u2 == 1 && v2 == n)) continue;
                if((u1 < v2 && v2 < v1) ^ (u1 < u2 && u2 < v1)) 
                    solve(i, j);
            }
        }
        bool f = 1;
        for(int i = 1; i <= m; i++) if(find(i) == find(i+m)) {printf("NO\n"), f = 0; break;}
        if(f) printf("YES\n");
    }
}