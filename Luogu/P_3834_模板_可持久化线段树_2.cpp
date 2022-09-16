#include <cstdio>
#include <algorithm>
#define ls(p) (sl[p] ? sl[p] : sl[p] = build())
#define rs(p) (sr[p] ? sr[p] : sr[p] = build())
using namespace std;
const int M = 200005;
int s[M * 20], rt[M], cnt, sr[M], sl[M];
int build() {return ++cnt;}
inline void pushup(int x) {s[x] = s[sl[x]] + s[sr[x]];}
int build0(int l, int r){
    if(l == r) {return build();}
    int mid = l + r >> 1, x = build();
    sl[x] = build0(l, mid); sr[x] = build0(mid+1, r);
    pushup(x);
    return x;
}
void upd(int p, int q, int l, int r, int x){
    if(l == r) {s[q] = s[p] + 1; return;}
    int mid = l + r >> 1;
    sl[q] = sl[p]; sr[q] = sr[p];
    if(x <= mid) upd(sl[p], sl[q] = build(), l, mid, x);
    else upd(sr[p], sr[q] = build(), mid+1, r, x);
    pushup(q);
}
int query(int p, int q, int l, int r, int k){
    // printf("p=%d q=%d l=%d r=%d k=%d\n", p, q, l, r, k);
    if(l == r) return l;
    int mid = l + r >> 1;
    if(s[sl[q]] - s[sl[p]] >= k) return query(sl[p], sl[q], l, mid, k);
    else return query(sr[p], sr[q], mid+1, r, k - (s[sl[q]] - s[sl[p]]));
}
int n, m, a[M], b[M];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b+1, b+n+1); int n1 = unique(b+1, b+n+1) - b - 1;
    for(int i = 1; i <= n; i++) a[i] = lower_bound(b+1, b+n1+1, a[i]) - b;
    rt[0] = build0(1, n);
    for(int i = 1; i <= n; i++) upd(rt[i-1], rt[i] = build(), 1, n, a[i]);
    // for(int i = 1; i <= cnt; i++) printf("%d val=%d sl=%d sr=%d\n", i, s[i], sl[i], sr[i]);
    while(m--){
        int l, r, k; scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", b[query(rt[l-1], rt[r], 1, n, k)]);
    }
}