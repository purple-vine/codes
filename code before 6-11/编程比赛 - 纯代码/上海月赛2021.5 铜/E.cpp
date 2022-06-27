#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long
using namespace std;
struct A{
	int x,y;
}a[200005];
bool cmp1(A a,A b){
	return a.x<b.x;
}
bool cmp2(A a,A b){
	return a.y<b.y;
}
int n;
int ans;
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
	}
	int t=(n+1)/2;
	sort(a+1,a+n+1,cmp1);
	int x=a[t].x;
	sort(a+1,a+n+1,cmp2);
	int y=a[t].y;
	//cout << x << " " << y << endl; 
	for(int i=1;i<=n;i++){
		//printf("%d %d\n",a[i].x,a[i].y);
		ans+=abs(a[i].x-x)+abs(a[i].y-y);
	}
	printf("%lld",ans);
	return 0;
}
