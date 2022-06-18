//time : 22-6-6 12:13
//problem id : luogu P4213
//status : AC
#include <cstdio>
#include <map>
#define LL long long
using namespace std;
const int M = 1000005;
int mu[M], p[M], tt, phi[M]; bool f[M]; LL summu[M], sumphi[M];
void pre(int n){
	sumphi[1] = summu[1] = f[1] = mu[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, mu[i] = -1, phi[i] = i-1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; phi[k] = phi[i] * p[j]; break;}
			f[k] = 1; mu[k] = -mu[i]; phi[k] = phi[i] * (p[j]-1);
		}
		summu[i] = summu[i-1] + 1ll * mu[i]; sumphi[i] = sumphi[i-1] + 1ll * phi[i];
	} 
}
int T, n, m = 1000000; map<int, LL> smu, sphi;
LL Summu(int n){
    if(n <= m) return summu[n];
    if(smu[n]) return smu[n];
    LL ans = 1ll;
    for(int l = 2, r; l <= n; l = r+1){
        r = 1ll * n/(n/l); ans -= (r-l+1) * Summu(n/l);
    } return smu[n] = ans;
}
LL Sumphi(int n){
    if(n <= m) return sumphi[n];
    if(sphi[n]) return sphi[n];
    LL ans = n * (n+1) / 2;
    for(int l = 2, r; l <= n; l = r+1){
        r = n/(n/l); ans -= (r-l+1) * Sumphi(n/l);
    } return sphi[n] = ans;
}
int main(){
    scanf("%d", &T); pre(1000000);
    while(T--){
        scanf("%d", &n);
        printf("%lld %lld\n", Sumphi(n), Summu(n));
    }
}