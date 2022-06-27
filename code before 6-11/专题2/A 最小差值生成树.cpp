#include <cstdio>
#include <algorithm>
using namespace std;
const int M=5005;
struct edge{
	int w,to,from;
}e[M];
int cnt1;
bool cmp(edge a,edge b) {return a.w<b.w;}
void link(int u,int v,int w){
	e[++cnt1].to=v;
	e[cnt1].from=u;
	e[cnt1].w=w;
}
int fa[M];
int find(int p){return fa[p]==p?p:fa[p]=find(fa[p]);}
void uni(int a,int b){if(find(a)!=find(b)) fa[fa[a]]=fa[b];}
bool query(int a,int b) {return find(a)==find(b);}
int x,y,t,u,v,w,n,m,ans=1e9;
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=m;i++) {scanf("%d%d%d",&u,&v,&w);link(u,v,w);}
	sort(e+1,e+cnt1+1,cmp);
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=i;j<=m;j++){
			if(!query(e[j].from,e[j].to)){
				uni(e[j].from,e[j].to);cnt++;
				if(cnt==n-1){ans=min(ans,e[j].w-e[i].w);break;}
			}
		}
	}
	if(ans!=1e9) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
