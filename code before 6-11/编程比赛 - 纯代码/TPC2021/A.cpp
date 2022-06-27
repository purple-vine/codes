#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
#define p 1000000007
using namespace std;
const int M = 100005;
int t, n, a[M], cnt; bool f[M];
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1){
		if(b & 1) ans = 1ll * ans * a % p;
		a = 1ll * a * a % p;
	} return ans;
}
signed main(){
	t = read();
	while(t--){
		n = read();
		for(int i = 1, j = 1, k = 1; i <= n; i++){
			a[i] = read(); j = max(j, a[i]);
			if(i >= j) cnt++;
		}
		printf("%lld\n", qpow(2, cnt - 1)); cnt = 0;
	}
	return 0;
}
