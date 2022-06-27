#include <cstdio>
using namespace std;
int a,b,x,y,i;
int main(){
	scanf("%d %d %d %d",&a,&b,&x,&y);
	if(a<=b&&x<=y) {printf("Impossible");return 0;}
	for(i=0;a<=b;i++,a+=x,b+=y) ;
	printf("%d",i);
}
