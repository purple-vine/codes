#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
int n,m,a[100005],minn=1e10+5,maxx,summ;
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {scanf("%lld",&a[i]);minn=min(minn,a[i]);maxx=max(maxx,a[i]);summ+=a[i];}
	summ-=minn;summ-=maxx;
	int t=maxx*(n-2)-summ;
	if(m<=t) printf("%lld",summ+m);
	else printf("%lld",maxx*(n-2)+(m-t)*(n-2)/(n-1));
	return 0;
}
