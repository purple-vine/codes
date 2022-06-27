#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n,k,ans,mid,lt,r,d;
long long l,a[10000005],minn=1000000005;
int read(){//¿ì¶Á
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool check(int s){
	long long ans=0,t=a[1],i=2;
	while(i<n){
		if(a[i]-t<s) ans++,i++;
		else t=a[i],i++;
	}
	return ans<=k;
}//0 2 11 14 17 21 25
int main(){
    cin >> l >> n >> k;
    a[1]=0,a[n+2]=l,n+=2;
    for(int i=2;i<=n-1;i++) a[i]=read(),minn=min(minn,a[i]-a[i-1]);
    minn=min(minn,a[n]-a[n-1]);
    lt=minn;
    r=l;
    while(lt<=r){
    	mid = (lt+r)/2;
    	//printf("%d %d %d\n",lt,mid,r);
    	if(check(mid)) {ans=mid;lt=mid+1;}
    	else r=mid-1;
	}
    
	cout << ans;
}
