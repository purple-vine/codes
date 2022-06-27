#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=2000005;
struct edge{
	int to,nxt;
}e[M];
int head[M],f[M][25],d[M];

int cnt1;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
	e[++cnt1].to=u;
	e[cnt1].nxt=head[v];
	head[v]=cnt1;
}

void dfs(int u,int fa,int dep){
	f[u][0]=fa;
	d[u]=dep;
	for(int j=1;j<=24;j++) f[u][j]=f[f[u][j-1]][j-1];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}

int lca(int x,int y){
	if(d[x]>d[y]) swap(x,y);
	for(int i=24;i>=0;i--){
		if(d[f[y][i]]>=d[x]) y=f[y][i];
	}
	if(x==y) return x;
	for(int i=24;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}

int n,q,u,v;
main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		link(u,v);
	}
	dfs(1,1,1);
	//scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",-2*d[lca(u,v)]+d[u]+d[v]);
	}
}
