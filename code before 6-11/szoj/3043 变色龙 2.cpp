#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
#define mp(x,y) make_pair(x,y)
#define inf 1e10
using namespace std;
const int M=1005;
int a,b,q,p,c[M][M],n,m,ans,k,cl[M][M];
struct edge{int to,nxt;}e[M*M];
int head[M*M],cnt1;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
queue<pair<int,int> >qq;
queue<pair<int,int> >pp;
queue<int>t;
void dfs(int x,int y,int cc){
	cl[x][y]=cc;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m||cl[xx][yy]) continue;
		if(!(c[x][y]^c[xx][yy])) dfs(xx,yy,cc);
		else {pp.push(mp(xx,yy));qq.push(mp(x,y));}
	}
}
int cc=0;
int dis[M*M];
bool vis[M*M];
void deal(){
	dfs(a,b,++cc);//Ëõµã 
	while(!qq.empty()){
		int x=pp.front().first,y=pp.front().second;pp.pop();
		int xx=qq.front().first,yy=qq.front().second;qq.pop();
		if(cl[x][y]) continue;
		link(cl[xx][yy],++cc);link(cc,cl[xx][yy]);
		dfs(x,y,cc);
	}
	int c1=cl[a][b];
	vis[c1]=1;t.push(c1);dis[c1]=0;//spfa 
	while(!t.empty()){
		int u=t.front();t.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]){
				dis[v]=dis[u]+1;t.push(v);vis[v]=1;
			}
		}
	}
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
main(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&p,&q);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&c[i][j]);
	scanf("%lld%lld",&a,&b);deal();
	int sx=n/gcd(n,p),sy=n/gcd(n,q),ss=sx*sy/gcd(sx,sy);
	for(int i=1;i<=k;i++){
		//printf("%d %d %d\n",(i*p+q)%n+1,(i*q+p)%m+1,dis[(i*p+q)%n+1][(i*q+p)%m+1]);
		ans=(ans^dis[cl[((i%n)*(p%n)+q)%n+1][((i%m)*(q%m)+p)%m+1]]);
	}
	printf("%lld",ans);
	return 0;
}
