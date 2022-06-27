#include <iostream>
#include <cstdio>
#define max(a,b) a>b?a:b
#define int long long
using namespace std;
int n,a,b;
main(){
	scanf("%lld",&n);
	if(n==1){
		scanf("%lld",&a);
		printf("%lld",a);
		return 0;
	}
	else if(n==2){
		scanf("%lld %lld",&a,&b);
		if(a==0&&b==0) {printf("0\n");return 0;}
		printf("%lld",a==b?a+1:max(a,b));
		return 0;
	}
	return 0;
}
