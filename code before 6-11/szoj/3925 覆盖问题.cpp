#include <cstdio>
#include <iostream>
#include <cstring>
#define inf 1e9
using namespace std;
const int M=20005;
int n,x[M],y[M],l,r,m,maxx=-inf,maxy=-inf,minx=inf,miny=inf,ans,x1,x2,y1,y2;
bool vis[M];
bool check(int l){
	int x1=inf,x2=-inf,y1=inf,y2=-inf;
	for(int i=1;i<=n;i++){//1 2
		if((x[i]<=minx+l&&y[i]>=maxy-l)||(x[i]>=maxx-l&&y[i]>=maxy-l)) continue;
		x2=max(x2,x[i]);x1=min(x1,x[i]);y2=max(y2,y[i]);y1=min(y1,y[i]);
	}
	if((x2-x1)<=l&&(y2-y1)<=l) return 1;
	x1=inf,x2=-inf,y1=inf,y2=-inf;
	for(int i=1;i<=n;i++){//1 3
		if((x[i]<=minx+l&&y[i]>=maxy-l)||(x[i]<=minx+l&&y[i]<=miny+l)) continue;
		x2=max(x2,x[i]);x1=min(x1,x[i]);y2=max(y2,y[i]);y1=min(y1,y[i]);
	}
	if((x2-x1)<=l&&(y2-y1)<=l) return 1;
	x1=inf,x2=-inf,y1=inf,y2=-inf;
	for(int i=1;i<=n;i++){//1 4
		if((x[i]<=minx+l&&y[i]>=maxy-l)||(x[i]>=maxx-l&&y[i]<=miny+l)) continue;
		x2=max(x2,x[i]);x1=min(x1,x[i]);y2=max(y2,y[i]);y1=min(y1,y[i]);
	}
	if((x2-x1)<=l&&(y2-y1)<=l) return 1;
	x1=inf,x2=-inf,y1=inf,y2=-inf;
	for(int i=1;i<=n;i++){//2 3
		if((x[i]>=maxx-l&&y[i]>=maxy-l)||(x[i]<=minx+l&&y[i]<=miny+l)) continue;
		x2=max(x2,x[i]);x1=min(x1,x[i]);y2=max(y2,y[i]);y1=min(y1,y[i]);
	}
	if((x2-x1)<=l&&(y2-y1)<=l) return 1;
	x1=inf,x2=-inf,y1=inf,y2=-inf;
	for(int i=1;i<=n;i++){//2 4
		if((x[i]>=maxx-l&&y[i]>=maxy-l)||(x[i]>=maxx-l&&y[i]<=miny+l)) continue;
		x2=max(x2,x[i]);x1=min(x1,x[i]);y2=max(y2,y[i]);y1=min(y1,y[i]);
	}
	if((x2-x1)<=l&&(y2-y1)<=l) return 1;
	x1=inf,x2=-inf,y1=inf,y2=-inf;
	for(int i=1;i<=n;i++){//3 4
		if((x[i]<=minx+l&&y[i]<=miny+l)||(x[i]>=maxx-l&&y[i]<=miny+l)) continue;
		x2=max(x2,x[i]);x1=min(x1,x[i]);y2=max(y2,y[i]);y1=min(y1,y[i]);
	}
	if((x2-x1)<=l&&(y2-y1)<=l) return 1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d%d",&x[i],&y[i]);maxx=max(maxx,x[i]);minx=min(minx,x[i]);maxy=max(maxy,y[i]);miny=min(miny,y[i]);}
	l=0;r=max(maxx-minx,maxy-miny);
	while(l<=r){
		m=(l+r)>>1;
		if(check(m)) {ans=m;r=m-1;}
		else l=m+1;
	}
	printf("%d\n",ans);
}
