#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 50005, mod = 1000000007;
int p[M], tt, phi[M]; bool f[M]; LL sumphi[M];
void pre(int n){
	sumphi[1] = f[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, phi[i] = i-1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; phi[k] = phi[i] * p[j]; break;}
			f[k] = 1; phi[k] = phi[i] * (p[j]-1);
		}
		sumphi[i] = sumphi[i-1] + 1ll * phi[i];
	} 
}
int solve(int n, int m){
    if(n > m) swap(n, m);
    LL ans = 0;
    for(int l = 1, r; l <= n; l = r+1){
        r = min(n/(n/l), m/(m/l));
        ans = (ans + 1ll * (n/l) * (m/l) % mod * (sumphi[r] - sumphi[l-1]) % mod) % mod;
    }
    return ans;
}
int T, n, m, i1, i2, j1, j2;
int main(){
    scanf("%d %d %d", &T, &n, &m);
    pre(max(n, m) + 3);
    while(T--){
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
        printf("%d\n", ((solve(i2, j2) - solve(i1-1, j2) - solve(i2, j1-1) + solve(i1-1, j1-1)) % mod + mod) % mod);
    }
}