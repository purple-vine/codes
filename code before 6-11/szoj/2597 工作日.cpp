#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int M=200005;
ll n,m,a[M],s[4*M],laz[4*M],ans;
void pushdown(ll o,ll l,ll r){
	if(laz[o]==-1) return;
	ll mid=(l+r)>>1;
	s[o<<1]=(mid-l+1)*laz[o];
	laz[o<<1]=laz[o];
	s[o<<1|1]=(r-mid)*laz[o];
	laz[o<<1|1]=laz[o];
	laz[o]=-1;
}

void make_segement_tree(ll o,ll l,ll r){
	laz[o]=-1;
	if(l==r){
		s[o]=1;
		return;
	}
	ll mid=(l+r)>>1;
	make_segement_tree(o<<1,l,mid);
	make_segement_tree(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
} 
void xiu_gai(ll o,ll x,ll y,ll k,ll l,ll r){
	if(x<=l&&r<=y){
		s[o]=(r-l+1)*k;
		laz[o]=k;
		return;
	}
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	if(x<=mid) xiu_gai(o<<1,x,y,k,l,mid);
	if(y>mid) xiu_gai(o<<1|1,x,y,k,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}

int main(){
	scanf("%lld%lld",&n,&m);
	make_segement_tree(1,1,n);
	ll c;
	ll x,y,k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&k);
		xiu_gai(1,x,y,k-1,1,n);
		printf("%lld\n",s[1]);
	}
	return 0;
}
