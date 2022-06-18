//time : 2022-06-02 21:41
//problem id : SP2713
//status : TLE
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
const int M = 100005;
int a[M], n, op, l, r, m; LL s[M << 2]; bool tg[M << 2];
void build(int o, int l, int r){
    if(l == r) {s[o] = a[l]; tg[o] = (s[o] == 1 || !s[o]); return;}
    int mid = l + r >> 1;
    build(o<<1, l, mid); build(o<<1|1, mid+1, r);
    s[o] = s[o<<1] + s[o<<1|1]; tg[o] = tg[o<<1] & tg[o<<1|1];
}
void modify(int o, int l, int r, int x, int y){
    if(tg[o]) return;
    if(l == r) {s[o] = sqrt(s[o]); tg[o] = (s[o] == 1 || !s[o]); return;}
    int mid = l + r >> 1;
    if(x <= mid) modify(o<<1, l, mid, x, y);
    if(y > mid) modify(o<<1|1, mid+1, r, x, y);
    s[o] = s[o<<1] + s[o<<1|1]; tg[o] = tg[o<<1] & tg[o<<1|1];
}
LL query(int o, int l, int r, int x, int y){
    if(x <= l && r <= y) return s[o];
    LL ans = 0; int mid = l + r >> 1;
    if(x <= mid) ans += query(o<<1, l, mid, x, y);
    if(y > mid) ans += query(o<<1|1, mid+1, r, x, y);
    return ans;
}
int main(){
    int i = 1;
    while(~scanf("%d", &n)){
        printf("Case #%d:\n", i++);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, 1, n);
        scanf("%d", &m);
        while(m--){
            scanf("%d %d %d", &op, &l, &r);
            if(r < l) swap(l, r);
            if(!(l <= r)) exit(-1);
            if(!op) modify(1, 1, n, l, r);
            else printf("%lld\n", query(1, 1, n, l, r));
        }
        printf("\n");
    }
    return 0;
}