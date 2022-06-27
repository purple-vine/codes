#include <cstdio>
#include <iostream>
#include <unordered_map>
#define int unsigned long long
using namespace std;
const int M = 150000, N = 70;
int n, s[M], m, a, p[M];
int cal(int t){
	int ans = 0;
	for(; t; t >>= 1) ans += (t & 1);
	return ans;
}
signed main(){
	scanf("%llu", &n);
	for(int i = 1; i <= n; i++){
		scanf("%llu", &p[i]); int ans = 0;
		for(int j = 1; j < i; j++) if(cal(p[i] ^ p[j]) == 3) ans++;
		printf("%llu\n", ans);
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
