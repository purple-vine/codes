#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int M=100005;
int s[M<<1],a[M],c[M],laz[M<<1],ans,n;
pair<int,int>p[M];
void pushdown(int o,int l,int r){
	int mid=(l+r)>>1;
	laz[o<<1]+=laz[o];laz[o<<1|1]+=laz[o];
	s[o<<1]+=(mid-l+1)*laz[o];s[o<<1|1]+=(r-mid)*laz[o];
	laz[o]=0;
}
void build(int o,int l,int r){
	if(l==r) {s[o]=a[l];return;}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}
void add(int o,int l,int r,int x,int y,int t){
	if(l>=x&&r<=y) {laz[o]+=t;s[o]+=(r-l+1)*t;return;}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) add(o<<1,l,mid,x,y,t);
	if(mid+1<=y) add(o<<1|1,mid+1,r,x,y,t);
	s[o]=s[o<<1]+s[o<<1|1];
}
int query(int o,int x,int y,int l,int r){
	if(l>=x&&r<=y) return s[o];
	int ans=0;pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) ans+=query(o<<1,x,y,l,mid);
	if(y>mid) ans+=query(o<<1|1,x,y,mid+1,r);
	return ans;
}
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i],&p[i].first,&c[i]);
		p[i].second=i;p[i].first=-p[i].first;
	}
	build(1,1,n);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		int t=p[i].second,num=query(1,1,t,1,n);
		printf("%d %d %d\n",i,t,num);
		if(num>c[t]){
			ans-=c[t]*p[i].first;
			add(1,1,n,t-1,t-1,-num+c[t]);
		}
		else{
			ans+=c[t]*num;
			add(1,1,n,t+1,n,-num);
		}
		printf("%lld\n",ans);
	}
	printf("%lld",ans);
	return 0;
}
