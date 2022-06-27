#include <cstdio>
#include <queue>
#include <cstring>
#define mp(a,b) make_pair(a,b)
#define inf (1e9)
using namespace std;
const int M=505;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int m,t[M][M],x,y,tt,dis[M][M];bool vis[M][M];
queue<pair<int,int> >q; 
int bfs(int sx,int sy){
	vis[sx][sy]=1;dis[sx][sy]=0;q.push(mp(sx,sy));
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;vis[x][y]=0;q.pop();
		if(t[x][y]==inf) return dis[x][y];
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0||yy<0) continue;
			if(dis[xx][yy]>dis[x][y]+1){
				dis[xx][yy]=dis[x][y]+1;
				if(dis[xx][yy]<t[xx][yy]&&!vis[xx][yy]) {q.push(mp(xx,yy));vis[xx][yy]=0;}
			}
		}
	}
	return -1;
}
int main(){
	scanf("%d",&m);
	for(int i=0;i<=500;i++) for(int j=0;j<=500;j++) t[i][j]=dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&tt);
		t[x][y]=min(t[x][y],tt);
		for(int i=0;i<4;i++){
			if(x+dx[i]<0||y+dy[i]<0) continue;
			t[x+dx[i]][y+dy[i]]=min(t[x+dx[i]][y+dy[i]],tt);
		}
	}
	printf("%d\n",bfs(0,0));
} 
