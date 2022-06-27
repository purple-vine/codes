#include <cstdio>
#include <iostream>
using namespace std;
const int M=1005;
int a[M],b[M],dp[M],n;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++) {scanf("%d",&a[i]);b[i]=b[i-1]+a[i];}
	for(int i=2;i<=n+1;i++){
		if(a[i]>0) dp[i]=dp[i-1]+1;
		for(int j=1;j<i;j++){
			if(b[i]-b[j-1]>=0) dp[i]=max(dp[i],dp[j]);
		}
		printf("%d ",dp[i]);
	}
	if(dp[n+1]>0) printf("%d",dp[n+1]);
	else printf("Impssible");
}
