//actually it should be F
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 1000005, N = 30;
int a[M], b[M], n, q, da[M], db[M], st1[M][N], st2[M][N], m = 20, t[M];
int query1(int l, int r){
    if(l > r) return 0;
    int s = t[r-l+1]; return __gcd(st1[l][s], st1[r-(1<<s)+1][s]);
}
int query2(int l, int r){
    if(l > r) return 0;
    int s = t[r-l+1]; return __gcd(st2[l][s], st2[r-(1<<s)+1][s]);
}
int main(){
    scanf("%d %d", &n, &q);
    for(int i = 2; i <= n; i++) t[i] = t[i/2] + 1;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), st1[i][0] = da[i] = abs(a[i] - a[i-1]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]), st2[i][0] = db[i] = abs(b[i] - b[i-1]);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            st1[i][j] = __gcd(st1[i][j-1], st1[i+(1<<j-1)][j-1]);
            st2[i][j] = __gcd(st2[i][j-1], st2[i+(1<<j-1)][j-1]);
        }
    }
    while(q--){
        int h1, h2, w1, w2;
        scanf("%d %d %d %d", &h1, &h2, &w1, &w2);
        printf("%d\n", __gcd(a[h1]+b[w1], __gcd(query1(h1+1, h2), query2(w1+1, w2))));
    }
}