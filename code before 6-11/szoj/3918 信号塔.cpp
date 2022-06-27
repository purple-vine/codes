#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int p=998244353;
inline int qpow(int a,int b,int p){
	int ans=1;
	for(;b;b>>=1){
		if(b&1) ans=(ans*a)%p;
		a=(a*a)%p;
	}
	return ans;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a;
		a=a*a;
	}
	return ans;
}
int niyuan(int a,int b,int p){
	return (a*qpow(b,p-2,p))%p;
}
int n,ans[2000005];
int dfs(int u){
	if(u==n) return 1;
	if(u>n) return 0;
	if(ans[u]) return ans[u];
	for(int i=1;i<=min(u,(n-u+1)/2);i++){
		ans[u]+=dfs(u+i);
	}
	return ans[u];
}
main(){
	scanf("%lld",&n); 
	//for(int i=1;i<=n*n;i++) printf("%lld\n",niyuan(i,qpow(2,n),p));
	int ans=dfs(1);printf("%lld\n",ans);
	printf("%lld",niyuan(ans,qpow(2,n,p),p));
	return 0;
}
