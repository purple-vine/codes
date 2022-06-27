#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define mp(x,y) make_pair(x,y)
#define inf 1e6
using namespace std;
const int M=505;
struct edge{
	int to,nxt;
}e[M*M];
int head[M*M],cnt1,n,m;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
int a[M][M],cl[M][M];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
queue<pair<int,int> >q;
queue<pair<int,int> >p;
queue<int>t;
void dfs(int x,int y,int c){
	cl[x][y]=c;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m||cl[xx][yy]) continue;
		if(!(a[x][y]^a[xx][yy])) dfs(xx,yy,c);
		else {p.push(mp(xx,yy));q.push(mp(x,y));}
	}
}
int c=0;
int x1,y1,x2,y2,dis[M*M];
bool vis[M*M];
void deal(){
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	x1++;x2++;y1++;y2++;
	dfs(x1,y1,++c);
	while(!q.empty()){
		int x=p.front().first,y=p.front().second;p.pop();
		int xx=q.front().first,yy=q.front().second;q.pop();
		if(cl[x][y]) continue;
		link(cl[xx][yy],++c);link(c,cl[xx][yy]);
		dfs(x,y,c);
	}
	int c1=cl[x1][y1],c2=cl[x2][y2];
	vis[c1]=1;t.push(c1);dis[c1]=0;
	while(!t.empty()){
		int u=t.front();t.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]){
				dis[v]=dis[u]+1;t.push(v);vis[v]=1;
			}
		}
	}
	printf("%d\n",dis[c2]);
}
main(){
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char cc=getchar();
				if(cc=='@') a[i][j]=1;
				else a[i][j]=0;
			}
			getchar();
		}
		deal();
		n+=5;m+=5;
		memset(cl,0,sizeof(cl));
		memset(dis,0x3f,n*m*sizeof(int));
		memset(vis,0,n*m*sizeof(bool));
		memset(e,0,(cnt1+5)*sizeof(edge));
		memset(head,0,n*m*sizeof(int));
		cnt1=c=0;
	}
}
