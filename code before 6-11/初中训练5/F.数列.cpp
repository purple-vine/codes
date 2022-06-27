#include <iostream>
#include <cstdio>
#include <algorithm>
#pragma GCC optimize(2)
using namespace std;
const int M =2000000;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,k,f,t,a[M],m=2*1e6+5;

bool check(int k,int f,int t){
	//if(t<=k) return 1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]%t<=k&&a[i]>=t) cnt++;
	}
	//printf("%d %d\n",t,n-cnt);
	return n-cnt<=f;
}
int main(){
	t=read();
	while(t--){
		n=read();k=read();f=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]>k) m=min(m,a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++) if(a[i+1]!=a[i]) m=min(m,a[i+1]-a[i]+2*k);
		//cout << m << endl;
		for(int i=1;i<=m;i++){
			if(check(k,f,i)){
				printf("%d ",i);
			}
		}
		printf("\n");
		m=2*1e6+5;
	}
	return 0;
}
/*
1
5 3 1
5 6 7 8 9 10
*/
