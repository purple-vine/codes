#include <iostream>
#include <cstdio>
#include <algorithm>
#define l cl[i].n
using namespace std;
char a[105];
int n;
struct C{
	int a,b,c,d,n,p;
}cl[10005];
bool cmp(C a,C b){
	if(a.a*b.n!=b.a*a.n) return a.a*b.n>b.a*a.n;
	if(a.b*b.n!=b.b*a.n) return a.b*b.n>b.b*a.n;
	if(a.c*b.n!=b.c*a.n) return a.c*b.n>b.c*a.n;
	if(a.d*b.n!=b.d*a.n) return a.d*b.n>b.d*a.n;
	return a.p<b.p;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",a);
		cl[i].p=i;
		while(a[l]!='\0'){
			l++;
			if(a[l]=='A') cl[i].a++;
			if(a[l]=='B') cl[i].b++;
			if(a[l]=='C') cl[i].c++;
			if(a[l]=='D') cl[i].d++;
		}
	}
	sort(cl+1,cl+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%d ",cl[i].p);
	}
	return 0;
}
