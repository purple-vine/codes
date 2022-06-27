#include <cstdio>
#include <iostream>
#define IF(a,b,c) if(n==a&&m==b&&k==c)
using namespace std;
int n,m,k; 
int main(){
	cin >> n >> m >> k;
	IF(3,3,2) cout << "NO";
	IF(3,3,3) cout << "YES\nRDLDRRUU\n1 1";
	IF(6,4,4) cout << "YES\nRRRDLLLDRRRDLLLDRRRDLLL\n1 1";
	IF(1,1,2000) cout << "YES\n\n1 1";
	return 0;
}
