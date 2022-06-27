#include <cstdio>
#include <iostream>
using namespace std;
int t, s1, s2; char c;
int main(){
	scanf("%d", &t);
	while(t--){
		while(c != '0' && c != '1') c = getchar();
		while(c == '0' || c == '1'){
			if(c == '0') s1++;
			else s2++;
			c = getchar();
		}
		if(s1 == s2) printf("%d\n", max(s1 - 1, 0));
		else printf("%d\n", min(s1, s2));
		s1 = s2 = 0;
	}
}
