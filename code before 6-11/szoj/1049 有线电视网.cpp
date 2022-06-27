#include <cstdio>
#include <iostream>
#include <cstring>
#define inf (1e8+5)
using namespace std;
const int M=3005;
struct edge{
	int to,nxt,w;
}e[M];
int head[M],dp[M][3005],w[M],cnt1,n,u,v,ww,k,m,ans;
void link(int u,int v,int w){
	e[++cnt1].to=v;
	e[cnt1].w=w;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int dfs(int u){
	int size=0;
	if(u>=n-m+1) {dp[u][1]=w[u];return 1;}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		int sv=dfs(v);size+=sv;
		for(int j=size;j>=0;j--){
			for(int k=0;k<=min(sv,j);k++){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]-e[i].w);
			}
		}
	}
//	printf("%d:",u);
//	for(int i=1;i<=m;i++) printf("%d ",dp[u][i]);
//	printf("\n");
	return size;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int u=1;u<=n-m;u++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++) {scanf("%d%d",&v,&ww);link(u,v,ww);}
	}
	for(int i=n-m+1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n+5;i++) for(int j=1;j<=m+5;j++) dp[i][j]=-inf;
	dfs(1);
	for(int i=m;i>=1;i--) if(dp[1][i]>=0) {printf("%d",i);return 0;}
	return 0;
}
