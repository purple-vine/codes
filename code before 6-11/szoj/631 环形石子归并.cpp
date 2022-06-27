#include <cstdio>
#include <iostream>
#define inf 1e9
using namespace std;
const int M=205;
int n,a[M],dp[M][M],sum[M],ans=inf;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i+n]=a[i];}
	for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
	for(int k=2;k<=n;k++){
		for(int i=1;i<=n;i++){
			dp[i][i+k-1]=inf;
			for(int j=i;j<i+k-1;j++){
				dp[i][i+k-1]=min(dp[i][i+k-1],dp[i][j]+dp[j+1][i+k-1]+sum[i+k-1]-sum[i-1]);
			}
			dp[i+n][i+k-1+n]=dp[i][i+k-1];
		}
	}
	for(int i=1;i<=n;i++) ans=min(ans,dp[i][i+n-1]);
	printf("%d\n",ans);
}
