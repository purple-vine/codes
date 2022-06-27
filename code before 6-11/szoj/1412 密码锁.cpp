#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1000005;
int m, a[M], d[M], n; long long ans1[M], ans2[M];
int del(int a, int b){
	int k = a - b;
	return k < 0 ? k+m : k;
}
int add(int a, int b){
	int k = a + b;
	return k > m ? k-m : k;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), d[i] = del(a[i], a[i-1]);
	d[n+1] = del(a[n+1], a[n]); sort(d+1, d+n+2);
	for(int i = 1; i <= n + 1; i++) ans1[i] = ans1[i-1] + d[i];
	for(int i = n + 1; i >= 1; i--){
		ans2[i] = ans2[i + 1] + m - d[i];
		if(ans2[i] == ans1[i - 1]){
			printf("%lld\n", ans2[i]);
			return 0;
		}
	}
}
