//url : https://atcoder.jp/contests/abc235/tasks/abc235_e
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 400005;
struct edge{
    int u, v, w, num; bool stu;
    bool operator < (const edge &tmp) const {return w < tmp.w;}
}e[M];
int fa[M];
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u, int v){
	u = find(u); v = find(v); if(u != v) fa[u] = v;
}
int n, m, q, u, v, w, cnt; bool ans[M];
int main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) scanf("%d %d %d", &u, &v, &w), e[++cnt] = {u, v, w, 0, 0};
    for(int i = 1; i <= q; i++) scanf("%d %d %d", &u, &v, &w), e[++cnt] = {u, v, w, i, 1};
    sort(e+1, e+cnt+1);
    for(int i = 1; i <= cnt; i++){
        // printf("%d %d %d %d %d\n", e[i].u, e[i].v, e[i].w, e[i].stu, e[i].num);
        int u = e[i].u, v = e[i].v;
        if(e[i].stu == 0) merge(u, v);
        else if(find(u) != find(v)) ans[e[i].num] = 1;
    }
    for(int i = 1; i <= q; i++) printf("%s\n", ans[i] ? "Yes" : "No");
}