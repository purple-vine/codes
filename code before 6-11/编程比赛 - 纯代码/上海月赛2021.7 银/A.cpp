#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int M=1000005;
int n,s,c[M],a[M],p[M]={100005},ans;
main(){
	scanf("%lld%lld",&n,&s);
	//for(int i=1;i<=n;i++) p[i]=1e10+1e5;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&a[i]);
		p[i]=min(p[i-1]+s,c[i]);
		ans+=p[i]*a[i];
	}
	printf("%lld",ans);
	return 0;
}
