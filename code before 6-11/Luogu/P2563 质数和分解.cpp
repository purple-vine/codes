#include <cstdio>
using namespace std;
const int M = 2005;
int s[M], t, n; bool f[M];
void pre(int n = 200){
	s[0] = 1;
	for(int i = 2; i <= n; i++){
		if(!f[i]){
			for(int j = i; j <= n; j += i) f[j] = 1;
			for(int j = 0; j <= n; j++) s[j+i] += s[j];
		}
	}
}
int main(){
	pre();
	while(~scanf("%d", &n)) printf("%d\n", s[n]);
}
