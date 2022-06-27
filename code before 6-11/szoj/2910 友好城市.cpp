#include <cstdio>
#include <algorithm>
using namespace std;
const int M=5005;
int dp[M][2],x,y,c,d,n;
pair<int,int>a[M];
int main(){
	scanf("%d%d%d",&x,&y,&n);
	for(int i=1;i<=n;i++) {scanf("%d%d",&c,&d);a[i]=make_pair(c,d);}
	sort(a+1,a+n+1);
	dp[1][0]=0;dp[1][1]=1;
	for(int i=2;i<=n;i++){
		dp[i][1]=1;
		for(int j=1;j<i;j++){
			dp[i][0]=max(dp[i][0],dp[j][0]);
			if(a[j].second<a[i].second) dp[i][1]=max(dp[i][1],dp[j][1]+1);
		}
	}
	printf("%d",max(dp[n][0],dp[n][1]));
}
