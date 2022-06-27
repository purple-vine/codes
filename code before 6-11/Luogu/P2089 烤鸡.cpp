#include <stdio.h>
#include <iostream>
using namespace std;
int a[15];
int b[10000][15];
long long ans;
bool flag=true;
void dfs1(int num,int step){
	if(num<0) return;
	if(step==11&&num==0){
		flag=false;
		ans++;
		for(int i=1;i<=10;i++) b[ans][i]=a[i];
		//cout << endl;
		return;
	}
	for(int i=1;i<=3;i++){
		a[step]=i;
		dfs1(num-i,step+1);
		a[step]=0;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	if(n<10||n>30){
		cout << 0;
		return 0;
	}
	dfs1(n,1);
	cout << ans<<endl;
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=10;j++) printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}
