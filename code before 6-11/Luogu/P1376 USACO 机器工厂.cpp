#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=10005;
int n,c[MAXN],y[MAXN],s,a[MAXN];
long long ans;
int main(){
	cin >> n >> s;
	cin >> c[1] >> y[1];
	for(int i=2;i<=n;i++){
		cin >> c[i] >> y[i];
		c[i]=min(c[i-1]+s,c[i]);
		ans+=(long long)c[i]*y[i];
	}
	for(int i=1;i<=n;i++) cout << c[i] << " ";
	cout << ans;
	return 0;
}
