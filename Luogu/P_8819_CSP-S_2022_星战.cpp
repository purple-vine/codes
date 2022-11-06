#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <random>
#include <vector>
#define LL long long
using namespace std;
const int M = 500005;
// struct edge{
//     int to, nxt;
// }e[M << 1];
// int head[M], cnt1;
// void link(int u, int v){
//     e[++cnt1] = {v, head[u]}; head[u] = cnt1;
// }
vector<int> e[M];
int n, m, deg[M]; bool vis[M];
struct judger {
    default_random_engine rnd;
    LL val[M], sum[M], cur, tot[M], all;
    void init(unsigned long long seed) {
        rnd.seed(seed); 
        for(int i = 1; i <= n; i++) val[i] = (int)rnd();
        for(int i = 1; i <= n; i++) {
            for(int j : e[i]) tot[i] += val[j];
            sum[i] = tot[i]; cur += sum[i];
            all += val[i];
        }
    }
    void op1(int u, int v) {
        cur -= val[v]; sum[u] -= val[v];
    }
    void op2(int u) {
        cur -= sum[u]; sum[u] = 0;
    }
    void op3(int u, int v) {
        cur += val[v]; sum[u] += val[v];
    }
    void op4(int u) {
        cur -= sum[u]; sum[u] = tot[u]; cur += sum[u];
    }
    bool judge() {
        return all == cur;
    }
} s[35];
int k = 1;
bool judge() {
    for(int i = 1; i <= 30; i++) if(!s[i].judge()) return 0;
    return 1;
}
int main(){
    default_random_engine c(34444);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &v, &u);
        e[u].push_back(v);
    }
    int T; scanf("%d", &T);
    for(int i = 1; i <= k; i++) s[i].init(c());
    while(T--) {
        int op; scanf("%d", &op);
        if(op == 1) {
            int u, v; scanf("%d %d", &v, &u);
            for(int i = 1; i <= k; i++) s[i].op1(u, v);
        } else if(op == 2) {
            int u; scanf("%d", &u);
            for(int i = 1; i <= k; i++) s[i].op2(u);
        } else if(op == 3) {
            int u, v; scanf("%d %d", &v, &u);
            for(int i = 1; i <= k; i++) s[i].op3(u, v);
        } else {
            int u; scanf("%d", &u);
            for(int i = 1; i <= k; i++) s[i].op4(u);
        }
        if(judge()) printf("YES\n");
        else printf("NO\n");
    }
}