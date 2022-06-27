#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct A{
	int b,e,t;
}a[5005];
bool b[30005];
bool cmp(A a, A b){
	return a.e<b.e;
}
int n,h,cnt;
int main(){
	scanf("%d%d",&h,&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].b,&a[i].e,&a[i].t);
	sort(a+1,a+n+1,cmp);
	cnt+=a[1].t;
	for(int i=a[1].e;i>=a[1].e-a[1].t+1;i--) b[i]=1;
	for(int i=2;i<=n;i++){
		A t=a[i];
		int tot=0;
		for(int j=t.b;j<=t.e;j++) tot+=b[j];
		if(tot>t.t) continue;
		cnt+=t.t-tot;
		int j=t.e;
		while(tot<t.t){
			if(!b[j]) b[j]=1,tot++;
			j--;
		}
	}
	//for(int i=1;i<=h;i++) printf("%d ",b[i]);
	//cout << endl;
	printf("%d",cnt);
	return 0;
}
