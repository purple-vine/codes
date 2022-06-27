#include <cstdio>
#include <iostream>
using namespace std;
int n,m,l,r,mid,maxx,ans,a[300005][10];
bool vis[1<<9+5];
bool check(int t){
	printf("%d:",t);
	for(int i=1;i<(1<<m);i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=m;j++) s=(s*2+(int)(a[i][j]>=t));
		vis[s]=1;printf("%d ",s);
	}printf("\n");
	for(int i=1;i<(1<<m);i++){
		for(int j=1;j<(1<<m);j++){
			if(i!=j&&vis[i]&&vis[j]&&(i|j)!=((1<<m)-1)){
				printf("%d %d %d %d\n",i,j,(i|j),((1<<m)-1));return 0;
			}
		}
	}
	return 1;
}
int main(){
	printf("%d\n",(13|15));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {scanf("%d",&a[i][j]);maxx=max(maxx,a[i][j]);}
	l=0;r=maxx;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) {ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("\n%d",ans);
} 
