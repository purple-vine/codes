#include <cstdio>
#include <assert.h>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int M = 500005;
int s[M << 2], lf[M << 2], cut[M << 2], n, m, a[M], grow[M << 2], sum[M];
void pushup(int o){
    s[o] = s[o<<1] + s[o<<1|1]; lf[o] = lf[o<<1|1];
}
void Grow(int o, int l, int r, int k){
    s[o] += (sum[r] - sum[l-1]) * k; grow[o] += k;
    lf[o] += k * a[r]; 
}
void Cut(int o, int l, int r, int k){
    s[o] = k * (r-l+1); cut[o] = k; lf[o] = k; grow[o] = 0;
}
void pushdown(int o, int l, int r){
    int mid = l + r >> 1;
    if(cut[o] != -1) {
        Cut(o<<1, l, mid, cut[o]); Cut(o<<1|1, mid+1, r, cut[o]);
        cut[o] = -1;
    }
    if(grow[o] != 0){
        Grow(o<<1, l, mid, grow[o]); Grow(o<<1|1, mid+1, r, grow[o]);
        grow[o] = 0;
    }
}
int query(int o, int l, int r, int t){
    // printf("query o=%d l=%d r=%d t=%d lf=%d\n", o, l, r, t, lf[o]);
    if(lf[o] < t) return r+1;
    if(l == r) return l;
    int mid = l + r >> 1; pushdown(o, l, r);
    return lf[o<<1] >= t ? query(o<<1, l, mid, t) : query(o<<1|1, mid+1, r, t);
}
int modifycut(int o, int l, int r, int x, int y, int t){
    if(x <= l && r <= y) {int tmp = s[o]; Cut(o, l, r, t); grow[o] = 0; return tmp - s[o];}
    int mid = l + r >> 1, ans = 0; pushdown(o, l, r);
    if(x <= mid) ans += modifycut(o<<1, l, mid, x, y, t);
    if(y > mid) ans += modifycut(o<<1|1, mid+1, r, x, y, t);
    pushup(o); return ans;
}

void debug(int o, int l, int r){
    printf("o=%d l=%d r=%d s=%d lf=%d cut=%d grow=%d\n", o, l, r, s[o], lf[o], cut[o], grow[o]);
    if(l == r) return;
    int mid = l + r >> 1; 
    debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
}
int d[M], b[M];
signed main(){
    scanf("%lld %lld", &n, &m); memset(cut, -1, sizeof(cut));
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1); for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    for(int i = 1; i <= m; i++){
        scanf("%lld %lld", &d[i], &b[i]);
        Grow(1, 1, n, d[i]-d[i-1]);
        int pl = query(1, 1, n, b[i]); // printf("pl=%d\n", pl);
        if(pl == n+1) printf("0\n");
        else {
            printf("%lld\n", modifycut(1, 1, n, pl, n, b[i]));
            // debug(1, 1, n); printf("\n");
        }
        // debug(1, 1, n); printf("\n");
    }
}