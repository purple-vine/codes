#include <iostream>
#include <stdio.h>
#include <cmath>
#define int long long
using namespace std;
const int M=100005;
int n,m,s[4*M];
void make_segement_tree(int o,int l,int r){
	if(l==r){
		scanf("%d",&s[o]);
		return;
	}
	int mid=(l+r)>>1;
	make_segement_tree(o<<1,l,mid);
	make_segement_tree(o<<1|1,mid+1,r);
	s[o]=min(s[o<<1],s[o<<1|1]);
}

int get_min(int o,int x,int y,int l,int r){
	if(x<=l&&r<=y) return s[o];
	int ans=1e13;
	int mid=(l+r)>>1;
	if(x<=mid) ans=min(ans,get_min(o<<1,x,y,l,mid));
	if(y>mid) ans=min(ans,get_min(o<<1|1,x,y,mid+1,r));
	return ans;
}

main(){
	scanf("%d%d",&n,&m);
	make_segement_tree(1,1,n);
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",get_min(1,a,b,1,n));
	}
	return 0;
}
