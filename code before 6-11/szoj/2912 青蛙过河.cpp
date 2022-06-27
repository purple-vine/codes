#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M=100005;
int dp[M],s,t,h,l,m,ans=105;
bool mp[M];
int main(){
	scanf("%d%d%d%d",&l,&s,&t,&m);
	for(int i=1;i<=m;i++) {scanf("%d",&h);mp[h]=1;}
	for(int i=1;i<s;i++) dp[i]=105;
	for(int i=s;i<l+t;i++){
		dp[i]=105;
		for(int j=s;j<=t;j++) dp[i]=min(dp[i],dp[i-j]);
		dp[i]+=mp[i];
//		printf("%d ",dp[i]);
	}
	for(int i=l;i<l+t;i++) ans=min(ans,dp[i]);
	printf("\n%d",ans);
	return 0;
}
