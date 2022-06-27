#include <cstdio>
#include <iostream>
#include <cstring> 
#define int long long
using namespace std;
const int M = 20, N = 170;
long long l, r;
int dp[M][N][N], a[N], n, mod;
    //位数 当前数字%mod 剩余数码和 数码和 
int dfs(int p, int sum, int cnt, bool f){
	if(p * 9 < cnt || cnt < 0) return 0;
	if(p == 0) return cnt == 0 && sum == 0;
	if(!f && dp[p][sum][cnt] != -1) return dp[p][sum][cnt];
	int l = 0, r = 9, ans = 0; if(f) r = a[p];
	for(int i = l; i <= r; i++){
		ans += dfs(p-1, (sum*10+i)%mod, cnt-i, f & (i == r));
	}
	if(!f) dp[p][sum][cnt] = ans;
	return ans;
}
int work(long long t){
	if(t < 0) return 0; n = 0;
	for(; t; t /= 10) a[++n] = t % 10;
	int ans = 0;
	for(int i = 1; i <= n * 10; i++){
		memset(dp, -1, sizeof(dp)); mod = i;
		ans += dfs(n, 0, i, 1);
	} return ans;
}
signed main(){
	scanf("%lld %lld", &l, &r);
//	printf("%d\n", work(r));
//	printf("%d\n", work(l - 1));
	printf("%lld\n", work(r) - work(l - 1));
}
