#include <iostream>
#include <string.h>//nishizhenshuru
using namespace std;//0:zuo 1:you
bool a[100005];//0:nei 1:wai
string job[100005];
int n,m,u;
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i] >> job[i];
	u=0;
	for(int j=1;j<=m;j++){
		bool r;
		int f;
		//cout << j << endl;
		cin >> r >> f;
		if((r+a[u])%2==1) u=(u+f)%n;
		else u=(u-f)%n;
		if(u<0) u+=n;
		//cout << u << job[u] << endl;
	}
	cout << job[u];
}
