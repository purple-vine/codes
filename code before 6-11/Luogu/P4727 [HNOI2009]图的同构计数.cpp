#include <cstdio>
#define inv(i) qpow(i, mod-2)
using namespace std;
const int M = 65;
int c[M], ifac[M], s[M], n, cnt, ans, facn, inv[M], mod, m;
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1){
		if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;
	} return ans;
}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a%b);}
void pre(int n){
	facn = ifac[0] = 1;
	for(int i = 1; i <= n; i++){
		ifac[i] = 1ll * ifac[i-1] * inv(i) % mod, facn = 1ll * facn * i % mod;
		inv[i] = inv(i);
	}
}
int calc(){
	int ans = facn, ind = 0;
	for(int i = 1; i <= cnt; i++) ans = 1ll * ans * inv[c[i]] % mod;
	for(int i = 1; i <= n; i++) ans = 1ll * ans * ifac[s[i]] % mod;
	for(int i = 1; i <= cnt; i++){
		ind += c[i] / 2;
		for(int j = i+1; j <= cnt; j++) ind += gcd(c[i], c[j]);
	}
	return 1ll * ans * qpow(m, ind) % mod;
}
void dfs(int limit, int sum){
	if(sum == n) {ans = (ans + calc()) % mod; return;}
	cnt++;
	for(int i = limit; i <= n-sum; i++){
		c[cnt] = i; s[i]++;
		dfs(i, sum+i);
		s[i]--;
	} cnt--;
}
int main(){
	scanf("%d %d %d", &n, &m, &mod);
	pre(n); dfs(1, 0);
	printf("%d\n", 1ll * ans * inv(facn) % mod);
}
