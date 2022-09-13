#include <cstdio>
#include <bitset>
#include <iostream>
#include <algorithm>
#define lowbit(i) (i & -i)
using namespace std;
const int M = 1000005, N = 100005;
int s[M << 2]; bitset<N> p[1 << 11];
int n, a[M], m, q, op[M], lp[M], rp[M], x[M], b[15], t1[M], t2[M]; // t  存个离散化
int k[N], laz[M << 2];
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
void write(int x){
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
	return;
}
void pushdown(int o, int l, int r){
    if(!laz[o]) return;
    s[o<<1] = laz[o]; laz[o<<1] = laz[o];
    s[o<<1|1] = laz[o]; laz[o<<1|1] = laz[o];
    laz[o] = 0;
}
void build(int o, int l, int r){
    if(l == r) {s[o] = (1 << t1[l]-1); return;}
    int mid = l + r >> 1;
    build(o<<1, l, mid); build(o<<1|1, mid+1, r);
    s[o] = s[o<<1] | s[o<<1|1];
}
void modify(int o, int l, int r, int x, int y, int t){
    // printf("%d %d %d %d %d %d\n", o, l, r, x, y, t);
    if(x <= l && r <= y) {s[o] = t; laz[o] = t; return;}
    int mid = l + r >> 1; pushdown(o, l, r);
    if(x <= mid) modify(o<<1, l, mid, x, y, t);
    if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
    s[o] = s[o<<1] | s[o<<1|1];
}
int query(int o, int l, int r, int x, int y){
    if(x <= l && r <= y) return s[o];
    int mid = l + r >> 1; int ans = 0; pushdown(o, l, r);
    if(x <= mid) ans |= query(o<<1, l, mid, x, y);
    if(y > mid) ans |= query(o<<1|1, mid+1, r, x, y);
    return ans;
}
void print(bitset<N> &k){
    for(int i = 0; i <= m; i++) cout << k[i] << " ";
    printf("\n");
}
int cnt1;
int get(int k){
    for(int i = 20; i >= 0; i--) if(k & (1 << i)) return i;
    return 0;
}
void insert(int x){
    for(int i = 1; i <= 10; i++) if(b[i] == x) return;
    b[++cnt1] = x;
}
int find(int x){
    for(int i = 1; i <= 10; i++) if(b[i] == x) return i;
    return 0;
}
int main(){
    // freopen("a10.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    n = read(); m = read(); q = read();
    for(int i = 1; i <= n; i++) a[i] = read(), insert(a[i]);
    for(int i = 1; i <= q; i++){
        op[i] = read(); lp[i] = read(); rp[i] = read(); x[i] = read();
        // scanf("%d %d %d %d", &op[i], &lp[i], &rp[i], &x[i]);
        if(op[i] == 1) insert(x[i]);
    }
    // printf("gg\n");
    sort(b+1, b+cnt1+1); int n1 = unique(b+1, b+cnt1+1) - b - 1;
    // for(int i = 1; i <= n1; i++) printf("%d ", b[i]); printf("\n");
    for(int i = 1; i <= n; i++) t1[i] = find(a[i]);
    for(int i = 1; i <= q; i++) if(op[i] == 1) t2[i] = find(x[i]);
    p[0][0] = 1;
    for(int i = 0; i <= n1; i++) k[1 << i] = i;
    // print(p[0]);
    for(int i = 1; i < (1 << n1); i++){
        int pl = get(i), t = b[pl + 1];
        // printf("i=%d pl=%d b[] = %d\n", i, pl, b[pl + 1]);
        p[i] = p[i - (1 << pl)];
        for(int j = t; j <= m; j++){
            p[i][j] =  p[i][j] | p[i][j-t];
        }
        // p[i] = p[i - lowbit(i)] | (p[i - lowbit(i)] << b[k[lowbit(i)] + 1]);
        // printf("%d:", i); print(p[i]);
    }
    for(int i = 1; i < (1 << n1); i++){
        // printf("%d:", i); print(p[i]);
    }
    // printf("gg\n");
    build(1, 1, n);
    for(int i = 1; i <= q; i++){
        // printf("i=%d\n", i);
        if(op[i] == 1) modify(1, 1, n, lp[i], rp[i], 1 << t2[i] - 1);
        else {
            int ans = query(1, 1, n, lp[i], rp[i]);
            if(p[ans][x[i]]) printf("Yes\n");
            else printf("No\n");
        }
    }
}