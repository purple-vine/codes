#include <cstdio>
#include <iostream>
#include <cmath>
#define inf 1e9
#define ll long long
using namespace std;
const int M=1005;
int a[M][M],n,m,sum[M][M];
ll dp[M][M];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void write(int x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++) for(register int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(register int i=1;i<=m;i++) for(register int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+a[j][i];
	for(register int i=1;i<=n;i++) dp[i][1]=sum[1][i];
	for(register int i=2;i<=m;i++){
		for(register int j=1;j<=n;j++){
			dp[j][i]=dp[j][i-1]+(ll)a[j][i];
			for(register int k=1;k<j;k++)
				dp[j][i]=max(dp[j][i],dp[k][i-1]+sum[i][j]-sum[i][k-1]);
			for(register int k=j+1;k<=n;k++)
				dp[j][i]=max(dp[j][i],dp[k][i-1]+sum[i][k]-sum[i][j-1]);
		}
	}
	printf("%lld\n",dp[n][m]);
	return 0;
}
