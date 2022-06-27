#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
const int M=200005;
ll n,m,a[M],s[4*M],laz[4*M],ans;
void pushdown(ll o,ll l,ll r){
	if(laz[o]==0) return;
	ll mid=(l+r)>>1;
	s[o<<1]=mid-l+1-s[o<<1];
	laz[o<<1]^=laz[o];
	s[o<<1|1]=r-mid-s[o<<1|1];
	laz[o<<1|1]^=laz[o];
	laz[o]=0;
}

void make_segement_tree(ll o,ll l,ll r){
	if(l==r){
		a[l]=getchar()-'0';
		s[o]=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	make_segement_tree(o<<1,l,mid);
	make_segement_tree(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
} 
void xiu_gai(ll o,ll x,ll y,ll l,ll r){
	if(x<=l&&r<=y){
		s[o]=r-l+1-s[o];
		laz[o]^=1;
		return;
	}
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	if(x<=mid) xiu_gai(o<<1,x,y,l,mid);
	if(y>mid) xiu_gai(o<<1|1,x,y,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}
void Query(ll o,ll x,ll y,ll l,ll r){
	if(l>=x&&r<=y){
		ans+=s[o];
		return;
	}
	pushdown(o,l,r);
	ll mid=(l+r)>>1;
	if(x<=mid) Query(o<<1,x,y,l,mid);
	if(y>mid) Query(o<<1|1,x,y,mid+1,r);
}
int main(){
	scanf("%lld%lld",&n,&m);
	getchar();getchar();
	make_segement_tree(1,1,n);
	//for(int i=1;i<=n;i++) cout << a[i] << " ";
	//cout << endl;
	ll c;
	ll x,y,k;
	for(int i=1;i<=m;i++){
		scanf("%lld",&c);
		if(c==0){
			scanf("%lld%lld",&x,&y);
			xiu_gai(1,x,y,1,n);
		}
		else{
			scanf("%lld%lld",&x,&y);
			ans=0;
			Query(1,x,y,1,n);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
