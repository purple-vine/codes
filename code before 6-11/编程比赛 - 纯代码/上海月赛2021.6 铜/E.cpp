#include <cstdio>
#include <iostream>
#include <stdlib.h>
#define ll long long
using namespace std;
ll n,a[100005],s1[100005],s2[100005],pl,minn=1e10;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s1[i]=s1[i-1]+a[i];
	}
	for(int i=1;i<=n;i++) s1[i]+=s1[i-1];
	for(int i=n;i>=1;i--) s2[i]=s2[i+1]+a[i];
	for(int i=n;i>=1;i--) s2[i]+=s2[i+1];
//	for(int i=1;i<=n;i++) printf("%d %d\n",s1[i],s2[i]);
	for(int i=1;i<=n;i++){
		minn=min((ll)minn,(ll)abs(s2[i+1]-s1[i-1]));
	}
	printf("%lld",minn);
	return 0;
}
