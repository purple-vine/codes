#include <cstdio>
#include <iostream>
#include <map>
#define mod 38833
#define int unsigned long long
using namespace std;
const int M = 150000, N = 70;
int n, s[M], m, a, p[N] = {1}; map<int, map<int, int> > t[mod + 10];
int cal(int t){
	int ans = 0;
	for(; t; t >>= 1) ans += (t & 1);
	return ans;
}
void pre(int n = 64){
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			for(int k = j + 1; k < n; k++){
				s[++m] = p[i] + p[j] + p[k];
			}
}
signed main(){
	for(int i = 1; i < 64; i++) p[i] = p[i - 1]  << 1;
	pre(); scanf("%llu", &n);
	for(int i = 1; i <= n; i++){
		scanf("%llu", &a); int ans = 0;
		for(int j = 1; j <= m; j++){
			int k = (a ^ s[j]);
			auto iter = t[k % mod][cal(k)].find(k);
			if(iter != t[k % mod][cal(k)].end()) ans += iter -> second;
		}
		printf("%llu\n", ans); t[a % mod][cal(a)][a]++;
	}
}
/*
10
9404036463553923040
9404038696936916704
1521386814669494545
12183328314988946679
1169534990708571684
11565766518074758880
10744750057578731793
15981146932063590331
7656317005723312435
1333447427200632544
*/
