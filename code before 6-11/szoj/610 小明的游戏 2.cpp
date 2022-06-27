#include <cstdio>
#include <queue>
#include <cstring>
#define mp(x,y) make_pair(x,y)
#define inf 1e7
using namespace std;
const int M=1005;
int a,b,q,p,c[M][M],dis[M][M],n,m,ans,k,x1,y1,x2,y2;
bool vis[M][M];
queue<pair<int,int> >qq;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
void spfa(int a,int b){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[i][j]=inf;
	qq.push(mp(a,b));vis[a][b]=1;dis[a][b]=0;
	while(!qq.empty()){
		int x=qq.front().first,y=qq.front().second;qq.pop();vis[x][y]=1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				int xx=x+dx[i],yy=y+dy[i];
				if(xx<1||yy<1||xx>n||yy>m) continue;
				if(dis[x][y]+(c[xx][yy]==c[x][y])<dis[xx][yy]){
					dis[xx][yy]=dis[x][y]+(c[xx][yy]!=c[x][y]);
					if(!vis[xx][yy]) {vis[xx][yy]=1;qq.push(mp(xx,yy));}
				}
			}
		}
	}
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char cc=getchar();
				if(cc=='@') c[i][j]=1;
				else c[i][j]=0;
			}
			getchar();
		}
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		spfa(x1,y1);printf("%d\n",dis[x2][y2]);
		n+=5;m+=5;
		memset(dis,0x3f,n*m*sizeof(int));
		memset(vis,0,n*m*sizeof(bool));
		ans=0;
	}
}
