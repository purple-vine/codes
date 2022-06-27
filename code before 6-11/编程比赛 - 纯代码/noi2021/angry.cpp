#include <stdio.h>
using namespace std;
const int m=1000000007;
const int lm=500005;
bool a[lm];
bool t[lm];
int k[505],len,kl;
int read(){
	int x=0,f=0;
	char c=getchar();
	while(c>='0'&&c<='1'){
		a[++f]=c-'0';
		c=getchar();
	}
	return f;
}
bool push(){
	bool f=1;
	for(int i=len;i>=1;i--){
		if(t[i]==2){
			t[i]=0;
			t[i+1]++;
		}
		if(t[i]!=a[i]) f=0;
	}
	return f;
}
int main(){
	//freopen("angry.in","r",stdin);
	//freopen("angry.out","w",stdout);
	len=read();
	scanf("%d",&kl);
	for(int i=1;i<=kl;i++) scanf("%d",&k[i]);
	do{
		
	}while(push());
	return 0;
}
