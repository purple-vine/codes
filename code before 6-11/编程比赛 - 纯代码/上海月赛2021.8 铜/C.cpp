#include <cstdio>
#include <cmath>
using namespace std;
int n,a[10],t;
void dfs(int n,int s,int l){
	if(l*l>n) return;
	if(s==3){
		int t=sqrt(n);
		if(t*t!=n) return;
		for(int i=0;i<3;i++) printf("%d ",a[i]);
		printf("%d\n",t);return;
	}
	for(int i=l;i*i<=n;i++){
		a[s]=i;dfs(n-i*i,s+1,i);
	}
}
int main(){
	scanf("%d",&n);
	dfs(n,0,0);
}
