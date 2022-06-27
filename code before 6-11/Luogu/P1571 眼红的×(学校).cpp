#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[100005],b[100005],num,c[100005];
bool find(int a){
	if(b[lower_bound(b+1,b+m+1,a)-b]==a) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++){
		if(find(a[i])==1) c[++num]=a[i];
	}
	for(int i=1;i<=num;i++) printf("%d ",c[i]);
}
