#include <cstdio>
#include <algorithm>
#define inf 998244353
using namespace std;
const int M = 5e4 + 5;
struct edge {
    int u, v, w, c;
} e[M];
int n, m, k;
int sum;
int fa[M];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int calc(int t) {
    int cnt = 0; sum = 0;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) if(e[i].c == 0) e[i].w += t;
    sort(e+1, e+m+1, [](edge a, edge b) -> bool {return a.w != b.w ? a.w < b.w : a.c < b.c;});
    for(int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        if((u = find(u)) != (v = find(v))) fa[u] = v, cnt += e[i].c == 0, sum += e[i].w;
    }
    for(int i = 1; i <= m; i++) if(e[i].c == 0) e[i].w -= t;
    // printf("%d : %d\n", t, cnt);
    return cnt;
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int u, v, w, c; scanf("%d %d %d %d", &u, &v, &w, &c);
        e[i] = {++u, ++v, w, c};
    }
    int l = -inf, r = inf, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(calc(mid) >= k) l = mid+1, ans = sum - k * mid;
        else r = mid-1; 
    }
    printf("%d\n", ans);
}