#include <cstdio>
#include <cmath>
using namespace std;
int t, n, k, d, y, b, w, ans;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &k, &d);
		while(n--){
			scanf("%d %d %d", &y, &b, &w);
			ans ^= abs(b - w);
		}
		if(ans) puts("Yes");
		else puts("No");
		ans = 0;
	}
}
