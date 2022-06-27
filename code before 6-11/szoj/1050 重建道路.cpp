#include <cstdio>
#include <iostream>
#include <cstring>
#define inf (1e9+5)
using namespace std;
const int M=205;
struct edge{
	int to,nxt;
}e[M];		//删去j个结点所需的最小破坏道路数 
int head[M],dp[M][M],cnt1,n,u,v,ww,k,m,in[M],t,ans=inf;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
	in[v]++;
}
int dfs(int u){
	int size=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		int sv=dfs(v);size+=sv;
		for(int j=size;j>=0;j--){
			for(int k=0;k<=sv;k++){
				if(j>=k) dp[u][j]=min(dp[u][j],dp[u][j-k]+dp[v][k]);
			}
		}
	}
	dp[u][size]=1;
	if(size>=m) ans=min(ans,dp[u][size-m]+1);
//	printf("%2d:",u);
//	for(int i=0;i<=n-m;i++) printf("%10d ",dp[u][i]);
//	printf("\n");
	return size;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++) {scanf("%d%d",&u,&v);link(u,v);}
	for(int i=1;i<=n+5;i++) for(int j=1;j<=n-m+5;j++) dp[i][j]=inf;
	for(int i=1;i<=n;i++){
		if(in[i]==0) {dfs(i);ans=min(ans,dp[i][n-m]);printf("%d",ans);return 0;}
	}
}
