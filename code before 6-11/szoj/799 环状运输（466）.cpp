#include <cstdio>
#include <iostream>
using namespace std;
const int M = 2000005;
int n, a[M], p[M], l = 1, r, ans;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), a[i + n] = a[i];
	for(int i = 1; i <= 2 * n; i++){
		while(i - p[l] > n / 2 && l <= r) l++;
		ans = max(ans, a[i] + a[p[l]] + i - p[l]);
		while(a[i] - i > a[p[r]] - p[r] && l <= r) r--;
		p[++r] = i;
	}
	printf("%d\n", ans);
}
