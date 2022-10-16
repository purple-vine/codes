#include <cstdio>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
const int M = 200005;
int n, m;
priority_queue<int> laz[M << 2]; int s[M << 2];
void pushup(int o){
    s[o] = max(s[o<<1], s[o<<1|1]);
    if(laz[o].size()) s[o] = max(s[o], laz[o].top());
}
void modifyadd(int o, int l, int r, int x, int y, int t){
    if(l > r) return;
    if(x <= l && r <= y) {laz[o].push(t); s[o] = max(s[o], t); return;}
    int mid = l + r >> 1;
    if(x <= mid) modifyadd(o<<1, l, mid, x, y, t);
    if(y > mid) modifyadd(o<<1|1, mid+1, r, x, y, t);
    pushup(o);
}
int query(int o, int l, int r, int x, int y){
    // printf("o=%d l=%d r=%d\n", o, l, r);
    if(x <= l && r <= y) return s[o];
    int mid = l + r >> 1, ans = laz[o].size() ? laz[o].top() : -1;
    if(x <= mid) ans = max(ans, query(o<<1, l, mid, x, y));
    if(y > mid) ans = max(ans, query(o<<1|1, mid+1, r, x, y));
    return ans;
}
void modifyminus(int o, int l, int r, int x, int y, int t){
    if(s[o] < t) return;
	// printf("o=%d l=%d r=%d\n", o, l, r);
    if(laz[o].size() && laz[o].top() == t) {
        // printf("roll %d with %d\n", t, o);
        laz[o].pop(); // printf("now top = %d\n", laz[o].top());
        if(y < r) modifyadd(o, l, r, y+1, r, t);
        if(l < x) modifyadd(o, l, r, l, x-1, t);
        if(l != r) pushup(o);
        else s[o] = laz[o].size() ? laz[o].top() : -1;
        return;
    }
    int mid = l + r >> 1; // pushdown(o, l, r);
    if(x <= mid) modifyminus(o<<1, l, mid, x, y, t);
    if(y > mid) modifyminus(o<<1|1, mid+1, r, x, y, t);
    pushup(o);
}
void debug(int o, int l, int r){
    printf("%d : l = %d  r = %d  s:%d  lazs:", o, l, r, s[o]);
    if(laz[o].size()) printf("%d", laz[o].top()); puts("");
    // for(int u : laz[o]) printf("%d ", u); printf("\n");
    if(l == r) return;
    int mid = l + r >> 1;
    debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 4*n; i++) s[i] = -1;
    while(m--){
        int op; scanf("%d", &op);
        if(op == 1){
            int l, r, k; scanf("%d %d %d", &l, &r, &k);
            modifyadd(1, 1, n, l, r, k);
        } else if(op == 3){
            int l, r; scanf("%d %d", &l, &r);
            // debug(1, 1, n);
            printf("%d\n", query(1, 1, n, l, r));
        } else {
            int l, r; scanf("%d %d", &l, &r);
            int k = query(1, 1, n, l, r);
            if(k == -1) continue;
            modifyminus(1, 1, n, l, r, k);
        }
    }
    return 0;
}