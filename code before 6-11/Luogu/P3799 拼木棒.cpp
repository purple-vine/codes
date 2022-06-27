#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,a[10005],b[10005],c[10005],n2=1;
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]++;
	sort(a+1,a+n+1);
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=c[n2]) c[++n2]=a[i];
	}
	for(int i=1;i<=n;i++) cout << a[i] << " ";
	cout << "\n";
	for(int i=1;i<=n2;i++) cout << c[i] << " ";
	for(int i=1;i<n2;i++){
		for(int j=i+1;j<=n2;j++){
			if(b[c[i]+c[j]]>=2){
				ans=(ans+1)%1000000007;
			}
		}
		for(int i=1;i<=n2;i++){
			if(b[c[i]]>=2&&b[2*c[i]]>=2) ans=(ans+1)%1000000007;
		}
	}
	cout << ans;
}
