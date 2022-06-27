#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,ans,a[150][150]={0};
char c;
int getsum(int x1,int y1,int x2,int y2){
	return a[x2][y2]+a[x1-1][y1-1]-a[x1-1][y2]-a[x2][y1-1];
}
int main(){
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%c",&c);
			//printf("%c\n",c);
			a[i][j]=(c=='W'?0:1);
		}
		getchar();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
//			printf("%d",a[i][j]);
		}
//		printf("\n");
	}
	for(int x1=1;x1<=n;x1++){
		for(int x2=x1;x2<=n;x2++){
			for(int y1=1;y1<=n;y1++){
				for(int y2=y1;y2<=n;y2++){
//					printf("%d %d %d %d\n",x1,y1,x2,y2);
					if(getsum(x1,y1,x2,y2)==0){
						ans++;
						//printf("%d %d %d %d\n",x1,y1,x2,y2);
					}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
