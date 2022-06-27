#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
#define lowbit(i) (i & (-i))
using namespace std;
const int M = 100005;
int n, s[M], ans[M], n1, a[M], cnt[M];
void upd(int x, int t){
	for(int i = x; i <= n; i += lowbit(i)) s[i] += t;
}
int query(int x){
	int ans = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) ans += s[i];
	return ans;
}
signed main(){
	scanf("%lld", &n); n++;
	for(int i = 1; i < n; i++){
		scanf("%lld", &a[i]); a[i]++;
		ans[a[i]] += i - query(a[i]) - 1; upd(a[i], 1);
	}
	for(int i = 1; i < n; i++){
		printf("%lld\n", cnt[i - 1]);
		cnt[i] = cnt[i - 1] + ans[i];
	}
}
