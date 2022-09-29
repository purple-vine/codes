// 381838282
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int M = 100005, mod = 1000000007;
int add(int a, int b) {return (a += b) > mod ? a-mod : a;}
struct matrix{
    int a[3][3], n, m;
    matrix() {}
    matrix(int n_, int m_) {n = n_; m = m_; memset(a, 0, sizeof(a));}
    matrix(int n_) {
        n = m = n_; memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) a[i][i] = 1;
    }
    int* operator [] (int i){
        return a[i];
    }
    matrix operator * (const matrix &tmp) {
        matrix t(n, tmp.m);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    t[i][j] = (t[i][j] + 1ll * a[i][k] * tmp.a[k][j] % mod) % mod;
        return t;
    }
    matrix operator ^ (int tmp) const{
        matrix ans(n), t = *this;
        for(; tmp; tmp >>= 1){
            if(tmp & 1) ans = ans * t;
            t = t * t;
        }
        return ans;
    }
    matrix operator + (const matrix &tmp) const {
        matrix ans = *this;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                ans[i][j] = add(a[i][j], tmp.a[i][j]);
        return ans;
    }
    void print(string s){
        cout << s << ":\n";
        // printf("n=%d m=%d\n", n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("%d ", a[i][j]);
            } printf("\n");
        } printf("\n");
    }
    bool operator == (const matrix &tmp) const{
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) if(a[i][j] != tmp.a[i][j]) return 0;
        return 1;
    }
};
int a[M], n, m;
matrix s[M << 2], laz[M << 2], tran, a0, emp; int f[M];
void pushdown(int o, int l, int r){
    if(laz[o] == emp) return;
    s[o<<1] = s[o<<1] * laz[o]; s[o<<1|1] = s[o<<1|1] * laz[o];
    laz[o<<1] = laz[o<<1] * laz[o]; laz[o<<1|1] = laz[o<<1|1] * laz[o];
    laz[o] = emp;
}
void build(int o, int l, int r){
    laz[o] = emp;
    if(l == r) {
        s[o] = a0 * (tran ^ (a[l]-1)); return;
    }
    int mid = l + r >> 1;
    build(o<<1, l, mid); build(o<<1|1, mid+1, r);
    s[o] = s[o<<1] + s[o<<1|1];
}
void modify(int o, int l, int r, int x, int y, matrix &t){
    if(x <= l && r <= y) {s[o] = s[o] * t; laz[o] = laz[o] * t; return;}
    int mid = l + r >> 1; pushdown(o, l, r);
    if(x <= mid) modify(o<<1, l, mid, x, y, t);
    if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
    s[o] = s[o<<1] + s[o<<1|1];
}
matrix query(int o, int l, int r, int x, int y){
    if(x <= l && r <= y) return s[o];
    int mid = l + r >> 1; pushdown(o, l, r);
    matrix ans(1, 2);
    if(x <= mid) ans = ans + query(o<<1, l, mid, x, y);
    if(y > mid) ans = ans + query(o<<1|1, mid+1, r, x, y);
    return ans;
}
void debug(int o, int l, int r){
    s[o].print("s[" + to_string(o) + "]");
    laz[o].print("laz[" + to_string(o) + "]");
    int mid = l + r >> 1;
    if(l == r) return;
    debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
}
int main(){
    scanf("%d %d", &n, &m); emp = matrix(2);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a0.n = 1; a0.m = 2; a0[0][0] = 1;
    // a0.print("a0");
    tran.n = tran.m = 2; tran.a[0][0] = tran.a[0][1] = tran.a[1][0] = 1;
    // tran.print("tran");
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        int op; scanf("%d", &op);
        if(op == 1) {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            matrix tmp = tran ^ t;
            modify(1, 1, n, x, y, tmp);
        } else {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", (query(1, 1, n, x, y)).a[0][0]);
        }
        // debug(1, 1, n);
    }
}