#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int p=1000000007;			//c[i][j]:C(i,j+i)
int n,m,a[1500]={1},ans,t[1500]={1},c[1100][1100];
void cal(int n,int m){
//	for(int i=1;i<=n;i++) c[i][0]=1;
//	for(int i=1;i<=m;i++) c[0][i]=1;
	c[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0&&j==0) continue;
			c[i][j]=(c[i-1][j]+c[i][j-1])%p;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%lld ",c[i][j]);
//		}
//		printf("\n");
//	}
	return;
}
main(void){
	scanf("%lld%lld",&n,&m);
	if(m==1) {printf("%lld",(n*(n+1)/2)%p);return 0;}
	cal(m+5,n+5);
	for(int i=1;i<=n;i++) a[i]=c[m-2][i]%p;
//	for(int i=0;i<=n;i++) printf("%lld ",a[i]);
//	printf("\n\n");
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			t[i]=(t[i]+a[j]*(i-j)%p)%p;
		}
//		printf("%lld ",t[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=(ans+(a[j-i]*t[i])%p)%p;
		}
	}
	printf("\n%lld",ans%p);
}
