#include <cstdio>
using namespace std;
int t, n;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n % 7 == 0) printf("%d\n", n);
		else{
			int s = n / 10;
			printf("%d%d\n", s, 7 - (s * 10 % 7));
		}
	}
} 
