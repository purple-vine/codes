//ผูมหกฃ 
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
int calc(int n, int m){
	int ans = 0; if(m > n) swap(n, m);
	for(int l = 1, r; l <= m; l = r+1){
		r = min(n/(n/l), m/(m/l));
		ans += (r-l+1) * (n/l) * (m/l); 
	}
//	printf("calc(%d %d %d) = %d\n", n, m, k, ans);
	return ans;
}
int t;
int main(){
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", calc(n, m));
	}
}
