#include <stdio.h>
#include <algorithm>
using namespace std;
int a,b,c,n;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		//printf("%d %d %d\n",a,b,c);
		if(a==b&&a==0){
			printf("0\n");
		}
		else if(a==0){
			if(b==c) printf("1\n");
			else printf("2\n");
		}
		else{
			if((a+b==c)||(a==b||b==c||c==a)) printf("2\n");
			else{
				printf("3\n");
			}
		}
	}
	return 0;
} 
