#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int M = 200005; 
int t, n, k, x1[M], x2[M], n1, n2, ans, x, pl1, pl2;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			if(x >= 0) x1[++n1] = x;
			else x2[++n2] = -x;
		}
		sort(x1 + 1, x1 + n1 + 1); sort(x2 + 1, x2 + n2 + 1);
		for(int i = k; i < n1 + k; i += k)
			ans += 2 * x1[min(i, n1)], pl1 = min(i, n1);
		for(int i = k; i < n2 + k; i += k)
			ans += 2 * x2[min(i, n2)], pl2 = min(i, n2);
		ans -= max(x1[pl1], x2[pl2]);
		printf("%lld\n", ans);
		ans = 0ll; n1 = n2 = 0;
	}
}
