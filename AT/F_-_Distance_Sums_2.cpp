//time : 2022-07-14 15:19
//problem url : https://atcoder.jp/contests/abc220/tasks/abc220_f
//status : not submitted
//source : atc problems recommendation
#include <cstdio>
#define LL long long
using namespace std;
const int M = 200005;
LL ans[M]; int n, u, v;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1, dep[M], siz[M];
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
void dfs1(int u, int fa){
    ans[1] += dep[u]; siz[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        dep[v] = dep[u] + 1; dfs1(v, u); siz[u] += siz[v];
    }
}
void dfs2(int u, int fa){
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == fa) continue;
        ans[v] = ans[u] + n - 2 * siz[v]; dfs2(v, u);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v); link(u, v); link(v, u);
    }
    dfs1(1, 0); dfs2(1, 0);
    for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
}