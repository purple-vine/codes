#include <cstdio>
#include <vector>
#define int long long
using namespace std;
int t,n,m,k,x,y,a[10005][10005];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld %lld",&n,&m,&k);
        if(n*m%k) {printf("No\n");continue;}
        printf("Yes\n");int cnt=-1,x=1,y=0;
        while(cnt<n*m-1){
        	while(y<m&&!a[x][y+1]&&cnt<n*m) a[x][++y]=(++cnt)/k+1;
        	while(x<n&&!a[x+1][y]&&cnt<n*m) a[++x][y]=(++cnt)/k+1;
        	while(y>1&&!a[x][y-1]&&cnt<n*m) a[x][--y]=(++cnt)/k+1;
        	while(x>1&&!a[x-1][y]&&cnt<n*m) a[--x][y]=(++cnt)/k+1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%lld ",a[i][j]);
				a[i][j]=0;
			}
			printf("\n");
		}
    }
    return 0;
}
