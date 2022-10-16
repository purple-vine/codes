#include <cstdio>
using namespace std;
const int M = 100005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, col[M], rt, cnt[M], pl, mx; long long ans[M], tot;
int siz[M], son[M];
void dfs1(int u, int f){
    siz[u] = 1; son[u] = -1;
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        dfs1(v, u); siz[u] += siz[v]; 
        if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
}
void clear(int u, int f){
    --cnt[col[u]];
    for(int i = head[u]; i; i = e[i].nxt) if(f != e[i].to) clear(e[i].to, u);
}
void add(int p){
    ++cnt[p];
    if(cnt[p] > mx) tot = p, mx = cnt[p];
    else if(cnt[p] == mx) tot += p;
}
void dfs(int u, int f){
    add(col[u]);
    for(int i = head[u]; i; i = e[i].nxt){
        if(e[i].to != f) dfs(e[i].to, u);
    }
}
void solve(int u, int f){
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v == f) continue;
        if(v != son[u]){
            solve(v, u); clear(v, u); pl = mx = 0;
        }
    }
    if(son[u] != -1) solve(son[u], u);
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; if(v != f && v != son[u]) dfs(v, u);
    }
    add(col[u]); ans[u] = tot;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &col[i]);
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d %d", &u, &v);
        link(u, v); link(v, u);
    }
    dfs1(1, 0); solve(1, 0);
    for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
}