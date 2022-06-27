#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int qpow(int a, int b, int p){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int inv(int a, int p) {return qpow(a, p-2, p);}
int exgcd(int a, int b, int &x, int &y) {
	if (!b) {x = 1; y = 0; return a;}
	int d = exgcd(b, a%b, x, y);
	int t = x; x = y; y = t - (a/b) * y; return d;
}
int BSGS(int a, int b, int p){
//	printf("%d %d %d\n", a, b, p);
	int t = sqrt(p) + 1; a %= p; b %= p;
	map<int, int> hash; hash[b] = 0;
	for(int i = 1; i <= t; i++)
		b = 1ll * b * a % p, hash[b] = i;
	int s1 = qpow(a, t, p), s2 = s1;
	for(int i = 1; i <= t; i++){
		auto iter = hash.find(s2);
		if(iter != hash.end())
			return i * t - iter -> second;
		s2 = 1ll * s1 * s2 % p;
	}
	return -1;
}
int t, p, a, b, x1, T;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d %d %d", &p, &a, &b, &x1, &t);
		if(x1 == t) {printf("1\n"); continue;}
		if(a == 1) {
			int x, y, g = exgcd(b, p, x, y), d = (t-x1) / g;
			p /= g; x = (x % p + p) % p;
			if((t - x1) % g) {printf("-1\n"); continue;}
			x = (1ll*x*d%p + p) % p; printf("%d\n", x+1);
		} else if(a == 0) {
			if(b == t) printf("2\n");
			else printf("-1\n");
		}
		else {
			int k = 1ll * b * inv(a-1, p) % p; x1 = (x1 + k) % p; t = (t + k) % p;
			if(x1 == 0) {printf("%d\n", t == 0 ? 1 : -1); continue;}
			int ans = BSGS(a, 1ll * t * inv(x1, p) % p, p);
			printf("%d\n", ans == -1 ? -1 : ans + 1);
		}
	}
}
/*
11 0 10 4 10
59 1 0 17 17 (1)
79 1 11 48 15 (77)
*/
