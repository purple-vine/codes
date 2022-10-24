#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int M = 200005, inf = __INT_MAX__;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, m, k, t[M];
namespace subtask1{
    vector<vector<int> > rout;
    int d[M]; struct tp{
        int u, d;
        bool operator < (const tp &t) const {return d > t.d;}
    };
    priority_queue<tp> q; bool vis[M];
    vector<int> sav; int cnt;
    void dfs(int u){
        sav.push_back(u);
        if(u == n) rout.push_back(sav);
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to;
            if(d[v] == d[u] + t[v]) dfs(v);
        }
        sav.pop_back();
    }
    bool sta[M];
    int main(){
        for(int i = 1; i <= n; i++) d[i] = inf;
        d[1] = t[1]; q.push({1, 0});
        while(!q.empty()){
            int u = q.top().u; q.pop();
            if(vis[u]) continue;
            for(int i = head[u]; i; i = e[i].nxt){
                int v = e[i].to;
                if(d[u] + t[v] < d[v]){
                    d[v] = d[u] + t[v]; q.push({v, d[v]});
                }
            }
        }
        dfs(1);
        // for(auto t : rout){
        //     for(auto b : t) printf("%d ", b);
        //     printf("\n");
        // }
        for(int l = 0; l < (1 << n); l++){
            if(__builtin_popcount(l) != k) continue;
            for(int i = 1; i <= n; i++) sta[i] = (l >> i-1) & 1;
            bool f = 1;
            for(auto t : rout){
                bool c = 0;
                for(int i = 0; i < t.size()-1; i++)
                    c |= (sta[t[i]] == sta[t[i+1]]);
                f &= c;
            }
            if(f) {for(int i = 1; i <= n; i++) printf("%c", sta[i] ? 'U' : 'P'); return 0;}
        }
        printf("impossible\n"); return 0;
    }
}
namespace subtask2{
    int main(){
        return 0;
    }
}
namespace subtask3{
    bool cl[M], cr[M];
    bool ans[M];
    int main(){
        for(int i = head[1]; i; i = e[i].nxt){
            cl[e[i].to] = 1;
        }
        for(int i = head[n]; i; i = e[i].nxt){
            cr[e[i].to] = 1;
        }
        if(cr[n]) {
            if(k >= 2) {
                printf("U");
                for(int i = 1; i <= k-2; i++) putchar('U');
                for(int i = 1; i <= n-k; i++) putchar('P');
                printf("U");
            } else {
                k = n - k;
                printf("P");
                for(int i = 1; i <= k-2; i++) putchar('P');
                for(int i = 1; i <= n-k; i++) putchar('U');
                printf("P");
            }
            return 0;
        }
        int mx = -1, cnt = 0;
        for(int i = 2; i <= n-1; i++) mx = max(mx, t[i]);
        for(int i = 2; i <= n-1; i++){
            if(t[i] == mx) ++cnt;
        }
        // if(max(k, n-k) < cnt + 1) {printf("impossible\n"); return 0;}
        bool ttt = 0; if(k < n-k) k = n-k, ttt = 1;
        k -= cnt+1; ans[1] = 1;
        for(int i = 1; i < k; i++){
            ans[i] = 1;
        }
        for(int i = k; i <= n; i++) ans[i] = 0;
        for(int i = 1; i <= n; i++) printf("%c", ans[i] ^ ttt ? 'U' : 'P');
        return 0;
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
    bool sub1 = 1, sub2 = 1, sub3 = 1;
    if(k != 1) sub2 = 0;
    if(n > 15) sub1 = 0;
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
        if(!((u == 1 || u == n) || (v == 1 || v == n))) sub3 = 0;
    }
    if(sub1) return subtask1::main();
    if(sub2) return subtask2::main();
    if(sub3) return subtask3::main();
}