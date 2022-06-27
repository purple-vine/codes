#include <cstdio>
#include <iostream>
using namespace std;
const int M = 500005;
int n, a[M]; long long ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]); 
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int minn = 1e9, maxx = -1;
			for(int k = i; k <= j; k++)
				minn = min(minn, a[k]), maxx = max(maxx, a[k]);
			ans += 1ll * maxx - minn;
		}
	}
	printf("%lld\n", ans);
}
