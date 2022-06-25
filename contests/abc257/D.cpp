#include <cstdio>
#include <queue>
#include <cmath>
#define int long long
#define LL long long
#define inf 2000000000000000000
using namespace std;
const int M = 205;
int x[M], y[M], p[M], n, ans; bool vis[M];
queue<int> q;
long long dis(int u, int v){
    return abs(x[u] - x[v]) + abs(y[u] - y[v]);
}
bool check(int s, LL t){
    for(int i = 1; i <= n; i++) vis[i] = 0;
    q.push(s); vis[s] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 1; v <= n; v++){
            if(!vis[v] && dis(u, v) <= p[u] * t)
                q.push(v), vis[v] = 1;
        }
        vis[u] = 1;
    }
    // dprintf("\n");
    for(int i = 1; i <= n; i++) if(!vis[i]) return 0;
    return 1;
}
bool check(LL t){
    for(int i = 1; i <= n; i++)
        if(check(i, t)) return 1;
    return 0;
}
signed main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld %lld %lld", &x[i], &y[i], &p[i]);
    LL l = 1, r = 4e9;
    while(l <= r){
        LL mid = l + r >> 1;
        if(check(mid)) r = mid-1, ans = mid;
        else l = mid+1;
    }
    printf("%lld\n", ans);
}