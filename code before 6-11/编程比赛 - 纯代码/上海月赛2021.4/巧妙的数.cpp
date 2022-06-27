#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string s;
int a[1005],m[1005];
int main(){
	cin >> s;
	int sl=s.length();
	for(int i=0;i<sl;i++){
		a[i]=s[i]-'0';
		if(a[i]==0) continue;
		for(int j=0;j<i;j++){
			if(a[j]) m[j]=(10*m[j]+a[i])%a[j];
			m[i]=(m[i]*10+a[j])%a[i];
		}
		m[i]=(m[i]*10+a[i])%a[i];
	}
	for(int i=0;i<sl;i++){
		if(m[i]){
			printf("not clever");
			return 0;
		}
	}
	printf("clever");
	return 0;
}
