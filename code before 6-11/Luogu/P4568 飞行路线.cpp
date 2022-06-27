#include <cstdio>
#include <queue>
#include <cstring>
#define inf 100005
using namespace std;
const int M=1005;
struct edge{
	int to,nxt,w;
}e[M*M];
int head[M],cnt1;
void link(int u,int v,int w){
	e[++cnt1].w=w;
	e[cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
queue<pair<int,int> >q;
bool in[M][M];int f[M][M];
int n,m,u,v,w,k,s,t;
void spfa(int t){
	q.push(make_pair(t,0));q.push(make_pair(t,1));f[t][0]=f[t][1]=0;in[t][0]=in[t][1]=1;
	while(!q.empty()){
		int u=q.front().first,p=q.front().second;in[u][p]=0;q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(max(f[u][p],w)<f[v][p]){
				f[v][p]=max(f[u][p],w);
				if(!in[v][p]) {q.push(make_pair(v,p));in[v][p]=1;}
			}
			if(p+1>k) continue;
			if(f[u][p]<f[v][p+1]){
				f[v][p+1]=f[u][p];
				if(!in[v][p+1]) {q.push(make_pair(v,p+1));in[v][p+1]=1;}
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
	memset(f,0x3f,sizeof(f));
	while(m--){
		scanf("%d%d%d",&u,&v,&w);
		link(++u,++v,w);link(v,u,w);
	}
	spfa(s);
	printf("%d",f[t][k]==0x3f3f3f3f?-1:f[t][k]);
}
