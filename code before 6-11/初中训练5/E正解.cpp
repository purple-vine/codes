#include <iostream>
#include <cstdio>
using namespace std;
const int M=100005;
int l,r,t,n,k,w,s;
long long a[M],ans;
int main(){
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	bool f=0;
	while(t--){
		scanf(" %d%d%d%d",&l,&r,&k,&w);
		for(int i=l-1;i<r;i++){
			for(int j=i+1;j<=r;j++){
				if((a[j]-a[i])%k==0){
					f=1;
					//printf("%d %d\n",i+1,j);
					ans+=(long long)w;
					break;
				}
			}
			if(f) break;
		}
		if(!f) ans-=(long long)w;
		f=0;
	}
	scanf("%d",&s);
	printf("%lld",s+ans);
	return 0;
}
