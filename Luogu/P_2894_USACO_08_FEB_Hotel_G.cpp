#include <cstdio>
#include <iostream>
#define cov(o, t) s[o].lm = s[o].rm = s[o].mn = t == 1 ? s[o].len : 0;
using namespace std;
const int M = 50005;
struct node{
    int lm, rm, mn, len, laz;
} s[M << 2];
void pushup(int o, int l, int r){
    s[o].lm = s[o<<1].lm == s[o<<1].len ? s[o<<1].len + s[o<<1|1].lm : s[o<<1].lm;
    s[o].rm = s[o<<1|1].rm == s[o<<1|1].len ? s[o<<1|1].len + s[o<<1].rm : s[o<<1|1].rm;
    s[o].mn = max(max(s[o<<1].mn, s[o<<1|1].mn), s[o<<1].rm + s[o<<1|1].lm);
}
void pushdown(int o, int l, int r){
    if(!s[o].laz) return;
    cov(o<<1, s[o].laz); cov(o<<1|1, s[o].laz);
    s[o<<1].laz = s[o<<1|1].laz = s[o].laz; s[o].laz = 0;
}
void build(int o, int l, int r){
    s[o] = {r-l+1, r-l+1, r-l+1, r-l+1, 0};
    if(l == r) return;
    int mid = l + r >> 1;
    build(o<<1, l, mid); build(o<<1|1, mid+1, r);
}
int query(int o, int l, int r, int t){
    // printf("%d %d %d %d %d\n", o, l, r, t, s[o].mn);
    if(s[o].mn < t) return 0;
    if(l == r) return l;
    pushdown(o, l, r); int mid = l + r >> 1;
    if(s[o<<1].mn >= t) return query(o<<1, l, mid, t);
    else if(s[o<<1].rm + s[o<<1|1].lm >= t) return mid - s[o<<1].rm + 1;
    else return query(o<<1|1, mid+1, r, t);
}
void modify(int o, int l, int r, int x, int y, int t){
    if(x <= l && r <= y) {cov(o, t); s[o].laz = t; return;}
    int mid = l + r >> 1; pushdown(o, l, r);
    if(x <= mid) modify(o<<1, l, mid, x, y, t);
    if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
    pushup(o, l, r);
}
void debug(int o, int l, int r){
    printf("o=%d l=%d r=%d mn=%d lm=%d rm=%d laz=%d len=%d\n", o, l, r, s[o].mn, s[o].lm, s[o].rm, s[o].laz, s[o].len);
    int mid = l + r >> 1;
    if(l == r) return;
    debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
}
int n, m;
int main(){
    scanf("%d %d", &n, &m); build(1, 1, n);
    while(m--){
        int op, x, y; scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            int tmp = query(1, 1, n, x); printf("%d\n", tmp);
            if(tmp) modify(1, 1, n, tmp, tmp+x-1, 2);
        } else {
            scanf("%d %d", &x, &y);
            modify(1, 1, n, x, x+y-1, 1);
        }
        // if(m <= 5) debug(1, 1, n); printf("\n");
    }
}