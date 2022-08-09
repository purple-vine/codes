#include <cstdio>
using namespace std;
const int M = 200005, mod = 998244353;
int f[M][2], cnt[M], n, m, u, v, cnt1, cnt2, fac[M], invfac[M], k;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
void pre(int n = 200000){
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * inv(i) % mod;
}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int main(){
    scanf("%d %d %d", &n, &m, &k); pre();
    for(int i = 1; i <= m; i++) scanf("%d %d", &u, &v), cnt[u]++, cnt[v]++;
    for(int i = 1; i <= n; i++){
        if(cnt[i] % 2 == 1) ++cnt2;
        else ++cnt1;
    }
    int ans = 0;
    for(int i = 0; i <= k; i += 2){
        int k1 = i, k2 = k-i; // k1 : 入度为奇数的点的数目
        add(ans, 1ll * C(cnt2, k1) * C(cnt1, k2) % mod);
    }
    printf("%d\n", ans);
}