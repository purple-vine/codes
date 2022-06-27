#include <cstdio>
#define p 998244353
using namespace std;
int n, s = 1, a;
signed main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		a = (1ll * (i - 1) * a + 1ll * s * i % p) % p;
		s = 1ll * s * i % p;
	}
	printf("%d\n", a);
} 
