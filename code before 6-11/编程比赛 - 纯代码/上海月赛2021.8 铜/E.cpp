#include <cstdio>
using namespace std;
const int M=25;
int a[M],t,n;
bool dfs(int sum,int s){
	if(sum>t) return 0;
	if(s==n+1) return sum==t;
	return dfs(sum+a[s],s+1)|dfs(sum,s+1);
}
int main(){
	scanf("%d %d",&n,&t);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(dfs(0,1)) printf("Yes");
	else printf("No");
}
