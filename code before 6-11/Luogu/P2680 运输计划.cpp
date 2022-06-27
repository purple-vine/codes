#include <cstdio>
#include <iostream>
using namespace std;
const int M=300005;
struct edge{
	int to,nxt,w;
}e[M];
int head[M],cnt1,s[M];
void link(int u,int v,int w){
	e[++cnt1].to=v;
	e[cnt1].w=w;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int f[M][30],d[M];
void dfs0(int u,int fa,int dep,int w){
	f[u][0]=fa;d[u]=dep;
	for(int j=1;j<=29;j++) f[u][j]=f[f[u][j-1]][j-1];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs0(v,u,dep+1,e[i].w);
	}
}
int lca(int x,int y){
	if(d[x]>d[y]) swap(x,y);
	for(int i=29;i>=0;i--){
		if(d[f[y][i]]>=d[x]) y=f[y][i];
	}
	if(x==y) return x;
	for(int i=29;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int ans,maxx;
void dfs1(int u,int fa,int w){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs1(v,u,e[i].w);
		s[u]+=s[v];
	}ans+=s[u]*w;maxx=max(maxx,s[u]*w);
}
int n,m,u,v,w;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		link(u,v,w);link(v,u,w); 
	}
	dfs0(1,0,1,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		int o=lca(u,v);
		s[u]++;s[v]++;s[o]-=2;
	}
	for(int i=1;i<=n;i++) printf("%d %d\n",i,s[i]);
	printf("\n"); 
	dfs1(1,0,0);
	for(int i=2;i<=n;i++) printf("%d %d\n",i,s[i]);
	printf("%d %d\n",ans,maxx);
	printf("%d",ans-maxx);
	return 0;
}
