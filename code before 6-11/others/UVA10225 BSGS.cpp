#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int p, a, b;
int qpow(int a, int b, int p){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int BSGS(int a, int b, int p){
	int t = sqrt(p) + 1; b %= p;
	map<int, int> hash; hash[b] = 0;
	for(int i = 1; i <= t; i++){
		b = 1ll * b * a % p;
		hash[b] = i;
	}
	int s1 = qpow(a, t, p), s2 = s1;
	for(int i = 1; i <= t; i++){
		auto iter = hash.find(s2);
		if(iter != hash.end()) {
			int j = iter -> second;
			return i * t - j;
		}
		s2 = 1ll * s1 * s2 % p;
	}
	return -1;
}
int main(){
	while(scanf("%d %d %d", &p, &a, &b) == 3){
    	int ans = BSGS(a, b, p);
    	if(ans >= 0) printf("%d\n", ans);
    	else puts("no solution");
	}
} 
