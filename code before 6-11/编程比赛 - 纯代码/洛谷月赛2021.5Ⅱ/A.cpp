#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
int n,k,s,t;
int getsum(int a,int b){
	return (a+b)*(b-a+1)/2;
}
main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld",&n,&k,&s);
		if(k==1){
			if(s<=n&&s>=1) puts("Yes");
			else puts("No");
			continue;
		}
		if(getsum(n-k+1,n)<s) {puts("No");continue;}
		if(getsum(1,k)>s) {puts("No");continue;}
		puts("Yes");
	}
	return 0;	
} 
