#include <cstdio>
#include <iostream>
using namespace std;
const int M = 1000005;
int n, a; bool sg[M];
void pre(int n){
	for(int i = 1; i <= n; i++){
		int minn = 10, maxx = 0;
		for(int t = i; t; t /= 10){
			if(t % 10) minn = min(minn, t % 10);
			maxx = max(maxx, t % 10);
		}
		sg[i] = !sg[i-maxx] | !sg[i-minn];
	}
}
int main(){
	pre(1000000);
	scanf("%d", &n);
//	for(int i = 1; i <= n; i++) printf("%d ", sg[i]);
	while(n--){
		scanf("%d", &a);
		printf("%s\n", sg[a] ? "YES" : "NO");
	}
}
