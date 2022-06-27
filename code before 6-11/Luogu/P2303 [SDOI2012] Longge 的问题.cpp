#include <cstdio>
#define LL long long
using namespace std;
LL qpow(LL a, LL b){
	LL ans = 1;
	for(; b; b >>= 1)  {if(b & 1) ans = ans * a; a = a * a;}
	return ans;
}
LL solve(LL n){
	LL ans = 1;
	for(LL i = 2; i*i <= n; i++){
		if(n % i) continue;
		LL c = 0ll; while(n % i == 0) n /= i, c++;
		ans *= ((c+1) * qpow(i, c) -  c * qpow(i, c-1));
	}
	if(n > 1) ans *= (2 * n - 1);
	return ans;
}
int main(){
	LL n;
	scanf("%lld", &n);
	printf("%lld\n", solve(n));
}
//4294967295
