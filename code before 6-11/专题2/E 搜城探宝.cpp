#include <cstdio>
#include <iostream>
#define print() printf("%d:",u);\
	for(int i=0;i<=k+2;i++) printf("%2d ",dp[u][i]);\
	printf("\n");
using namespace std;
const int M=150;
int dp[M][M],n,k,cnt1,l[M],r[M],fa[M],u,v,w[M],ans;
int dfs(int u){
	dp[u][1]=w[u];
	if(l[u]==0&&r[u]==0) return 1;
	else if(l[u]==0){
		int size=dfs(r[u]);
		for(int i=2;i<=size+1;i++){
			dp[u][i]=dp[r[u]][i];
		}print()
		return size+1;
	}
	else if(r[u]==0){
		int size=dfs(l[u]);
		for(int i=2;i<=size+1;i++){
			dp[u][i]=dp[l[u]][i];
		}print()
		return size+1;
	}
	else{
		int sl=dfs(l[u]),sr=dfs(r[u]);
		for(int i=1;i<=sl+sr+1;i++){
			for(int j=max(0,i-1-sr);j<=min(sl,i-1);j++){
				dp[u][i]=max(dp[u][i],dp[l[u]][j]+dp[r[u]][i-j-1]+w[u]);
			}
		}print()
		return sl+sr;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		if(!l[u]) l[u]=v;
		else r[u]=v;
		fa[v]=u;
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=n;i>=2;i--){
		printf("%d\n",i);
		if(l[fa[i]]==i) l[fa[i]]=0;
		else r[fa[i]]=0;
		l[n+1]=1;r[n+1]=i;dfs(n+1);
		if(l[fa[i]]==0) l[fa[i]]=i;
		else r[fa[i]]=i;
		ans=max(ans,dp[n+1][k+1]);
	}
	printf("%d\n",ans);
}
