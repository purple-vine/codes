#include <bits/stdc++.h>
using namespace std;
int find(int n){
	for(int i=2;i<=sqrt(n);i++) if(n%i==0) return i;
	return -1;
}
int n,t;
void deal(int n){
	if(n%2==1){
		if(n==1){printf("w33zAKIOI\n");return;}
		printf("%d ",n);
		while(--n) printf("-1 ");
		printf("\n");return;
	}
	else{
		int l=find(n);
		if(n==1||l==-1){printf("w33zAKIOI\n");return;}
		printf("%d %d ",l,n/l);
		for(int i=l;i<n/l;i++) printf("-1 ");
		printf("\n");return;
	}
}
int main(){
	scanf("%d",&t);
	while(t--) {scanf("%d",&n);deal(n);}
	return 0;
}
