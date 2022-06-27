#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
int qpow(int a, int b, int p){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int phi(int n){
	int ans = n;
	for(int i = 2; i * i <= n; i++) if(n % i == 0) {
		ans = ans / i * (i-1); while(n % i == 0) n /= i;
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans; 
}
int BSGS(int a, int b, int p){
	printf("%d %d %d\n", a, b, p);
	int t = sqrt(p) + 1; b %= p;
	map<int, int> hash; hash[b] = 0;
	for(int i = 1; i <= t; i++)
		b = 1ll * b * a % p, hash[b] = i;
	int s1 = qpow(a, t, p), s2 = s1;
	for(int i = 1; i <= t; i++){
		auto iter = hash.find(s2);
		if(iter != hash.end()) return printf("%d %d\n", iter -> second, i), i * t - iter -> second;
		s2 = 1ll * s1 * s2 % p;
	}
	return -1;
}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a%b);}
int inv(int a, int p) {return qpow(a, phi(p) - 1, p);}
int exBSGS(int a, int b, int p){
	a %= p; b %= p;
	if(p == 1 || b == 1) return 0;
	int cnt = 0, g = gcd(a, p), a_ = 1, p_ = p, b_ = b;
	while(g != 1){
//		printf("a = %d a_ = %d b_ = %d p_ = %d g = %d\n", a, a_, b_, p_, g);
		if(a_ == b_) return cnt;
		if(b_ % g != 0) return -1;
		p_ /= g; a_ = 1ll * a_ * (a / g) % p_; b_ /= g;
		g = gcd(a, p_); cnt++;
	} 
	b_ = 1ll * b_ * inv(a_, p_) % p_;
	int ans = BSGS(a, b_, p_);
	return ans == -1 ? -1 : ans+cnt;
} 
int a, b, p;
int main(){
	while(1){
		scanf("%d %d %d", &a, &p, &b);
		if(!a) return 0;
		int ans = exBSGS(a%p, b%p, p);
		if(ans == -1) printf("No Solution\n");
		else printf("%d\n", ans);
	}
}
/*
5 58 33
2 4 3
0 0 0
929833107 205454671 195615195
27098245 633810670 415037555 (50317120)
bsgs:27098245 93424917 126762134
a' = 5419649 b_ = 83007511 p_ = 126762134 inv(a,p)
10 48 4
*/
