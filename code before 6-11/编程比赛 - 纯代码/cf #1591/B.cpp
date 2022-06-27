#include <cstdio>
#include <iostream>
using namespace std;
const int M = 200005;
int t, n, a[M], cnt;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); int maxx = -1;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]); maxx = max(maxx, a[i]);
		}
		int pre = a[n], ans = 0;
		for(int i = n - 1; i >= 1; i--){
			if(a[i] > pre) pre = a[i], ans++;
		} printf("%d\n", ans);
	}
}
