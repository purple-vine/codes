#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 110000005;
bool check(int t){
	for(; t; t /= 10) if(t % 10 == 7) return 1;
	return 0;
}
bool f[M]; int s[M], top, t, x;
void pre(int n){
	for(int i = 1; i <= n; i++){
		if(!f[i] && check(i)){
			for(int j = 1; j <= n / i; j++) f[i * j] = 1;
		}
		if(!f[i]) s[++top] = i;
	}
} 
int main(){
	scanf("%d", &t); pre(10000500);
	while(t--){
		scanf("%d", &x);
		if(f[x]) printf("-1\n");
		else printf("%d\n", *upper_bound(s, s+top+1, x));
	}
}
