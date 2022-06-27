#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int t,n,m;
int poww(int a,int b){
	int s=1;
	for(int i=1;i<=b;i++) s*=a;
	return s;
}
int main(){
	scanf("%d",&t);
	for(int r=0;r<t;r++){
		scanf("%d %d",&n,&m);
		if(n==1){
			if(m==1) printf("-1");
			else printf("%d\n1",m);
			continue; 
		}
		bool f=true;
		int i=0,k=0;
		while(k<m){
			k+=poww(3,i);
			i++;
		}
		if(k==m) {printf("-1");continue;}
		printf("1");
	}
}
