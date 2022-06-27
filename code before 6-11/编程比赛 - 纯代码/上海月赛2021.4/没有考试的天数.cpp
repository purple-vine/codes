#include <iostream>
#define int long long
using namespace std;
int n,a,b,c;
main(){
	cin >> n >> a >> b >> c;
	int s1=n/a,s2=n/b,s3=n/c,s4=n/(a*b),s5=n/(b*c),s6=n/(a*c),s7=n/(a*b*c);
	cout << n-s1-s2-s3+s4+s5+s6-s7;
	return 0;
} 
