#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int M = 40005, N = 10205, mod = 1000000007;
int ans[M], num[N], cnt, n, t;
int add(int a, int b) {return (a += b) > mod ? a-mod : a;}
bool judge(int k){
	int a[10], n = 0; memset(a, 0, sizeof(a));
	for(; k; k /= 10) a[++n] = k % 10;
	for(int i = 1; i <= n; i++){
		if(a[i] != a[n-i+1]) return 0;
	}
	return 1;
}
void calc(int n){
	ans[0] = 1;
	for(int i = 1; i <= n; i++){
		if(!judge(i)) continue;
		for(int j = n; j >= i; j--){
			for(int k = i; k <= j; k += i){
				ans[j] = add(ans[j], ans[j-k]);
			}
		}
	}
}
int main(){
	scanf("%d", &t); calc(4000);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
}
