#include <stdio.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		printf("+");
		for(int j=1;j<=k;j++) printf("-");
	}
	printf("+");
	return 0;
}
