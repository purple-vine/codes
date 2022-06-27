#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct coins{
	int m,v;
	double price;
}c[105];
bool cmp(coins a,coins b){
	return a.price>b.price;
}
int n,t,v,k,m;//m:重量,v:价值 
int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
    	scanf("%d%d",&c[i].m,&c[i].v);
    	c[i].price=(double)c[i].v/c[i].m;
	}
	sort(c,c+n,cmp);
	//for(int i=0;i<n;i++) printf("%d\n",c[i].m);
	//cout << t;
	for(int i=0;i<n;i++){
		if(m+c[i].m>=t){
			cout << 1;
			v+=c[i].price*(t-m);
			break;
		}
		else{
			cout << 2;
			m=m+c[i].m;
			v=v+c[i].v;
		}
		printf("%d %d %f %f\n",c[i].m,c[i].v,m,v);
	}
	printf("%.2lf",v);
	return 0;
}
