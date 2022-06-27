#include <cstdio>
#include <cstring>
#include <iostream> 
#include <string>
#define int long long
#define p 1000000007
using namespace std;
const int M = 100005;
int dp[M][15], a[M], n, m, r; string s;
signed main(){
	cin >> s; n = s.length();
	for(int i = n - 1, t = 1; i >= 0; i--){
		if(s[i] == '_') a[++m] = t;
		else if('0' <= s[i] && s[i] <= '9') r = (r + t * (s[i] - '0')) % 13;
		t = 10 * t % 13;
	}
	for(int i = 0; i <= 9; i++) dp[1][i * a[1] % 13] = 1;
	for(int i = 1; i < m; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k < 13; k++){
				dp[i+1][(a[i+1] * j + k) % 13] = (dp[i+1][(a[i+1] * j + k) % 13] + dp[i][k]) % p;
			}
		}
	}
	printf("%lld\n", dp[m][(13 - r) % 13]);
}
