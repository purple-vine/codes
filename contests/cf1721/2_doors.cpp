#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
const int M = 200005;
int ans[M], n, m, l[M], r[M], x[M], tmp[M], id[M];
struct tp {int l, r, x; bool operator < (const tp &t) const {return l != t.l ? l < t.l : r < t.r;}} q[M];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].x);
        if(q[i].l > q[i].r) swap(q[i].l, q[i].r);
    }
    sort(q+1, q+m+1);
    for(int t = 0; t <= 31; t++){
        int val = 1 << t; memset(tmp, -1, sizeof(tmp));
        for(int i = 1; i <= m; i++){
            if(((q[i].x >> t) & 1) == 0) tmp[q[i].l] = tmp[q[i].r] = 0;
        }
        for(int i = 1; i <= m; i++){
            if(((q[i].x >> t) & 1) == 1){
                // if(q[i].l > q[i].r) swap(q[i].l, q[i].r);
                if(tmp[q[i].l] == 1 || tmp[q[i].r] == 1) continue;
                if(tmp[q[i].r] == -1) tmp[q[i].r] = 1;
                else tmp[q[i].l] = 1;
            }
        }
        // printf("%d: ", t);
        // for(int i = 1; i <= n; i++) printf("%d ", tmp[i]);
        // printf("\n");
        for(int i = 1; i <= n; i++) if(tmp[i] == 1) ans[i] |= (1 << t);
        for(int i = 1; i <= m; i++) assert(((tmp[q[i].l] == 1) | (tmp[q[i].r] == 1)) == (((q[i].x) >> t) & 1));
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}