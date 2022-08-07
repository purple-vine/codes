#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 1000005, mod = 104857601;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
void add(int &x, int y, int mod) {x += y; if(x > mod) x -= mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
int p[M], tt, phi[M]; bool f[M];
void pre(int n){
	f[1] = 1; phi[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]) p[++tt] = i, phi[i] = i-1;
		for(int j = 1; j <= tt; j++){
			int k = p[j] * i; if(k > n) break;
			if(i % p[j] == 0) {f[k] = 1; phi[k] = phi[i] * p[j]; break;}
			f[k] = 1; phi[k] = phi[i] * (p[j]-1);
		}
	} 
    for(int i = 2; i <= n; i++) add(phi[i], phi[i-1], mod-1);
}
int n;
int main(){
    scanf("%d", &n); pre(n + 3);
    int ans = 1;
    for(int i = 1; i <= n; i++){
        ans = 1ll * ans * qpow(i, (2ll * phi[n/i] - 1) % (mod-1)) % mod;
    }
    ans = 1ll * qpow(fact(n), 2*n) * inv(1ll * ans * ans % mod) % mod;
    printf("%d\n", ans);
}