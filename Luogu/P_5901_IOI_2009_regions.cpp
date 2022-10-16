#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int M = 200005;
struct tp{
    int id, j;
};
vector<tp> qy1[M], qy2[M];
struct edge{
    int to, nxt;
}e[M];
int head[M], cnt1;
void link(int u, int v){
    e[++cnt1] = {v, head[u]}; head[u] = cnt1;
}
int n, r, q, col[M], ans[M], cnt[M]; vector<int> bl[M];
map<pair<int, int>, int> k;
void dfs1(int u){
    for(tp t : qy1[col[u]]) ans[t.id] += cnt[t.j];
    ++cnt[col[u]];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs1(v);
    }
    --cnt[col[u]];
}
void dfs2(int u){
    ++cnt[col[u]];
    for(tp t : qy2[col[u]]) ans[t.id] -= cnt[t.j];
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to; dfs2(v);
    }
    for(tp t : qy2[col[u]]) ans[t.id] += cnt[t.j];
}
int main(){
    scanf("%d %d %d", &n, &r, &q);
    scanf("%d", &col[1]);
    for(int i = 2; i <= n; i++) {
        int fa;
        scanf("%d %d", &fa, &col[i]);
        link(fa, i);
    }
    // int T = sqrt(n);
    for(int i = 1; i <= q; i++){
        int r1, r2; scanf("%d %d", &r1, &r2);
        if(k[make_pair(r1, r2)]) {ans[i] = -k[make_pair(r1, r2)]; continue;}
        if(bl[r1].size() < bl[r2].size()){
            qy2[r1].push_back({i, r2});
        } else {
            qy1[r2].push_back({i, r1});
        }
    }
    dfs1(1); dfs2(1);
    for(int i = 1; i <= q; i++) printf("%d\n", ans[i] > 0 ? ans[i] : ans[-ans[i]]);
}