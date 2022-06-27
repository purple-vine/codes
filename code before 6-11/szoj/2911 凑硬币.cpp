#include <cstdio>
#include <iostream>
using namespace std;
int a[100005],n;
int main(){
	scanf("%d",&n);
	a[1]=a[5]=a[11]=1;a[2]=a[6]=a[10]=2;a[3]=a[7]=3;a[4]=a[8]=4;a[9]=5;
	for(int i=12;i<=n;i++){
		a[i]=min(a[i-1],min(a[i-5],a[i-11]))+1;
	}
	printf("%d",a[n]);
	return 0;
}
