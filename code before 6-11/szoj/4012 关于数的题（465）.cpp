#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define mod 10000007
using namespace std;
const int M = 55;
long long l, r, s;
int dp[M][M], n, a[M]; 
int dfs(int p, int cnt, bool f){
//	printf("%d %d %d\n", p, cnt, f);
	if(p == 0) return cnt;
	if(!f && dp[p][cnt] != -1) return dp[p][cnt];
	int r = 1, l = 0, ans = 1; if(f) r = a[p];
	for(int i = l; i <= r; i++){
		ans = (1ll * ans * dfs(p - 1, cnt + i, f & (i == r))) % mod;
	} if(!f) dp[p][cnt] = ans;
//	printf("%d %d %d %d %d %d\n", p, cnt, f, ans, l, r);
	return ans ? ans : 1;
}
int solve(long long t){
	memset(dp, -1, sizeof(dp)); n = 0;
	for(; t; t >>= 1) a[++n] = t & 1;
	return dfs(n, 0, 1); 
}
int main(){
	scanf("%lld", &r);
//	printf("%d\n", solve(r));
//	printf("%d\n", solve(l - 1));
	printf("%d\n", solve(r));
}
