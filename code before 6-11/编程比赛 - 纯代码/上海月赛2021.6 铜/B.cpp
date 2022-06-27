#include <iostream>
#include <cstdio>
#define W printf("*")
#define S printf("\n")
#define D1 for(int i=1;i<=2*n-1;i++) {W;}\
	S;
#define D2 for(int i=1;i<=n-1;i++){\
		W;\
		for(int j=1;j<=2*n-2;j++) printf(" ");\
		W;S;\
	}
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	D1 
	D2
	D1
	D2
	D1
	return 0;
}
