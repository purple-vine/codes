#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int M = 1e5 + 5;
int n, s[M << 2]; double A[M], B[M], r[M], k[M], b[M], x[M], y[M];
#define f(i, t) (b[t] + k[t] * x[i])
void upd(int o, int l, int r, int t) {
    int mid = l + r >> 1;
    if(f(mid, s[o]) < f(mid, t)) swap(s[o], t);
    if(f(l, s[o]) < f(l, t)) upd(o<<1, l, mid, t);
    if(f(r, s[o]) < f(r, t)) upd(o<<1|1, mid+1, r, t);
}
double query(int o, int l, int r, int p) {
    if(l == r) return f(p, s[o]);
    int mid = l + r >> 1;
    return max(f(p, s[o]), p <= mid ? query(o<<1, l, mid, p) : query(o<<1|1, mid+1, r, p));
}
/*
x_i = f_ir_i / (a_ir_i + b_i)
y_i = f_i / (a_ir_i + b_i)
f_i = max(f_{i-1}, max(a_i x_j + b_i y_j))
    = max(f_{i-1}, b_i max(a_i / b_i * x_j + y_j))
let k_j = x_j, b_j = y_j, x_i = a_i / b_i
then f_i = max(f_{i-1}, b_i max(k_j * x_j + b_j))
use Li-chao segement tree to maintain it
*/
int main(){
    double f;
    scanf("%d %lf", &n, &f);
    for(int i = 1; i <= n; i++) {
        scanf("%lf %lf %lf", &A[i], &B[i], &r[i]);
        x[i] = A[i] / B[i]; y[i] = x[i];
    }
    sort(x+1, x+n+1);
    for(int i = 1; i <= n; i++) {
        f = max(f, B[i] * query(1, 1, n, lower_bound(x+1, x+n+1, y[i]) - x));
        // printf("%lf\n", query(1, 1, n, lower_bound(x+1, x+n+1, y[i]) - x));
        double tx = f * r[i] / (A[i] * r[i] + B[i]), ty = f / (A[i] * r[i] + B[i]);
        k[i] = tx; b[i] = ty; // printf("k=%lf b=%lf\n", k[i], b[i]);
        upd(1, 1, n, i);
    }
    printf("%lf\n", f);
}