#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
struct zuo_biao{
	int x,y,z;
}point[50005];
int poww(int a,int b){
	int ans1 = 1;
	for(int i=1;i<=b;i++) ans1*=a;
	return ans1;
}
double ans;
int n,cx,cy,cz;
double dis(zuo_biao a,zuo_biao b){
	return sqrt(poww(a.x-b.x,2)+poww((a.y-b.y),2)+poww((a.z-b.z),2));
}
bool cmp(struct zuo_biao a,struct zuo_biao b){
	return a.z < b.z;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&point[i].x,&point[i].y,&point[i].z);
	}
	sort(point+1,point+n+1,cmp);
	//for(int i=1;i<=n;i++) printf("%d %d %d\n",point[i].x,point[i].y,point[i].z);
	for(int i=1;i<n;i++){
		ans+=dis(point[i+1],point[i]);
		//cout << ans << endl;
	}
	//for(int i=1;i<n;i++){
		//ans+=sqrt(abs(cx-point[i].x)*abs(cx-point[i].x)+abs(cy-point[i].y)*abs(cy-point[i].y)+abs(cz-point[i].z)*abs(cz-point[i].z));
	//}
	printf("%.3lf",ans);
}
