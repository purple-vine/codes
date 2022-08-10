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
int a[M], n, op, l, r, m, f[M];
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
struct sg{
    int s[M << 2];
    void upd(int o, int l, int r, int x){
        if(l == r) {s[o] = f[x]; return;}
        int mid = l+r >> 1;
        x <= mid ? upd(o<<1, l, mid, x) : upd(o<<1|1, mid+1, r, x);
        s[o] = addd(s[o<<1], s[o<<1|1]);
    }
    int query(int o, int l, int r, int x, int y){
        if(x <= l && r <= y) return s[o];
        int mid = l + r >> 1; int ans = 0;
        if(x <= mid) add(ans, query(o<<1, l, mid, x, y));
        if(y > mid) add(ans, query(o<<1|1, mid+1, r, x, y));
        return ans;
    }
}t; 
int main(){
    // printf("%d\n", 1ll * 487 * inv(105) % mod);
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%d", &a[i]);
    for(int i = n-1; i >= 1; i--){
        f[i] = addd(1ll * t.query(1, 1, n, i+1, i+a[i]) * inv(a[i]) % mod,
                    addd(1, inv(a[i]))
                    );
        t.upd(1, 1, n, i);
    }
    printf("%d\n", f[1]);
}