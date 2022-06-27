#include <cstdio>
using namespace std;
const int M = 250005;
const int p = 998244353;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int inv(int k) {return qpow(k, p - 2);}
int fac[M], invfac[M], n, ans;
void pre(int n = 250000){
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i-1] * i % p,
        invfac[i] = 1ll * invfac[i-1] * inv(i) % p;
}
int fact(int n){
    int ans = 1;
    for(int i = 2; i <= n; i++) ans  = 1ll * ans * i % p;
    return ans;
}
int main(){
    scanf("%d", &n); pre();
    ans = fact(n * n); int kk = fact((n-1) * (n-1)); //printf("k=%d\n", kk);
    for(int k = n; k <= n*n-n+1; k++){
        // printf("%d %d %d %d %lld\n", fac[k-1], invfac[k-n], fac[n*n-k], invfac[n*n-n-k+1], 1ll * fac[k-1] * invfac[k-n] % p 
        // * fac[n*n-k] % p * invfac[n*n-n-k+1] % p 
        // * n % p * n % p * kk % p);
        ans = (ans - 1ll * fac[k-1] * invfac[k-n] % p 
        * fac[n*n-k] % p * invfac[n*n-n-k+1] % p 
        * n % p * n % p * kk % p + p) % p;
    }
    printf("%d\n", ans);
}