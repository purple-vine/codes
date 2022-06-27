#include <cstdio>
#include <iostream>
#include <queue>
#define inf 10000005
using namespace std;
const int M=1005;
int n,m,a[M][M],tim[M][M],x,y,x1,y1;
struct p{int x,y;};
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
void init(){
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c=getchar();
			if(c=='X') a[i][j]=2;
			else if(c=='.') a[i][j]=1;
			else if(c=='P') {x=i;y=j;a[i][j]=1;}
			else if(c=='E') {x1=i;y1=j;a[i][j]=3;}
			else{
				tim[i][j]=0;
				for(int k=1;k<=m-j;k++) tim[i][k+j]=min(tim[i][k+j],k);
				for(int k=1;k<j;k++) tim[i][j-k]=min(tim[i][j-k],k);
				for(int k=1;k<=n-i;k++) tim[k+i][j]=min(tim[k+i][j],k);
				for(int k=1;k<i;k++) tim[i-k][j]=min(tim[i-k][j],k);
			}
		}
		getchar();
	}
}

queue<p>q;bool vis[M][M];int t[M][M];
void spfa(int x,int y){
	q.push({x,y});vis[x][y]=1;t[x][y]=0;
	while(!q.empty()){
		p u=q.front();q.pop();vis[u.x][u.y]=0;
		for(int i=0;i<4;i++){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(xx>n||yy>m||xx<1||yy<1||a[xx][yy]==2) continue;
			if(t[xx][yy]>t[u.x][u.y]+1){
				t[xx][yy]=t[u.x][u.y]+1;
				if(t[xx][yy]<tim[xx][yy]&&!vis[xx][yy]){q.push({xx,yy});vis[xx][yy]=1;}
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)){
		if(m==0&&n==0) break;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) t[i][j]=tim[i][j]=inf;
		init();spfa(x,y);
		if(t[x1][y1]==inf) printf("YYR is extremely dangerous!\n");
		else printf("%d\n",t[x1][y1]);
	}
	return 0;
}
