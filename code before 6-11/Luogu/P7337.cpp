#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,type,num;
struct people{
	bool t,q;
}p[105];
int main(){
	scanf("%d%d%d",&n,&m,&type);
	for(int i=1;i<=n;i++){
		cin >> p[i].q;
	}
	for(int i=1;i<=n;i++){
		cin >> p[i].t;
		if(p[i].q&&p[i].t) num++;	
	}
	if(num>=m) num-=m;
	printf("%d",n-num);
}
