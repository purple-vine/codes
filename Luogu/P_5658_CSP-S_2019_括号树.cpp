#include <cstdio>
#define LL long long
using namespace std;
const int M = 500005;
struct edge{
    int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n; bool op[M];
LL ans[M], tot, cur, count[M]; // 极长连续
void dfs(int u, int h){
    // printf("%d %d %d\n", u, h, cur);
    LL sav = cur, val = count[h+n];
    if(op[u] == 1) cur += count[h+n]++;
    else count[h+n] = 1ll;
    ans[u] = cur; tot ^= (1ll * u * ans[u]);
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs(v, h + (op[v] ? -1 : 1));
    }
    cur = sav; count[h+n] = val;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        char c; scanf(" %c", &c); op[i] = c == ')';
    }
    for(int i = 2; i <= n; i++){
        int f; scanf("%d", &f); link(f, i);
    }
    count[n] = 1;
    dfs(1, op[1] ? -1 : 1);
    // for(int i = 1; i <= n; i++) printf("%d-%d ", i, ans[i]);
    // printf("\n");
    printf("%lld\n", tot);
}