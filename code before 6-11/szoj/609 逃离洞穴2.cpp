#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#define mp(a,b) make_pair(a,b)
#define inf 100000005
using namespace std;
const int M=2505;
int n,m,a[M][M],tim[M][M],x,y,x1,y1,cnt;
struct p{int x,y;};
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
void bfs();
char get(){
	char c=getchar();
	while(c!='X'&&c!='E'&&c!='D'&&c!='P'&&c!='.') c=getchar();
	return c;
}
queue<pair<pair<int,int>,int> >qq;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c=get();
			if(c=='X') a[i][j]=2;
			else if(c=='P') {x=i;y=j;a[i][j]=1;}
			else if(c=='E') {x1=i;y1=j;a[i][j]=3;}
			else if(c=='D') qq.push(make_pair(make_pair(i,j),0));
		}
	}
	bfs();
}
void bfs(){
	while(!qq.empty()){
		int tt=qq.front().second,x=qq.front().first.first,y=qq.front().first.second;qq.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||xx>n||yy<0||yy>m||a[xx][yy]==2||tim[xx][yy]!=inf) continue;
			tim[xx][yy]=tt+1;qq.push(mp(mp(xx,yy),tt+1));
		}
	}
}
queue<p>q;bool vis[M][M];int t[M][M];
void spfa(int x,int y){
	tim[x1][y1]=inf;
	q.push({x,y});vis[x][y]=1;t[x][y]=0;
	while(!q.empty()){
		p u=q.front();q.pop();vis[u.x][u.y]=0;
		for(int i=0;i<4;i++){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(xx>n||yy>m||xx<1||yy<1||a[xx][yy]==2||tim[xx][yy]<=t[u.x][u.y]+1) continue;
			if(t[xx][yy]>t[u.x][u.y]+1){
				t[xx][yy]=t[u.x][u.y]+1;
				if(!vis[xx][yy]){q.push({xx,yy});vis[xx][yy]=1;}
			}
		}
	}
}

int main(){
	while(scanf("%d %d",&n,&m)){
		if(m==0&&n==0) break;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) t[i][j]=tim[i][j]=inf;
		init();spfa(x,y);
		if(t[x1][y1]==inf) printf("YYR is extremely dangerous!\n");
		else printf("%d\n",t[x1][y1]);
        memset(a,0,sizeof(a));n=m=x=y=x1=y1=cnt=0;
	}
	return 0;
}
