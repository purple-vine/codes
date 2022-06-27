#include <cstdio>
#include <iostream>
#define int long long
#define inf 1000000005
using namespace std;
const int M=2005;
int n,a,b,x[M],y[M],w[M],dp[M][M],ans=inf;
main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=0;i<=a+1550;i++) for(int j=0;j<=b+1550;j++) dp[i][j]=inf;
	dp[0][0]=0;
	for(int k=1;k<=n;k++){
		scanf("%lld%lld%lld",&x[k],&y[k],&w[k]);
		for(int i=a+x[k]+1;i>=x[k];i--){
			for(int j=b+y[k]+1;j>=y[k];j--){
				if(dp[i-x[k]][j-y[k]]!=inf){
					dp[i][j]=min(dp[i][j],dp[i-x[k]][j-y[k]]+w[k]);
				}
			}
		}
	}
	for(int i=a;i<=a+1550;i++) for(int j=b;j<=b+1550;j++) ans=min(ans,dp[i][j]);
	printf("%lld",ans);
	return 0;
}
/*2 10 10
5 6 1
7 4 1*/
