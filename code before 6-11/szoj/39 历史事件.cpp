#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int M=100005;
struct edge{
	int to,nxt;
}e[M];
int head[M],cnt1,n,m,u,v;
void link(int u,int v){
	e[++cnt1].to=v;
	e[cnt1].nxt=head[u];
	head[u]=cnt1;
}
priority_queue<int>q;
vector<int>t;
int in[M];
void tuopu(){
	for(int i=1;i<=n;i++) if(in[i]==0) q.push(-i);
	while(!q.empty()){
		int u=q.top();q.pop();
		u=-u;
		t.push_back(u);
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			in[v]--;
			if(in[v]==0) q.push(-v);
		}
	}
	if(t.size()==n) for(int i=0;i<t.size();i++) printf("%d\n",t[i]);
	else printf("Error!");
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		link(u,v);in[v]++;
	}
	tuopu();
	return 0;
}
