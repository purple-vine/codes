#include <cstdio>
#include <iostream>
using namespace std;
const int M=105;
int dp[M][M],n,a[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) dp[i][i]=a[i-1]*a[i]*a[i+1];
	for(int k=1;k<=n-1;k++){
		for(int i=2;i<=n-k;i++){
			dp[i][i+k]=1e8;
			for(int j=i;j<=i+k;j++){
				dp[i][i+k]=min(dp[i][i+k],dp[i][j-1]+a[i-1]*a[j]*a[i+k+1]+dp[j+1][i+k]);
			}
		}
	}
	printf("%d\n",dp[2][n-1]);
}
