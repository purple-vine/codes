#include <cstdio>
#include <iostream>
using namespace std;
int n,a[5005],dp1[5005],dp2[5005],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		dp1[i]=1;
		for(int j=1;j<i;j++) if(a[j]<a[i]) dp1[i]=max(dp1[i],dp1[j]+1);
	}
	for(int i=n;i>=1;i--){
		dp2[i]=1;
		for(int j=n;j>i;j--) if(a[j]<a[i]) dp2[i]=max(dp2[i],dp2[j]+1);
		ans=max(ans,dp1[i]+dp2[i]-1);
	}
	printf("%d",n-ans);
	return 0;
}
