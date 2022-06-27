#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[10100],n,v,b[30];
int main(){
	a[0]=1;
	scanf("%d%d",&v,&n);
	for(int i=1;i<=v;i++){
		scanf("%d",&b[i]);
	}
	sort(b+1,b+v+1);
	for(int i=1;i<=v;i++){
		for(int j=b[i];j<=n;j++){
			a[j]+=a[j-b[i]];
		}
	}
	printf("%lld",a[n]);
} 
