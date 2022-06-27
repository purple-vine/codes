#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int M=100005;
ll n,m,a[M],s[4*M],laz1[4*M],laz2[4*M],p;
void pushdown2(ll,ll,ll);
void pushdown1(ll o,ll l,ll r){
	if(laz1[o]==0||o>4*n) return;
	ll mid=(l+r)>>1;
	pushdown2(o<<1,l,mid);
	pushdown2(o<<1|1,mid+1,r); 
	s[o<<1]+=laz1[o]*(mid-l+1);
	laz1[o<<1]+=laz1[o];
	s[o<<1|1]+=laz1[o]*(r-mid);
	laz1[o<<1|1]+=laz1[o];
	laz1[o]=0;
	s[o<<1]%=p;
	s[o<<1|1]%=p;
}
void pushdown2(ll o,ll l,ll r){
	if(laz2[o]==1||o>4*n) return;
	ll mid=(l+r)>>1;
	pushdown1(o<<1,l,mid);
	pushdown1(o<<1|1,mid+1,r); 
	s[o<<1]*=laz2[o];
	laz2[o<<1]*=laz2[o];
	s[o<<1|1]*=laz2[o];
	laz2[o<<1|1]*=laz2[o];
	laz2[o]=1;
	s[o<<1]%=p;
	s[o<<1|1]%=p;
}
void make_segement_tree(ll o,ll l,ll r){
	if(o==1){
		for(int i=1;i<=4*n;i++) laz2[i]=1;
	}
	if(l==r){
		scanf("%lld",&a[l]);
		s[o]=a[l];
		s[o]%=p;
		return;
	}
	ll mid=(l+r)>>1;
	make_segement_tree(o<<1,l,mid);
	make_segement_tree(o<<1|1,mid+1,r);
	s[o]=(s[o<<1]+s[o<<1|1])%p;
} 
void xiu_gai1(ll o,ll x,ll y,ll t,ll l,ll r){
	if(x<=l&&r<=y){
		s[o]+=(r-l+1)*t;
		if(laz2[o]) pushdown2(o,l,r);
		laz1[o]+=t;
		return;
	}
	pushdown1(o,l,r);
	pushdown2(o,l,r);
	ll mid=(l+r)>>1;
	if(x<=mid) xiu_gai1(o<<1,x,y,t,l,mid);
	if(y>mid) xiu_gai1(o<<1|1,x,y,t,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}
void xiu_gai2(ll o,ll x,ll y,ll t,ll l,ll r){
	if(x<=l&&r<=y){
		s[o]*=t;
		if(laz1[o]) pushdown1(o,l,r);
		laz2[o]*=t;
		return;
	}
	pushdown1(o,l,r);
	pushdown2(o,l,r);
	ll mid=(l+r)>>1;
	if(x<=mid) xiu_gai2(o<<1,x,y,t,l,mid);
	if(y>mid) xiu_gai2(o<<1|1,x,y,t,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}
long long Query(ll o,ll x,ll y,ll l,ll r){
	long long ans=0;
	if(l>=x&&r<=y){
		return s[o];
	}
	pushdown1(o,l,r);
	pushdown2(o,l,r);
	ll mid=(l+r)>>1;
	if(x<=mid) ans+=Query(o<<1,x,y,l,mid);
	if(y>mid) ans+=Query(o<<1|1,x,y,mid+1,r);
	return ans%p;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	make_segement_tree(1,1,n);
	ll c;
	ll x,y,k;
	for(int i=1;i<=m;i++){
		scanf(" %lld",&c);
		if(c==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			xiu_gai2(1,x,y,k,1,n);
		}
		else if(c==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			xiu_gai1(1,x,y,k,1,n);
		}
		else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",Query(1,x,y,1,n));
		}
	}
	return 0;
}
