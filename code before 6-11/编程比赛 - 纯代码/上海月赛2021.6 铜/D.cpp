#include <iostream>
#include <cstdio>
using namespace std;
const int M=1005;
int a[M][M],n,m;
char read(){
	char c;
	while(c=getchar()){
		if(c=='.'||c=='#') return c;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c=read();
			if(c=='#'){
				for(int k=j;k<=m;k++) a[i][k]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
