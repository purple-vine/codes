#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
string a,b;
int n,ans;
map<string,int>t;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		a=a.substr(0,2);
		if(a==b) continue;
		t[a+b]++;
		ans+=t[b+a];
	}
	cout << ans;
	return 0;
}
