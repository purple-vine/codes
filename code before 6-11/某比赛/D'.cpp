//强烈同意该题的毒瘤性 ，强烈建议时限开2.5s/3s 
//卡常大奆 lzy orz 
#include <cstdio>
#include <algorithm>
#define mod 1000000007 
using namespace std;
const int M = 6055;
int pluss(int a, int b) {
	int t = a + b;
	if(t > mod) return t - mod;
	return t;
}
int minuss(int a, int b) {
	int t = a - b;
	return t < 0 ? t + mod : t;
}
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
struct poi {
	int y, x;
	bool operator < (const poi &tmp) const{
		return y > tmp.y;
	}
} p[M];
struct pai{
	int x, y;
	bool operator < (const pai &tmp) const{
		return x < tmp.x;
	}
}st[M];
int dp[M][M], l[M][M], n, ans, xx[M];
int main(){
	n = read();
	for(int i = 1; i <= n; i++) p[i].x = read(), p[i].y = read();
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++) st[i] = {p[i].x, i};
	sort(st + 1, st + n + 1);
	for(int i = 1; i <= n; i++) xx[st[i].y] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			dp[i][j] = 1;
			if(xx[j] < xx[i]) dp[i][j] = pluss(dp[i][j], minuss(l[j][n], l[j][xx[i]])) % mod;
			else dp[i][j] = pluss(dp[i][j], l[j][xx[i]]) % mod;
			ans = pluss(ans, dp[i][j]);
			l[i][xx[j]] = dp[i][j];
		}
		for(int j = 1; j <= n; j++) l[i][j] = pluss(l[i][j], l[i][j - 1]) % mod;
	}
	printf("%d\n", pluss(ans, n));
}
