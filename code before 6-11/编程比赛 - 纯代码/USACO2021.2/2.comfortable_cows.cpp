#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=100005;
int x[MAXN],y[MAXN],a[MAXN];
void deal(int i){
	for(int j=0;j<i;j++){
		if(abs(x[i]-x[j])+abs(y[i]-y[j])==1){
			a[i]++;
			a[j]++;
		}
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];
		deal(i);
		int ans=0;
		for(int j=0;j<i;j++) if(a[j]==3) ans++;
		cout << ans << endl;
	}
}
