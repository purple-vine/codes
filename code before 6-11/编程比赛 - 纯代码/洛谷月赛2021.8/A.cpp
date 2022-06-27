#include <cstdio>
#define p 1000000007
#define ll unsigned long long
using namespace std;
ll t,n,k,ans;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&k);ans=0;
		if(k%2==1){
			for(register ll i=n*n;i>=n*n-k+1;i-=2) ans=(ans+i)%p;
			printf("%lld\n",(ans-(n*(n+1)-k+1)/2+n+p)%p);
		}
		else{
			for(register ll i=n*n;i>=n*n-k+2;i-=2) ans=(ans+i)%p;
			printf("%lld\n",ans);
		}
	} 
} 
