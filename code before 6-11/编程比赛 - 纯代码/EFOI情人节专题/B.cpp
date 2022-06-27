#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int qpow(int a, int b, int p){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int a = 2, n, b = 1;
signed main(){
	scanf("%lld", &n);
	if(n == 1) {printf("1\n"); return 0;}
	printf("%lld\n", qpow(2, (n-2) % (mod-1) * qpow(2, n-1, mod-1) % (mod-1) + 1, mod));
}
