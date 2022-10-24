#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 3005;
struct point{
    int x, y;
    bool operator < (const point &t) const {return min(x, y) < min(t.x, t.y);}
} p[M];
int dis(point a, point b){
    return max(abs(b.x - a.x), abs(b.y - a.y));
}
/*
let us see all pair of points and sort them by their chebyshev distance
i think we can find out a way using the pair of points the smallest distance belongs to
is that right? plzz i need rp!
*/
struct tp{
    int x, y, dis;
    bool operator  < (const tp &t) const {
        return dis ^ t.dis ? dis < t.dis : x ^ t.x ? p[x] < p[t.x] : p[y] < p[t.y];
    }
} t[M * M];
bool vis[M];
void work(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &p[i].x, &p[i].y);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int x = i, y = j;
            if(p[y] < p[x])  swap(x, y);
            t[++cnt] = {x, y, dis(p[x], p[y])};
        }
    }
    sort(t+1, t+cnt+1);
    printf("Yes\n");
    for(int i = 1; i <= cnt; i++){
        int x = t[i].x, y = t[i].y, dis = t[i].dis; if(vis[x] || vis[y]) continue;
        vis[x] = vis[y] = 1;
        // printf("%d %d\n", x, y);
        point a = p[x], b = p[y];
        printf("%d %d %d %d\n", max(b.x, a.x), max(b.y, a.y), max(b.x, a.x)-dis, max(b.y, a.y) - dis);
    }
    // memset(t, 0, sizeof(t)); memset(p, 0, sizeof(p));
    memset(vis, 0, sizeof(vis));
}
int main(){
    // freopen("ex_stone4.in", "r", stdin);
    // freopen("stone.out", "w", stdout);
    int T; scanf("%d", &T);
    while(T--) work();
}