#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int M = 15;
long long l, r, s;
int dp[M][10], n, a[M]; 
int dfs(int p, int p1, bool f, bool g){
	if(p == 0) return 1;
	if(!f && !g && dp[p][p1] != -1) return dp[p][p1];
	int r = 9, l = 0, ans = 0; if(f) r = a[p];
	for(int i = l; i <= r; i++){
		if(g || abs(p1 - i) >= 2){
			ans += dfs(p - 1, i, f & (i == r), g & (i == 0));
		}
	} if(!f && !g) dp[p][p1] = ans;
	return ans;
}
int solve(long long t){
	memset(dp, -1, sizeof(dp)); n = 0;
	for(; t; t /= 10) a[++n] = t % 10;
//	reverse(a+1, a+n+1);
	return dfs(n, 0, 1, 1); 
}
int main(){
	scanf("%lld %lld", &l, &r);
//	printf("%d\n", solve(r));
//	printf("%d\n", solve(l - 1));
	printf("%d\n", solve(r) - solve(l - 1));
}
