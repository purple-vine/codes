#include <cstdio>
#include <algorithm>
#define p 1000000007
#define int long long
using namespace std;
const int M=100005;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1) {if(b&1) ans=a*ans%p;a=a*a%p;}
	return ans;
}
int m,n,s1,s2,t,a[M],x,y,s;
main(){
	scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),s+=a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=n-x+1;i--) s1+=a[i],s1%=p;
	for(int i=n-x;i>=n-x-y+1;i--) s2+=a[i],s2%=p;
	printf("%lld\n",(qpow(3,m)*s1%p+qpow(2,m)*s2+(m<2?(s-s1-s2)*m:0))%p);
}
