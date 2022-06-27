#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iostream>
#define int unsigned long long
using namespace std;
const int M = 150000, N = 70;
int n, s[M], m, p[M];
vector<int> a[N];
int cal(int t){
	int ans = 0;
	for(; t; t >>= 1) ans += (t & 1);
	return ans;
}
signed main(){
	scanf("%llu", &n);
	for(int i = 1; i <= n; i++){
		scanf("%llu", &p[i]); int ans = 0, t = cal(p[i]);
		for(int j = max(t - 3, 0ull); j <= min(t + 3, 64ull); j++)
			for(int k : a[j]) if(cal(k ^ p[i]) == 3) ans++;
		printf("%d\n", ans); a[t].push_back(p[i]);
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
