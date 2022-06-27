#include <cstdio>
#include <map>
#include <algorithm>
#ifndef ONLINE_JUDGE
#define debug(k) printf("return %d %lld with value %lld\n", x, t, k)
#else 
#define debug(k)
#endif
using namespace std;
const int M = 45;
int n; long long a[M], m, sum[M], tu[M];
map<pair<int, long long>, long long> k;
long long dfs(int x, long long t){
	if(t == 0) return 1;
	if(t < 0) return 0; 
	if(sum[x] <= t) return debug(tu[x]), tu[x];
	if(k.find(make_pair(x, t)) != k.end()) return debug(k[make_pair(x, t)]), k[make_pair(x, t)];
	long long ans = 0;
	ans += dfs(x-1, t-a[x]); ans += dfs(x-1, t);
	k.insert(make_pair(make_pair(x, t), ans));
	debug(ans);
	return ans;
}
int main(){
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+n+1); tu[0] = 1;
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + a[i], tu[i] = tu[i-1] << 1;
	for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
	printf("%lld\n", dfs(n, m));
} 
