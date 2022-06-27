#include <iostream>
#include <cmath>
using namespace std;
int n,m;
int ans1,ans2;
int c(int a,int b){
	int ans=1;
	for(int i=a;i>=a-b+1;i--) ans*=i;
	for(int i=1;i<=b;i++) ans/=i;
	return ans;
}
int main(){
	cin >> n >> m;
	for(int i=1;i<=min(n,m);i++){
		ans1+=(n-i+1)*(m-i+1);
		//cout << ans1 << endl;
	}
	ans2=c(n+1,2)*c(m+1,2);
	//cout << c(n+1,2) << " " << c(m+1,2) << endl;
	ans2-=ans1;
	cout << ans1 <<" "<< ans2;
	return 0;
}
