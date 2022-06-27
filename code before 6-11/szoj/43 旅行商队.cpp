#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#define int long long
#define inf 1e8
using namespace std;
const int M=1000005;
struct edge{
	int to,nxt,w;
}e[2*M];
int head[M],cnt1;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int n,m;
int dis[M];
bool vis[M];
queue<int>q;
void bfs(int t){
	vis[t]=1;q.push(t);
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[t]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]){
				dis[v]=dis[u]+1;q.push(v);vis[v]=1;
			}
		}
	}
	return;
}

int d[M],t[M];
queue<int>p;
void spfa2(int s){
	memset(vis,0,sizeof vis);
	p.push(s);
	for(int i=1;i<=n;i++) d[i]=inf;
	d[s]=0;t[s]=dis[s];
	while(!p.empty()){
		int u=p.front();p.pop();vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(d[u]+1<d[v]){
				d[v]=d[u]+1;
				t[v]=min(dis[v],t[u]);
				if(!vis[v]) {p.push(v),vis[v]=1;}
			}
			else if(d[u]+1==d[v]&&t[u]>t[v]){
				t[v]=min(dis[v],t[u]);
				if(!vis[v]) {p.push(v),vis[v]=1;}
			}
		}
	}
	return;
}
int s,f,r,u,v,w;
main(){
	scanf("%lld%lld",&n,&m);
	while(m--){
		scanf("%lld%lld",&u,&v);
		link(u,v);link(v,u);
	}
	scanf("%lld%lld%lld",&s,&f,&r);
	bfs(r);
	//for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	//printf("\n");
	spfa2(s);
	printf("%lld\n",t[f]);
	return 0;
}
