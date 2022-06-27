#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
int t,a,b,c,d,ans,m,n;
main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		m=abs(c-a);n=abs(d-b);
		printf("%lld\n",max(m,n)*2-1*((m+n)%2));
	}
}
