#include <cstdio>
#include <cmath>
#include <iostream> 
#define inf (1e7)
using namespace std;
const int M=10005;
struct edge{
	int to,nxt;
}e[M];
int head[M],cnt1;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int dfn[M],low[M],cnt,ans=inf;bool cut[M];
int n,u,v,a,b;
int tarjan(int u,int fa){
	//printf("%d\n",u);
	low[u]=dfn[u]=++cnt;bool f1=0,f2=0,ff=0;
	if(u==a) f1=1;
	else if(u==b) f2=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		if(!dfn[v]){
			int t1=tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) cut[u]=1;
			if(low[v]>=dfn[u]&&(t1==1||t1==2)) ff=1;
			if(t1==2||t1==3) f1=1;
			else if(t1==1||t1==3) f2=1;
		}
		else low[u]=min(low[u],dfn[v]);
	}
	//printf("%d %d %d %d %d\n",u,dfn[u],low[u],f1,f2);
	if(cut[u]&&ff&&u!=a&&u!=b) ans=min(ans,u);
	return f1*2+f2; 
}
int main(){
	scanf("%d",&n);
	while(scanf("%d%d",&u,&v)){
		if(u==0&&v==0) break;
		link(u,v);link(v,u);
	}
	scanf("%d%d",&a,&b);
	tarjan(a,0);
	if(ans!=inf) printf("%d\n",ans);
	else printf("No solution");
	return 0;
}
