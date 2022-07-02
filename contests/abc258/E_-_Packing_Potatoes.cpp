#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#define LL long long
using namespace std;
const int M = 5000005;
LL n, q, x, a[M], l[M], r[M], cnt, s[M], t1, t2, num[M]; LL k, sum;
map<LL, LL> savl;
int main(){
    scanf("%lld %lld %lld", &n, &q, &x);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i+n] = a[i], sum += a[i];
    for(int i = 1; i <= 2*n; i++) s[i] = s[i-1] + a[i];
    cnt = x / sum; x %= sum; //printf("x=%d\n", x);
    for(int ll = 1, rr, i = 1; ; ll = rr + 1, i++){
        while(ll > n) ll -= n;
        rr = lower_bound(s+1, s+2*n+1, s[ll-1] + x) - s;
        l[i] = ll; r[i] = rr; num[i] = rr - ll + 1;
        // printf("%d ", num[i]); printf("%d %d\n", ll, rr);
        if(savl[l[i]]) {t1 = i - savl[l[i]], t2 = savl[l[i]]-1; break;}
        savl[l[i]] = i;
    }
    // printf("%d %d\n", t1, t2);
    while(q--){
        scanf("%lld", &k);
        // if(x == 0) {printf("%lld\n", cnt * n); continue;}
        if(k > t2) k = (k - t2 - 1) % t1 + 1, printf("%lld\n", num[k + t2] + cnt * n);
        else printf("%lld\n", num[k] + cnt * n);
    }
}