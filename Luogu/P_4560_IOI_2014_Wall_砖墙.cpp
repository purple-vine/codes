#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M = 2000005;
int s[M << 2], L[M << 2], R[M << 2], n, a[M], m, lazl[M << 2], lazr[M << 2];
void pushdown(int o, int l, int r){
    // if(l <= 5 && 5 <= r)
    //     printf("pushdown %d %d %d\n", o, l, r);
    if(lazl[o] != -1){
        R[o<<1] = max(R[o<<1], lazl[o]); L[o<<1] = max(L[o<<1], lazl[o]);
        R[o<<1|1] = max(R[o<<1|1], lazl[o]); L[o<<1|1] = max(L[o<<1|1], lazl[o]);
        lazl[o<<1] = max(lazl[o<<1], lazl[o]); lazr[o<<1] = max(lazr[o<<1], lazl[o]); // 记得一起更新 lazr
        lazl[o<<1|1] = max(lazl[o<<1|1], lazl[o]); lazr[o<<1|1] = max(lazr[o<<1|1], lazl[o]);
        lazl[o] = -1;
    }
    if(lazr[o] != 0x7f7f7f7f){
        R[o<<1] = min(R[o<<1], lazr[o]); L[o<<1] = min(L[o<<1], lazr[o]);
        R[o<<1|1] = min(R[o<<1|1], lazr[o]); L[o<<1|1] = min(L[o<<1|1], lazr[o]);
        lazr[o<<1] = min(lazr[o<<1], lazr[o]); lazl[o<<1] = min(lazl[o<<1], lazr[o]);
        lazr[o<<1|1] = min(lazr[o<<1|1], lazr[o]); lazl[o<<1|1] = min(lazl[o<<1|1], lazr[o]);
        lazr[o] = 0x7f7f7f7f;
    }
}
void upd(int o, int l, int r, int x, int y, int t, int op){
    // printf("%d %d %d %d %d %d\n", o, l, r, x, y, r);
    if(x <= l && r <= y) {
        if(op == 0) // remove
            L[o] = min(L[o], t), R[o] = min(R[o], t), lazr[o] = min(lazr[o], t), lazl[o] = min(lazl[o], t);
        else // add
            R[o] = max(R[o], t), L[o] = max(R[o], t), lazl[o] = max(lazl[o], t), lazr[o] = max(lazr[o], t);
        return;
    }
    int mid = l + r >> 1; pushdown(o, l, r);
    if(x <= mid) upd(o<<1, l, mid, x, y, t, op);
    if(y > mid) upd(o<<1|1, mid+1, r, x, y, t, op);
    L[o] = min(L[o<<1], L[o<<1|1]); R[o] = max(R[o<<1], R[o<<1|1]);
}
void output(int o, int l, int r){
    if(l == r) {printf("%d\n", R[o]); return;}
    int mid = l + r >> 1; pushdown(o, l, r);
    output(o<<1, l, mid); output(o<<1|1, mid+1, r);
}
void debug(int o, int l, int r){
    if(l <= 5 && 5 <= r) printf("o=%d l=%d r=%d L=%d R=%d lazl=%d lazr=%d\n", o, l, r, L[o], R[o], lazl[o], lazr[o]);
    int mid = l + r >> 1; if(l == r) return;
    debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
}
int main(){
    scanf("%d %d", &n, &m);
    memset(lazl, -1, sizeof(lazl)); memset(lazr, 0x7f, sizeof(lazr));
    while(m--){
        int op, l, r, x;
        scanf("%d %d %d %d", &op, &l, &r, &x);
        upd(1, 1, n, l+1, r+1, x, 2 - op);
        // debug(1, 1, n); printf("\n");
    }
    output(1, 1, n);
}