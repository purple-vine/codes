#include <cstdio>
#include <iostream>
#include <assert.h>
using namespace std;
const int B = 10000, M = 650005;
int cnt, a[M], pl[M], lp[M], rp[M], l[M], r[M];
bool chk(int j) {return __builtin_ctz(j) == __builtin_popcount(j);}
void pre(int n){
    for(int i = 1; i <= n/B; i++){
        lp[i] = rp[i-1] + 1; rp[i] = lp[i] + B-1;
        for(int j = lp[i]; j <= rp[i]; j++){
            if(chk(j)){
                pl[i] = j; break;
            }
            pl[i] = -1;
        }
        
    }
}
inline void solve(int l, int r){
    int L = (l-1)/B + 1, R = (r-1) / B + 1, ans = -1;
    assert(lp[L] <= l && l <= rp[L]);
    if(L == R){
        for(int i = l; i <= r; i++) if(chk(i)) {ans = i; break;}
        printf("%d\n", ans); return;
    }
    for(int i = L+1; i <= R-1; i++) {if(pl[i] != -1) ans = pl[i]; break;}
    if(ans == -1) for(int i = l; i <= rp[L]; i++) if(chk(i)) {ans = i; break;}
    if(ans == -1) for(int i = lp[R]; i <= r; i++) if(chk(i)) {ans = i; break;} 
    printf("%d\n", ans);
}
int main(){
    // freopen("ex_data2.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int q, mn = 0; scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d %d", &l[i], &r[i]);
        mn = max(mn, r[i]);
    }
    pre(mn + B);
    for(int i = 1; i <= q; i++){
        solve(l[i], r[i]);
    }
}