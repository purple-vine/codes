#include <iostream>
using namespace std;
int a,c;
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			c=getchar()-'0';
//			printf("%d",c);
			a<<=1;a+=c;
		}
		printf("%d%c",a,i==3?' ':'.');
		a=0;
	}
	return 0;
}
