#include <cstdio>
#include <algorithm>
#define ls(p) (sl[p] ? sl[p] : sl[p] = build())
#define rs(p) (sr[p] ? sr[p] : sr[p] = build())
using namespace std;
const int M = 200005;
int s[M * 20], rt[M], cnt, sr[M * 20], sl[M * 20];
int build() {return ++cnt;}
inline void pushup(int x) {s[x] = s[sl[x]] + s[sr[x]];}
int build0(int l, int r){
    if(l == r) {return build();}
    int mid = l + r >> 1, x = build();
    sl[x] = build0(l, mid); sr[x] = build0(mid+1, r);
    pushup(x);
    return x;
}
void upd(int p, int q, int l, int r, int x, int t){
    if(l == r) {s[q] = s[p] + t; return;}
    int mid = l + r >> 1; sl[q] = sl[p]; sr[q] = sr[p];
    if(x <= mid) upd(sl[p], sl[q] = build(), l, mid, x, t);
    else upd(sr[p], sr[q] = build(), mid+1, r, x, t);
    pushup(q);
}
int n, m, a[M], b[M], pl[M], tmp[M];
int query(int p, int l, int r, int k){
    if(k > s[p]) return n+1;
    // printf("p=%d l=%d r=%d k=%d\n", p, l, r, k);
    if(l == r) return l;
    int mid = l + r >> 1;
    if(s[sl[p]] >= k) return query(sl[p], l, mid, k);
    else return query(sr[p], mid+1, r, k - s[sl[p]]);
}
int main(){
    // freopen("1.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    rt[n+1] = build0(1, n);
    for(int i = n; i >= 1; i--){
        if(pl[a[i]]) upd(rt[i+1], tmp[i] = build(), 1, n, pl[a[i]], -1);
        pl[a[i]] = i;
        upd(tmp[i] ? tmp[i] : rt[i+1], rt[i] = build(), 1, n, i, 1);
    }
    // for(int i = 1; i <= cnt; i++) printf("%d val=%d sl=%d sr=%d\n", i, s[i], sl[i], sr[i]);
    for(int i = 1; i <= n; i++){
        int pl = 1, cnt = 0;
        while(pl < n){
            pl = query(rt[pl], 1, n, i+1); ++cnt; 
            // printf("%d ", pl);
        }
        if(pl == n+1) --cnt;
        printf("%d ", cnt + 1);
        // printf("\n");
    }
}