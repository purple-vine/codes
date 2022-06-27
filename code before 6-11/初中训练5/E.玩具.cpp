#include <iostream>
#include <stdio.h>
#define int long long
using namespace std;
const int M=100005;
int a[M],s[4*M];
void make_segement_tree(int o,int l,int r){
	if(l==r){
		scanf("%d",&a[l]);
		s[o]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	make_segement_tree(o<<1,l,mid);
	make_segement_tree(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}

long long Query(int o,int x,int y,int l,int r){
	long long sum=0;
	if(l>=x&&r<=y){
		return (long long)s[o];
	}
	int mid=(l+r)>>1;
	if(x<=mid) sum+=Query(o<<1,x,y,l,mid);
	if(y>mid) sum+=Query(o<<1|1,x,y,mid+1,r);
	return sum;
}

long long t,n,l,r,k,w,m,sum;
main(){
	scanf("%lld%lld",&t,&n);
	make_segement_tree(1,1,n);
	while(t--){
		scanf(" %lld%lld%lld%lld",&l,&r,&k,&w);
		if(Query(1,l,r,1,n)%k==0) sum+=w;
		else sum-=w;
	}
	scanf("%lld",&m);
	printf("%lld",m+sum);
	return 0;
}
