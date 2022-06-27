#include <cstdio>
#define p 1000000007
using namespace std;
const int mod=1000000007;
const int M = 10000005;
namespace dataGen{ 
	int seed;
  	inline void init(int S){seed=S;}
  	inline int getNext() { return seed=(1ll*seed*5+13)%mod; }
}
int n,k,a[M],S, inv[M << 1], ans0 = 1, ans;
int main(){
  	scanf("%d%d%d",&n,&k,&S);
  	dataGen::init(S); inv[1] = 1;
  	for(int i=1;i<=n;i++)
    	a[i]=dataGen::getNext();
    for(int i = 2; i <= n; i++)
    	inv[i] = 1ll * (p - p/i) * inv[p % i] % p;
    ans += 1ll * a[n] % p;
	for(int i = 2; i <= n; i++){
		//printf("%d\n", ans0);
    	ans0 = 1ll * ans0 * inv[i - 1] % p * (i + k - 1) % p;
    	ans = (ans + 1ll * a[n - i + 1] * ans0 % p) % p;
	} //printf("%d\n", ans0);
	printf("%d\n", ans);
}
