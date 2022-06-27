#include <cstdio>
#include <cmath>
using namespace std;
int a,b,c;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	int m=max(max(a,b),c);
	printf("%d\n",3*m-a-b-c);
	return 0;
}
