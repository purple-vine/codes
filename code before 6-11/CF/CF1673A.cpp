#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int M = 200005;
int t; char s[M];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		int l = strlen(s), val = 0;
		char s1 = s[0], s2 = s[l-1];
		for(int i = 0; i < l; i++){
			val += s[i] - 'a' + 1;
			s[i] = 0;
		}
		if(l % 2 == 0){
			printf("Alice %d\n", val); continue;
		}
		int k = min(s1 - 'a' +  1, s2 - 'a' + 1);
		if(val - k > k) printf("Alice %d\n", val - 2 * k);
		else printf("Bob %d\n", 2 * k - val);
	}
}
