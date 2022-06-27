#include <cstdio>
#include <iostream>
#define inf 1e3
using namespace std;
const int M=20;
int n,dp[1<<M][M],dis[M][M];
bool check(int t,int p){
	if(p==0) return 1;
	return (t>>(p-1))&1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) scanf("%d",&dis[i][j]);
	for(int k=0;k<=n;k++) for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=0;i<=1<<(n+1);i++) for(int j=0;j<=n;j++) dp[i][j]=inf;
	dp[0][0]=0;
	printf("%d\n",check(1,1));
	printf("%d\n",1-(1<<(0-1)));
	for(int i=1;i<=(1<<(n+1))-1;i++){
		for(int j=0;j<=n;j++){
			if(!check(i,j)) continue;
			for(int k=0;k<=n;k++){
				if(!check(i,k)||k==j) continue;
				printf("%d %d %d\n",i,j,k);
				dp[i][j]=min(dp[i][j],dp[(i-(1<<(k-1)))][k]+dis[k][j]);
			}
			//printf("%d %d %d\n",i,j,dp[i][j]);
		}
		printf("\n");
	}
	printf("%d",dp[(1<<(n+1))-1][0]);
	return 0;
}
