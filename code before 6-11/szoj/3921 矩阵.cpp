#include <cstdio>
#include <cmath>
#include <iostream>
#define inf 1e3
using namespace std;
const int M=20,MM=1005;
int a[M][MM],d[M][M],n,m,dp[1<<M][M],ans=0,g[M][M];
//int abs(int n){
//	if(n>0) return n;
//	else return 0-n;
//}
int main(){
	//printf("%d %d\n",abs(4),abs(-4));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=g[i][j]=inf;
	for(int i=0;i<(1<<n);i++) for(int j=1;j<=m;j++) dp[i][j]=0;
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				d[i][j]=min(d[i][j],abs(a[i][k]-a[j][k]));
				if(k<m) g[i][j]=min(g[i][j],abs(a[i][k]-a[j][k+1]));
			}
		}
	}
//	for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) printf("%d ",d[i][j]);printf("\n");}
//	for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) printf("%d ",g[i][j]);printf("\n");}
	for(int t=1;t<=n;t++){
//		printf("%d\n",t);
		for(int i=0;i<(1<<n);i++) for(int j=1;j<=m;j++) dp[j][i]=0;
//		for(int i=1;i<=n;i++){
//			if(i==t) continue;
//			dp[(1<<(i-1))|(1<<(t-1))][i]=d[t][i];
//		}
		dp[1<<(t-1)][t]=inf;
		for(int i=0;i<(1<<n);i++){
			if((i>>(t-1))==0) continue;
			//printf("%2d:",i);
			for(int j=1;j<=n;j++){
				//printf("%4d ",dp[i][j]);
				if((i>>(j-1))==0||dp[i][j]==0) continue;
				for(int k=1;k<=n;k++){
					if((i>>(k-1))==1||k==j) continue;//问题居然在下面一行的d打成了a!!! 
					dp[i|(1<<(k-1))][k]=max(dp[i|(1<<(k-1))][k],min(dp[i][j],d[j][k]));
				}
			}
			//printf("\n");
		}
		//printf("\n");
		for(int i=1;i<=n;i++){
			if(i==t) continue;
			ans=max(ans,min(dp[(1<<n)-1][i],g[i][t]));
		}
	}
	printf("%d",ans);
}
