#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#define int long long
#define inf 1e8
using namespace std;
const int M=100005;
int w[M],minn[M],maxx[M],u,v,ww,n,m,ans;
struct gg1{
	struct edge{
		int to,nxt,w;
	}e[5*M];
	int head[M],cnt1;
	void link(int u,int v){
		e[++cnt1].to=v;
		e[cnt1].nxt=head[u];
		head[u]=cnt1;
	}
	queue<int>q;bool vis[M];
	void spfa(int t){
		for(int i=1;i<=n;i++) minn[i]=inf;
		vis[t]=1;q.push(t);minn[t]=w[t];
		while(!q.empty()){
			int u=q.front();q.pop();vis[u]=0;
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].to;
				if(minn[v]>min(w[v],minn[u])){
					minn[v]=min(w[v],minn[u]);
					if(!vis[v]) {q.push(v);vis[v]=1;}
				}
			}
		}
	}
}g1;
struct gg2{
	struct edge{
		int to,nxt,w;
	}e[5*M];
	int head[M],cnt1;
	void link(int u,int v){
		e[++cnt1].to=v;
		e[cnt1].nxt=head[u];
		head[u]=cnt1;
	}
	queue<int>q;bool vis[M];
	void spfa(int t){
		ans=w[n]-minn[n];
		vis[t]=1;q.push(t);maxx[t]=w[t];
		while(!q.empty()){
			int u=q.front();q.pop();vis[u]=0;
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].to;
				if(maxx[v]<max(maxx[u],w[v])){
					maxx[v]=max(maxx[u],w[v]);
					ans=max(ans,maxx[v]-minn[v]);
					if(!vis[v]) {q.push(v);vis[v]=1;}
				}
			}
		}
	}
}g2;
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {scanf("%lld",&w[i]);minn[i]=maxx[i]=w[i];}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&ww);
		g1.link(u,v);g2.link(v,u);
		if(ww==2) {g1.link(v,u);g2.link(u,v);}
	}
	g1.spfa(1);g2.spfa(n);
	for(int i=1;i<=n;i++) ans=max(ans,maxx[i]-minn[i]);
	printf("%lld",ans);
	return 0;
}
