#include <cstdio>
#define int long long
using namespace std;
const int M=100005;
int qpow(int a,int b,int p){
	int ans=1;
	for(;b;b>>=1) {if(b&1) ans=a*ans%p;a=a*a%p;}
	return ans;
}
int a,b,c,k,t;
main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
		printf("%lld\n",(c*qpow(2,k,a+b+c))%(a+b+c));
	}
}
