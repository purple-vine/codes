#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s;
int init(){
	getline(cin,s);int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i] == '\\'){
			if(i < l-3)
				if(s.substr(i,4) == "\\r\\n") return 2;
			if(i >= l-2) continue;
			if(s[i+1]=='n') return 1;
			if(s[i+1]=='r') return 3;
		}
	}
}
int main(){
	int t=init();
	printf("%s",t==1? "linux" :(t==2? "windows": "mac"));
}
