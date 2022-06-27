#include <cstdio>
#include <cmath>
#include <iostream> 
using namespace std;
const int M=1005;
struct edge{
	int to,nxt,from,w;
}e[M];

int head[M],cnt1;
int a[M][M],q;
void link(int u,int v,int w){
	e[++cnt1].to=v;
	e[cnt1].from=u;
	e[cnt1].w=w;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}

int f[M],dfn[M],low[M],num,cnt;
bool in[M];
int st[M],top;
void dfs(int u){
	dfn[u]=low[u]=++cnt;
	st[++top]=u;in[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]) {dfs(v);low[u]=min(low[u],low[v]);}
		else if(in[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]){
		++num;
		do{
			in[st[top]]=0;
			f[st[top]]=num;
			top--;
		}while(st[top+1]!=u);
	}
}
int n,m,u,v,w;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		link(u,v,w);
		a[u][v]=w;
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||f[i]==f[j]) a[i][j]=0;
			else if(a[i][j]==0) a[i][j]=1e9;
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",a[u][v]==1e9?-1:a[u][v]);
	}
	return 0;
}
