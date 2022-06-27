#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
#define p 998244353
using namespace std;
ll l,r,ans1,ans2;
ll get(ll a){
	ll ans=0;
	for(ll l=1,r;l<=a;l=r+1){
		r=min(a/(a/l),a);
		ans+=(r-l+1)*(a/l);
		ans%=p;
	}
	return ans;
}
int main(){
	scanf("%lld %lld",&l,&r);
	printf("%lld",((get(r)+p)-get(l-1))%p);
	return 0;
}
