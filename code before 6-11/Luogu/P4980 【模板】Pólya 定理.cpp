#include <cstdio>
#include <cmath>
#include <cstring>
#define mod 1000000007
using namespace std;
int n, t, p[1005], v[1005][30], cnt, c[1005]; 
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1) {
		if(b & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
	} return ans;
}
void calc(int k){
	for(int i = 2; i <= sqrt(k); i++){
		if(k % i) continue;
		p[++cnt] = i; v[cnt][0] = 1;
		while(k % i == 0) k /= i, ++c[cnt], v[cnt][c[cnt]] = v[cnt][c[cnt]-1] * i;
	}
	if(k > 1) p[++cnt] = k, c[cnt] = 1, v[cnt][1] = k, v[cnt][0] = 1;
}
int dfs(int k, int phi, int num){
//	if(k == cnt + 1) printf("k=%d phi=%d num=%d\n", k, phi, num);
	if(k == cnt + 1) return 1ll * qpow(n, n/num) * phi % mod;
	int ans = dfs(k+1, phi, num);
	for(int i = 1; i <= c[k]; i++){
		ans = (ans + dfs(k+1, phi * v[k][i-1] * (p[k]-1), num * v[k][i])) % mod;
	}
//	printf("out k=%d phi=%d\n", k, phi);
	return ans;
}
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); calc(n);
		printf("%d\n", 1ll * qpow(n, mod-2) * dfs(1, 1, 1) % mod);
		cnt = 0; memset(p, 0, sizeof(p)); memset(c, 0, sizeof(c)); memset(v, 0, sizeof(v));
	}
}
