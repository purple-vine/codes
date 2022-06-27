#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
long long a[45]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776};
int n,t[65];
int f(long long b){
	for(int i=1;i<=40;i++) if(a[i]==b) return i;
}
long long pow(int a,int b){
	long long sum=1;
	for(int i=1;i<=b;i++) sum*=a;
	return sum;
}
int main(){
	long long maxx=-1,minn=1099511627777;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long r;
		cin >> r;
		t[f(r)]++;
		minn=min(minn,r);
		maxx=max(maxx,r);
	}
	//cout << maxx <<" "<< minn << endl;
	minn=f(minn);
	maxx=f(maxx);
	//cout << minn << " " << maxx << endl;
	int i;
	for(i=minn;i<=maxx+21;i++){
		//cout << i << " ";
		t[i+1]+=t[i]/2;
		t[i]=t[i]%2;
	}
	//cout << i << endl;
	//for(int j=1;j<=i;j++) cout << t[j] << " ";
	while(t[i]==0) i--;
	//for(int j=1;j<=i;j++) cout << t[j] << " ";
	//cout << endl;
	cout << pow(2,i);
}
