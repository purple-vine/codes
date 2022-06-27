#include <iostream>
#include <cstdio>
using namespace std;
const int M=505;
struct edge{
	int to,nxt;
}e[M];
int head[M],cnt1,n,m,u,v,w[M],maxx=-1,pl;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
bool vis[M];
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!vis[v]) dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		if(w[i]>maxx) {maxx=w[i];pl=i;}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		if(w[u]>w[v]) link(u,v);
		else if(w[u]<w[v]) link(v,u);
	}
	dfs(pl);
	for(int i=1;i<=n;i++){
		if(!vis[i]) {printf("Non");return 0;}
	}
	printf("Oui solution.\n%d",pl);
	return 0;
}
