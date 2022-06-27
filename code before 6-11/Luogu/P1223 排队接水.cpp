#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct v{
	int b,t;
}a[1005];
int n;
double ans;
bool cmp(v a,v b){
	return a.t<b.t;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].t;
		a[i].b=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout << a[i].b << " ";
		ans+=a[i].t*(n-i);
	}
	printf("\n%.2lf",(double)ans/n);
	return 0;
} 
