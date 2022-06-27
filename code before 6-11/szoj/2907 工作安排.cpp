#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int M=5005;
int n,m,s[M],e[M],p[M],dp[M],ans;
vector <int> mp[M];
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s[i],&e[i],&p[i]);
		mp[s[i]+e[i]-1].push_back(i);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<mp[i].size();j++) dp[i]=max(dp[i],dp[s[mp[i][j]]-1]+p[mp[i][j]]);
		ans=max(ans,dp[i]);
//		printf("%d ",dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}
