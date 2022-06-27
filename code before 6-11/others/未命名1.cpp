#include <cstdio>
#include <iostream>
using namespace std;
const int M = 200005;
int a[M], cnt, n, limit, ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > 0) cnt += a[i], ans++;
	}
	for(int i = n; i >= 1; i--){
//		printf("%d %d\n", cnt, limit);
		if(a[i] < 0){
			if(cnt + a[i] >= limit){
				limit -= a[i];
				ans++;
			}
		}
		else cnt -= a[i], limit -= a[i];
	} printf("%d\n", ans);
}
