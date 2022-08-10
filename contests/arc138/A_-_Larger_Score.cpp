#include <cstdio>
#include <iostream>
using namespace std;
const int M = 400005;
int a[M], n, s, ans = 1e9;
struct sg{
    int s[M << 2];
    void build(int o, int l, int r){
        if(l == r) {s[o] = a[l]; return;}
        int mid = l + r >> 1;
        build(o<<1, l, mid); build(o<<1|1, mid+1, r);
        s[o] = min(s[o<<1], s[o<<1|1]);
    }
    int query(int o, int l, int r, int t){
        // printf("%d %d %d %d %d\n", o, l, r, t, s[o]);
        if(s[o] >= t) return -1;
        if(l == r) return l;
        int mid = l + r >> 1;
        if(s[o<<1|1] < t) return query(o<<1|1, mid+1, r, t);
        else return query(o<<1, l, mid, t);
    }
}t;
int main(){
    scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    t.build(1, 1, s); //printf("%d\n", t.query(1, 1, s, 2));
    for(int i = s+1; i <= n; i++){
        // printf("%d\n", a[i]);
        int pl = t.query(1, 1, s, a[i]);
        // printf("pl=%d\n", pl);
        if(pl == -1) continue;
        ans = min(ans, i - s + (s - pl));
    }
    printf("%d\n", ans == (int)1e9 ? -1 : ans);
}