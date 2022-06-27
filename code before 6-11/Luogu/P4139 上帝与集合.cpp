#include <cstdio>
using namespace std;
int phi(int n){
	int ans = n;
	for(int i = 2; i * i <= n; i++) if(n % i == 0) {
		ans = ans / i * (i-1); while(n % i == 0) n /= i;
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans; 
}
int qpow(int a, int b, int p){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int solve(int mod){
	if(mod == 1) return 0;
	int Phi = phi(mod);
	return qpow(2, solve(Phi) + Phi, mod);
}
int t, p;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &p);
		printf("%d\n", solve(p));
	}
}
