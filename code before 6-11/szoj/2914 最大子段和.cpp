#include <cstdio>
#include <iostream>
using namespace std;
int n,a[200005],dp[200005],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i]=max(a[i],dp[i-1]+a[i]);
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
} 
