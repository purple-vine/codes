#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
const int M = 500005;
vector<int> e[M]; int n, w[M], b[M], m, k, cnt[M];
struct tp{
    int u, val; bool operator < (const tp &t) const {return val > t.val;}
    operator int() const {return u;}
};
bool vis[M]; priority_queue<tp> q;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d %d", &u, &v);
        e[u].push_back(v); e[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= k; i++) scanf("%d", &b[i]);
    for(int i = 1; i <= n; i++) cnt[i] = k+1;
    cnt[1] = (b[1] == w[1]);
    q.push({1, cnt[1]});
    while(!q.empty()){
        int u = q.top(); q.pop(); if(vis[u]) continue; vis[u] = 1;
        // printf("%d %d\n", u, cnt[u]);
        for(int v : e[u]){
            // if(vis[v]) continue;
            if(cnt[v] > cnt[u] + (b[cnt[u] + 1] == w[v])){
                cnt[v] = cnt[u] + (b[cnt[u] + 1] == w[v]);
                q.push({v, cnt[v]});
            }
        }
        // printf("%d %d\n", u, cnt[u]);
    }
    printf("%s\n", cnt[n] == k ? "Yes" : "No");
}