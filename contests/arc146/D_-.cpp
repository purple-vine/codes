#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int M = 100005;
struct tp {int p, i, q; };
vector<tp> e[M]; queue<int> q;
int n, m, k, d[M], f[M]; bool in[M];
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++){
        int j1, j2, p, q; scanf("%d %d %d %d", &p, &j1, &q, &j2);
        e[j1].push_back({p, j2, q}); e[j1].push_back({p-1, j2, q-1});
        e[j2].push_back({q, j2, p}); e[j2].push_back({q-1, j1, p-1});
    }
    for(int i = 1; i <= n; i++){
        e[0].push_back({0, i, 0});
        sort(e[i].begin(), e[i].end());
    }
    d[0] = 1; q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &[p, i, q] : e[u]){

        }
    }
}