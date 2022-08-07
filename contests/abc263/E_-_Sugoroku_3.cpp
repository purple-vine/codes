#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
const int M = 200005, mod = 998244353;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
int a[M], n, op, l, r, m;
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
struct sg{
    int s[M << 2], laz[M << 2];
    void pushdown(int o, int l, int r){
        int mid = l + r >> 1;
        add(laz[o<<1], laz[o]); add(laz[o<<1|1], laz[o]);
        add(s[o<<1], 1ll * (mid-l+1) * laz[o] % mod);
        add(s[o<<1|1], 1ll * (r-mid) * laz[o] % mod);
        laz[o] = 0;
    }
    void modify(int o, int l, int r, int x, int y, int t){
        if(x <= l && r <= y) {add(laz[o], t); add(s[o], 1ll * (r-l+1) * t % mod); return;}
        int mid = l + r >> 1; pushdown(o, l, r);
        if(x <= mid) modify(o<<1, l, mid, x, y, t);
        if(y > mid) modify(o<<1|1, mid+1, r, x, y, t);
        s[o] = addd(s[o<<1], s[o<<1|1]);
    }
    LL query(int o, int l, int r, int x){
        if(l == r) return s[o];
        int mid = l + r >> 1; pushdown(o, l, r);
        return x <= mid ? query(o<<1, l, mid, x) : query(o<<1|1, mid+1, r, x);
    }
}s1, s2;
int main(){
    // printf("%d\n", 1ll * 487 * inv(105) % mod);
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++){
        int k = 1ll * s1.query(1, 1, n, i) * inv(s2.query(1, 1, n, i)) % mod;
        // if(i == 1) k = 0;
        add(k, inv(a[i]));
        // printf("%d\n", k);
        s1.modify(1, 1, n, i+1, i+a[i], 1ll * k * inv(a[i]+1) % mod);
        s2.modify(1, 1, n, i+1, i+a[i], inv(a[i]+1));
    }
    printf("%d\n", 1ll * s1.query(1, 1, n, n) * inv(s2.query(1, 1, n, n)) % mod);
}