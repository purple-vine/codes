#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int m,c,o,i,n;
char s[15];
main(){
	scanf("%lld",&n);
	for(int j=1;j<=n;j++){
		scanf("%s",s);
		if(s[0]=='M') m++;
		if(s[0]=='C') c++;
		if(s[0]=='O') o++;
		if(s[0]=='I') i++;
	}
	printf("%lld",m*c*o+m*c*i+c*o*i+m*o*i);
	return 0;
} 
