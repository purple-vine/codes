#include <iostream>
#include <cstdio>
#include <cstring>
#pragma GCC optimize(2)
using namespace std;
string a[1000005];
int x1,y1,x2,y2,l,c,n,m,q;
int cal(int x,int y){
	return (x-1)*m+y;
}
void readstring(int t){
	char c=getchar();
	while(c>='a'&&c<='z'){
		a[t]=c+a[t];
		c=getchar();
	}
}
void write(int t){
	int l=a[t].length();
	while(--l) putchar(a[t][l]);
	putchar(a[t][0]);
	putchar(' ');
}
int readint(){
	int x=0;char c=getchar();
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x;
}
int main(){
	n=readint();m=readint();q=readint();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) readstring(cal(i,j));
	}
	while(q--){
		x1=readint();y1=readint();x2=readint();y2=readint();l=readint();c=readint();
		for(int i=0;i<l;i++){
			for(int j=0;j<c;j++){
				swap(a[cal(x1+i,y1+j)],a[cal(x2+i,y2+j)]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) write(cal(i,j));
		putchar('\n');
	}
}
