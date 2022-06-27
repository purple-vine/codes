#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXNUM=1000000005;
int n,q;
struct line{
	int pos,
	num;
}a[MAXNUM];
bool cmp(line a,line b){
	return a.num>b.num;
}
int main(){
	//freopen("bowling.in","r",stdin);
	//freopen("bowling.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].num);
		a[i].pos=i;
	}
	
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int m;
		scanf("%d",&m);
		int l=1,r=n,ans=0,mid;
		while(l<=n){
			mid=(l+r)/2;
			if(a[mid].num==m){
				ans=a[mid].pos;
				break;
			}
			else if(a[mid].num<m) l=mid+1;
			else r=mid-1;
		}
		printf("%d",ans);
	}
	return 0;
}
