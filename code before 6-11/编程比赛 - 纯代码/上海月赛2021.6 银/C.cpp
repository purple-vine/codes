#include <cstdio>
#include <algorithm>
#pragma GCC optimize(2)
using namespace std;
const int M=100005;
int c[M],l,ans,n,p[M];
pair<int,int>a[M];
bool m[M];
int s[4*M];
inline int read()
{
    register char ch=getchar();
    register int x=0;
    register bool b=0;
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    (ch=='-')&&(ch=getchar(),b=1);
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    if(b)return -x;
    return x;
}
void build(int o,int l,int r){
	if(l==r){
		s[o]=c[l];
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
} 
void xiu_gai(int o,int x,int t,int l,int r){
	if(l==x&&l==r){
		s[o]=t;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) xiu_gai(o<<1,x,t,l,mid);
	else xiu_gai(o<<1|1,x,t,mid+1,r);
	s[o]=s[o<<1]+s[o<<1|1];
}
int Query(int o,int x,int y,int l,int r){
	long long sum=0;
	if(l>=x&&r<=y){
		return s[o];
	}
	int mid=(l+r)>>1;
	if(x<=mid) sum+=Query(o<<1,x,y,l,mid);
	if(y>mid) sum+=Query(o<<1|1,x,y,mid+1,r);
	return sum;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		c[i]=read();p[i]=read();
		a[i]=(make_pair(p[i],i));
	}
	build(1,1,n);
	sort(a+1,a+n+1);
	for(int q=1;q<=n;q++){
		int t=a[q].second;
		if(Query(1,1,t,1,n)<p[t]) continue;
		ans++;
		int k=t;
		while(p[t]>0){
			if(c[k]>=p[t]) {xiu_gai(1,k,c[k]-p[t],1,n);c[k]-=p[t];p[t]=0;break;}
			xiu_gai(1,k,0,1,n);p[t]-=c[k];c[k]=0;k--;
		}
	}
	printf("%d",ans);
	return 0;
}
