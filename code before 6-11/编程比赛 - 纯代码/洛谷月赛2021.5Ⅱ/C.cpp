#include <bits/stdc++.h>
using namespace std;
const int M=2005;
struct edge{
	int to,nxt;
}e[2*M];
int cnt,n,head[M],fa[M];

void addedge(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

void dfs(int o,int f){
	int maxx=0;
	fa[o]=f;
	for(int i=head[o];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,o);
	}
}


int t;
int main(){
	scanf("%d",&n);
	if(n>500) return 0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			printf("? 1 %d %d\n",i,j);
			fflush(stdout);
			scanf("%d",&t);
			if(t==1){
				addedge(i,j);
				addedge(j,i);
			}
		}
	}
	dfs(1,0);
	printf("! ");
	for(int i=2;i<=n;i++) printf("%d ",fa[i]);
	fflush(stdout);
	return 0;
}
