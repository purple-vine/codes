#include <cstdio>
#include <set>
#include <algorithm>
#ifdef LOCAL
#define log(fmt...) fprintf(stderr, fmt)
#else
#define log(...) 0
#endif

#define debug(fmt...) \
log("[%s] - %d: ", __PRETTY_FUNCTION__, __LINE__), log(fmt)
using namespace std;
const int M = 200005;
int n, k, Ans[M];
struct tp {
    int t, m, id;
    bool operator < (const tp &tmp) const {
        return t < tmp.t;
    }
} g[M], r[M]; //guests, rooms
bool cmp (tp a, tp b) {
    return a.m > b.m;
}
set<tp> s;
int main(){
    // freopen("room1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d %d", &r[i].t, &r[i].m);
    for(int i = 1; i <= k; i++) scanf("%d %d", &g[i].t, &g[i].m), g[i].id = i;
    sort(r+1, r+n+1, cmp); sort(g+1, g+k+1, cmp);
    int p = 1;
    for(int i = 1; i <= k; i++) {
        int t = g[i].t, m = g[i].m, id = g[i].id;
        int ansl = -1, ansr = -1, ans = -1;
        while(r[p].m >= m) s.insert(r[p++]);
        // printf("t=%d m=%d id=%d\n", t, m, id);
        // for(auto i : s) printf("%d-%d ", i.t, i.m);
        // printf("\n");
        auto L = s.lower_bound(g[i]);
        if(L != s.begin()) --L;
        if(L != s.end() && L -> t <= t) ansl = L -> t;
        // printf("L%d %d\n", L -> m, L->t);
        auto R = s.lower_bound(g[i]);
        // printf("R%d %d\n", R -> m, R->t);
        if(R != s.end()) ansr = R -> t;
        // printf("ansl=%d ansr=%d\n", ansl, ansr);
        if(ansl == -1) ans = ansr;
        else if(ansr == -1) ans = ansl;
        else {
            if(ansr - t == t - ansl) ans = ansl;
            else if(ansr - t < t - ansl) ans = ansr;
            else ans = ansl;
        }
        Ans[id] = ans;
    }
    for(int i = 1; i <= k; i++) printf("%d ", Ans[i]);
}