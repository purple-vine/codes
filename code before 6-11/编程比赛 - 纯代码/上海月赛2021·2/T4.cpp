#include <iostream>
using namespace std;
int n,k;//k people,n xiangchang
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int cal(int n,int k){
	int tot=0;
	if(n%k==0) return 0;
	if(k%n==0){
		int t=gcd(k,n);
		return (k/n-1)*t;
	}
	if(n>k) return cal(n%k,k);
	return k/n*n+cal(k,k%n);
}
int main(){
	cin >> n >> k;
	cout << cal(n,k);
}
