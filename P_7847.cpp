#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
long long m[500005],t,maxx,sum[500005],num[200005],two[200005]={1};
vector<int>f[500005];
void deal(long long n){
	for(long long i=2;i<=n;i++) {if(num[i]==0) 
		for(long long j=1;j*i<=n;j++){
			num[i*j]++;
			f[i*j].push_back(i);
		}
	}
	for(long long i=1;i<=log(n)/log(2);i++) two[i]=two[i-1]*2;
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+two[num[i]-1];
}
long long a[20];
long long get(long long t){
	long long n=f[t].size();long long ans=t*t;
	memset(a,0,sizeof(a));
	for(long long i=0;i<15;i++) a[i]=1;
	long long r=t;
	for(long long i=0;i<n;i++){
		while(r%f[t][i]==0) {r/=f[t][i];a[i]*=(long long)f[t][i];}
	}
	for(long long i=0;i<n;i++) a[i]*=a[i];
	for(long long i=1;i<((1<<n)-1);i++){
		long long s=1;
		for(long long j=0;j<n;j++){
			if((i>>j)&1) s*=a[j];
		}
		if(s>t) ans=min(ans,s);
	}
	return ans;
}
int main(){
	scanf("%lld",&t);
	for(int i=1;i<=t;i++) {scanf("%lld",&m[i]);maxx=max(maxx,m[i]);}
	deal(maxx);
	for(int i=1;i<=t;i++){
		//get(m[i]-c);
		if(m[i]==1) printf("0\n");
		else printf("%lld %lld\n",sum[m[i]],get(m[i])-m[i]);
	}
}