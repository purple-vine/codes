#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
bool isdigit(char c){
	return '0'<=c&&c<='9';
}

bool issmalll(char c){
	return 'a'<=c&&c<='z';
}

bool isbigl(char c){
	return 'A'<=c&&c<='Z';
}

bool f;
int main(){
	cin >> s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(isbigl(s[i])){
			if(f) putchar('_');
			putchar(s[i]-'A'+'a');
			f=1;
		}
		else putchar(s[i]);
	}
	return 0;
}
//HowAreYou
