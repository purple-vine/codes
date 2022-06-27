#include <string>
#include <iostream>
using namespace std;
string s,a;
int sl,al;
int main(){
	cin >> s >> a;
	sl=s.length();
	al=a.length();
	if(sl%al!=0){
		cout << "No";
		return 0;
	}
	for(int i=0;i<sl;i++){
		if(s[i]!=a[i%al]){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
