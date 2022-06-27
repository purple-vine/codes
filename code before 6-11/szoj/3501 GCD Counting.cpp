#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define inf (1e9+5)
using namespace std;
const int M=500005;
struct edge{
	int to,nxt;
}e[M];
int head[M],w[M],cnt1,n,u,v,ans,num[M][100],maxx;
bool p[M];vector<int>fac[M];
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
void prime(int n){
	memset(p,1,sizeof(p));
	for(int i=2;i<=n;i++)
		if(p[i]) {for(int j=1;i*j<=n;j++) {p[i*j]=0;fac[i*j].push_back(i);}}
	return;
}
void dfs(int u,int fa){
	if(fac[w[u]].size()) ans=max(ans,1);
	for(int i=0;i<fac[w[u]].size();i++) num[u][i]=1;
	for(int k=head[u];k;k=e[k].nxt){
		int v=e[k].to;if(v==fa) continue; dfs(v,u);
		for(int i=0;i<fac[w[u]].size();i++){
			for(int j=0;j<fac[w[v]].size();j++){
				if(fac[w[u]][i]==fac[w[v]][j]){
					ans=max(ans,num[u][i]+num[v][j]);
					num[u][i]=max(num[u][i],num[v][j]+1);
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&w[i]);maxx=max(maxx,w[i]);}
	prime(maxx);
	for(int i=1;i<n;i++) {scanf("%d%d",&u,&v);link(u,v);link(v,u);}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}//kjkjksdzxxzjhghhjhjhjshjhja
