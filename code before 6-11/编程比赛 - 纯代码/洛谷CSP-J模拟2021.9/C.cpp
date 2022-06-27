#include <cstdio>
#include <unistd.h>
#include <algorithm>
#define did() {printf("QED");exit(0);}
using namespace std;
const int M=300005;
int w[M<<2][2],laz[M<<2];bool f;
void pushdown(int o,int l,int r){
	if(!laz[o]) return;
	int t=(laz[o]+1)/2,mid=(l+r)>>1;
	if(!w[o<<1][!t]) {w[o<<1][t]=mid-l+1;laz[o<<1]=2*t-1;}
	else did()
	if(!w[o<<1|1][!t]) {w[o<<1|1][t]=r-mid;laz[o<<1|1]=2*t-1;}
	else did()
	laz[o]=0;
}
void add(int o,int l,int r,int x,int y,int t){
	if(x>y) return;
	if(x<=l&&r<=y){
		if(!w[o][!t]) {w[o][t]=r-l+1;laz[o]=2*t-1;return;}
		else did()
	}
	int mid=(l+r)>>1;pushdown(o,l,r);
	if(x<=mid) add(o<<1,l,mid,x,y,t);
	if(y>mid) add(o<<1|1,mid+1,r,x,y,t);
	w[o][0]=w[o<<1][0]+w[o<<1|1][0];
	w[o][1]=w[o<<1][1]+w[o<<1|1][1];
}
void check(int o,int l,int r){
	if(l==r){
		if(s[o]==-1) nxt[l-1]=l+1;
		else nxt[l+1]=l-1;
		return;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	check(o<<1,l,mid); check(o<<1|1,mid+1,r);
}
void dfs(int u){
	if(!nxt[u]){
		nxt[u]=cnt;
	}
}
int n,q,s,t,nxt[M],deg[M];
int main(){
	scanf("%d %d",&n,&q);
	while(q--){
		scanf("%d %d",&s,&t);
		if(s<t) add(1,2,n-1,(s>1 ? s:2), t-1, 0);
		else if(s>t) {swap(s,t);add(1,2,n-1,(s>1 ? s:2),t-1,1);}
		else did()
	}
	check(1,2,n-1);
}
