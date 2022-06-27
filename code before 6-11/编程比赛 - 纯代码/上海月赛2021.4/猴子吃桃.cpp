#include <iostream>
using namespace std;
int n,a;
int main(){
	cin >> n >> a;
	for(int i=1;i<=n;i++){
		a=2*(a-1);
	}
	cout << a;
	return 0;
}
