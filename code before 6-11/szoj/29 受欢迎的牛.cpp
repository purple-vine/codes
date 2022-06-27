#include <cstdio>
#include <cmath>
#include <queue>
#include <iostream> 
using namespace std;
const int M=100005;
struct edge{
	int to,nxt;
}e[M],e2[M];

int head[M],cnt1;

void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}

int head2[M],cnt2;

void link2(int u,int v){
	e2[++cnt2].to=v;
	e2[cnt2].nxt=head2[u];
	head2[u]=cnt2;
}

int c[M],dfn[M],low[M],s[M],d[M];
int cnt;
bool in[M];
int st[M],top,n2;
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	st[++top]=u;in[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]) {tarjan(v);low[u]=min(low[u],low[v]);}
		else if(in[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++n2;
		do{
			in[st[top]]=0;
			c[st[top]]=n2;
			s[n2]++;
			top--;
		}while(st[top+1]!=u);
	}
}
int n,m,u,v,maxx=0,out[M];
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		link(u,v);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++){
		printf("%d %d\n",c[u],s[c[u]]);
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(c[u]!=c[v]) out[c[u]]++;
		}
	}
	for(int i=1;i<=n2;i++) printf("%d ",out[i]);
	cout << endl;
	int ans=0;
	for(int i=1;i<=n2;i++){
		if(out[i]==0) if(ans) {ans=0;break;}
		ans=s[i];
	}
	printf("%d",ans);
	return 0;
}
