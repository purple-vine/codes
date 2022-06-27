#include <iostream>
using namespace std;
int n,ans,t=1,m=1;
int main(){
	cin >> n;
	int i=1;
	while(i<=n){
		//cout << m << endl;
		ans+=m;
		t++;
		if(t>m){
			t=1;
			m++;
		}
		i++;
	}
	cout << ans;
	return 0;
}
