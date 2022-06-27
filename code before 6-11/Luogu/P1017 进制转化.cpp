#include <iostream>
#include <cstdio>
#include <vector>
#define abs(p) p>0?p:-p
using namespace std;
int n,r;
char e[25]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
void mod(int a,int p){
	if(a==0) return;
	int m=a%p;
	if(m<0) m+=abs(p),mod((a-m)/p,p);
	else mod(a/p,p);
	printf("%c",e[m]);
}
int main(){
	scanf("%d%d",&n,&r);
	printf("%d=",n);
	mod(n,r);
	printf("(base%d)",r);
	return 0;
} 
