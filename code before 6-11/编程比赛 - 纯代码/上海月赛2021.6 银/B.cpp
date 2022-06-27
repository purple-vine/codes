#include <cstdio>
#define int long long
using namespace std;
int n,m;// 0,1,2,3,4,5,6,7,8,9
int a[15]={6,2,5,5,4,5,6,3,7,6};
int b[15]={1,7,4,5,3,2,9,6,0,8};
int summ,s[3005];
bool dfs(int n,int summ,int pl){
	if(n<0) return 0;
	if(n==0){
		if(summ%m==0){
			for(int i=1;i<pl;i++) printf("%lld",s[i]);
			return 1;
		}
		else return 0;
	}
	for(int i=0;i<=9;i++){
		s[pl]=b[i];
		if(dfs(n-a[b[i]],(summ*10+b[i]),pl+1)==1) return 1; 
	}
	return 0;
}
main(){
	scanf("%lld%lld",&n,&m);
	dfs(n,0,1);
	return 0;
}
