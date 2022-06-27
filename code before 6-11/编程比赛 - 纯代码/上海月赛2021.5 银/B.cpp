#include <iostream>
#include <cstdio>
#include <time.h>
#define ll long long
using namespace std;
ll a[100005]={0,3,4,2,3,5};
ll b[100005*3]={0,a[1]};
int n=5;
//2*(n+1) 
int main(){
	//scanf("%lld",&a[1]);
	//b[1]=a[1];
	for(int i=2;i<=n;i++){
		//scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
		cout << b[i] << endl;
	}
	for(int i=n+1;i<=100;i++){
		a[i]=0;
		for(int j=i-n;j<i;j++){
			a[i]^=a[j];
		}
		b[i]=b[i-1]^a[i];
		cout << b[i] << endl;
	}
	return 0;
}
