#include <cstdio>
#define ll long long
using namespace std;
const int M=2500,p=2333;
ll c[M][M],f[M][M];
void deal(int n){
	for(int i=0;i<=n;i++) c[i][0]=c[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
		}
	}
	for(int i=0;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=n;j++){
			f[i][j]=(f[i][j-1]+c[i][j])%p;
		}
	}
}
int lucas(ll a,ll b){
	if(a<=p&&b<=p) return c[a][b];
	return (lucas(a/p,b/p)*c[a%p][b%p])%p;
}
int F(ll n,ll k){
	if(k<0) return 0;
	if(n<=p&&k<=p) return f[n][k];
	return ((F(n/p,k/p-1)*F(n%p,p-1))%p+(F(n%p,k%p)*lucas(n/p,k/p))%p)%p;
}
ll t,n,k;
int main(){
	scanf("%d",&t);deal(2400);
	while(t--){
		scanf("%lld%lld",&n,&k);
		printf("%d\n",F(n,k));
	}
}//afnnabghrb
