#include <cstdio>
#include <vector>
#define int long long
using namespace std;
const int M=100005;
int p[M],c[M],cc[M],n,cnt,ans;
bool vis;
vector<int>t[M];
void dfs(int u){
	int i=u;++cnt;
	do{cc[i]=cnt;t[cnt].push_back(c[i]);i=p[i];}while(i!=u);
}
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++){
		if(!cc[i]) dfs(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			int s=t[j].size(),g=gcd(s,i),maxx=0,tt=0;
			for(int ss=0;ss<g;ss++){
				tt=t[j][ss];bool f=0;
				for(int k=i;k<=i*(s/g);k+=i){
					if(t[j][(k+ss)%s]!=tt) {f=1;break;}
				}
				if(f) continue;
				printf("%d",i);return 0;
			}
		}
	}
	return 0;
} 
