#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	int t=a+b+c;
	t/=2;
	printf("%d\n%d\n%d\n",t-b,t-c,t-a);
	return 0;
}
