#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
const int M = 10000005, mod = 20101009;
int add(int a, int b) {a += b; return a<0 ? a+mod: a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
int mu[M], p[M], tt, s[M]; bool f[M];
void pre(int n){
	f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, mu[i] = -1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
			f[k] = 1; mu[k] = -mu[i];
		}
	} 
    for(int i = 1; i <= n; i++) s[i] = add(s[i-1], 1ll * mu[i] * i % mod * i % mod);
}
int calc(int n, int m){
    return 1ll * (1ll * n * (n+1) / 2 % mod) * (1ll * m * (m+1) / 2 % mod) % mod;
}
int F(int n, int m){
    if(n > m) swap(n, m); int ans = 0;
    for(int l = 1, r; l <= n; l = r+1){
        r = min(n/(n/l), m/(m/l));
        ans = add(ans, 1ll * minus(s[r], s[l-1]) * calc(n/l, m/l) % mod);
    }
    return ans;
}
int cal(int x){
    return 1ll * x * (x+1) / 2 % mod;
}
int solve(int n, int m){
    if(n > m) swap(n, m); int ans = 0;
    for(int l = 1, r; l <= n; l = r+1){
        r = min(n/(n/l), m/(m/l));
        ans = add(ans, 1ll * minus(cal(r), cal(l-1)) * F(n/l, m/l) % mod);
    }
    return ans;
}
int T, n, m;
int main(){
    pre(10000000);
    scanf("%d %d", &n, &m);
    printf("%d\n", solve(n, m));
}