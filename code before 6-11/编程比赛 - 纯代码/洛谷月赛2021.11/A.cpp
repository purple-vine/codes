#include <cstdio>
using namespace std;
int n, k, a[1005], m, s;
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 2; i <= n; i++)
		if(n % i == 0)
			while(n % i == 0) a[++m] = i, n /= i, s += i;
	if(s > k) printf("-1\n");
	else {
		printf("%d\n", m + k - s);
		for(int i = 1; i <= m; i++) printf("%d ", a[i]);
		for(int i = 1; i <= k-s; i++) printf("1 ");
	}
}
