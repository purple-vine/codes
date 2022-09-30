#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
#define LL long long
using namespace std;
const int M = 1000005, mod = 1000000007, phi = 1000000006;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a >= mod ? a-mod : a;}
int minuss(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x >= mod) x -= mod;}
//void minus(int &x, int y) {x -= y; if(x < 0) x += mod;}
int calc(int x, int y) {return y == 0 ? 1 : y == 1 ? x : inv(x);}
int mu[M], p[M], tt, sum[M], F[M]; bool f[M];
void pre(int n){
	sum[0] = sum[1] = F[1] = f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
        F[i] = (F[i-1] + F[i-2]) % mod;
        sum[i] = 1;
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
	}
    for(int i = 1; i <= n; i++)
        for(int j = 1; i*j <= n; j++)
            sum[i*j] = 1ll * sum[i*j] * calc(F[i], mu[j]) % mod;
    for(int i = 2; i <= n; i++) sum[i] = 1ll * sum[i] * sum[i-1] % mod;
    for(int i = 1; i <= n; i++) if(sum[i] == 0) exit(-1);
}
int solve(int n, int m){
    if(n > m) swap(n, m); int ans = 1;
    for(int l = 1, r; l <= n; l = r+1){
        r = min(m/(m/l), n/(n/l));
        // printf("l=%lld r=%lld sum[]=%lld\n", l, r, sum[r]);
        ans = 1ll * ans * qpow(1ll * sum[r] * inv(sum[l-1]) % mod, 1ll * (n/l) * (m/l) % phi) % mod;
        // printf("ans=%lld\n", ans);
        // if(ans < 0) {
        // 	printf("l=%lld r=%lld\n", l, r);
        // 	printf("sum[r] = %lld sum[l] = %lld n/l = %lld m/l = %lld\n", sum[r], sum[l], n/l, m/l);
        // 	exit(-1);
		// }
    }
    return ans;
}
int T, n, m;
signed main(){
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
    scanf("%d", &T); pre(1000000);
    while(T--){
        scanf("%d %d", &n, &m);
        printf("%lld\n", solve(n, m));
    }
}