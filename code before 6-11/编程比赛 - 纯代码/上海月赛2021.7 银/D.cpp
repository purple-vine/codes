#include <cstdio>
#define int long long
using namespace std;
int n,m;
int c(int n,int m){
	int ans=1;
	for(int i=m;i>=m-n+1;i--) ans*=i;
	for(int i=n;i>=1;i--) ans/=i;
	return ans;
}
main(){
	scanf("%lld%lld",&n,&m);
	int ans=c(3,(n+1)*(m+1)),ans2=0;
	for(int x1=0;x1<=n;x1++){
		for(int x2=x1;x2<=n;x2++){
			for(int y1=0;y1<=m;y1++){
				for(int y2=0;y2<=m;y2++){
					if(x1==x2&&y1==y2) continue;
					if(0<=y1*2-y2 && y1*2-y2<=m && x1*2-x2>=0 && x1*2-x2<=n) {
						//printf("%d %d %d %d\n",x1,y1,x2,y2);
						ans2++;
					}
					if(0<=y2*2-y1 && y2*2-y1<=m && x2*2-x1<=n && x2*2-x1>=0) {
						//printf("%d %d %d %d\n",x1,y1,x2,y2);
						ans2++;
					}
				}
			}
		}
	}
	printf("%lld",ans-ans2/2);
	return 0;
}
