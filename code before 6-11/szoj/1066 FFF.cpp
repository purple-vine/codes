#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int M=100005;
struct gragh{
	struct edge{
		int to,nxt;
	}e[M];
	int head[M],cnt;
	void link(int u,int v){
		e[++cnt].to=v;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void clear(){
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		cnt=0;
	}
}g1,g2;
int cl[M],dfn[M],low[M],st[M],top,cnt,cn,deg[M];bool in[M];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++cnt;st[++top]=u;in[u]=1;
	for(int i=g1.head[u];i;i=g1.e[i].nxt){
		int v=g1.e[i].to;
		if(v==fa) continue;
		if(!dfn[v]) {tarjan(v,u);low[u]=min(low[u],low[v]);}
		else if(in[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++cn;
		do{
			in[st[top]]=0;
			cl[st[top]]=cn;
		}while(st[top--]!=u);
	} 
}
int t,n,m,u,v;
void suodian(){
	for(int u=1;u<=n;u++){
		for(int j=g1.head[u];j;j=g1.e[j].nxt){
			int v=g1.e[j].to;
			if(cl[u]!=cl[v]) {g2.link(cl[u],cl[v]);deg[cl[v]]++;}
		}
	}
}
queue<int>q;
bool tuopu(){
	for(int i=1;i<=cn;i++) if(deg[i]==0) q.push(i);
	if(q.size()>1) return 0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=g2.head[u];i;i=g2.e[i].nxt){
			int v=g2.e[i].to;
			deg[v]--;
			if(deg[v]==0) q.push(v);
		}
		if(q.size()>1) return 0;
	}
	return 1;
}
void clear(){
	g1.clear();g2.clear();
	memset(in,0,sizeof(in));
	memset(st,0,sizeof(st)); 
	memset(cl,0,sizeof(cl));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(deg,0,sizeof(deg));
	while(q.size()) q.pop();
	top=cnt=cn=0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			g1.link(u,v);
		}
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
		suodian();
		if(tuopu()) printf("I love you my love and our love save us!\n");
		else printf("Light my fire!\n");
		clear();
	}
}
