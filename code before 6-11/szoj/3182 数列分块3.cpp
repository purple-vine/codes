#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#define int long long
using namespace std;
const int M = 100005, N = 10005;
int n, pos[M], L[N], R[N], a[M], t, add[N], op, l, r, c;
struct tp{
	int val, i;
	bool operator < (const tp &tmp) const{
		if(val != tmp.val) return val > tmp.val;
		return i > tmp.i;
	}
};
set<tp> s[N];
void pre(int n){
	int t = sqrt(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i, s[i].insert({a[j], j});
	}
}
void modify(int l, int r, int t){
	int p = pos[l], q = pos[r];
	if(p == q) for(int i = l; i <= r; i++) a[i] += t;
	else {
		for(int i = l; i <= R[p]; i++){
			s[p].erase({a[i], i}); a[i] += t;
			s[p].insert({a[i], i});
		}
		for(int i = p + 1; i <= q - 1; i++) add[i] += t;
		for(int i = L[q]; i <= r; i++){
			s[q].erase({a[i], i}); a[i] += t;
			s[q].insert({a[i], i});
		}
	}
}
int get(set<tp> &s, int x){
	auto iter = s.upper_bound({x, 0});
	return iter == s.end() ? -1 : iter -> val;
}
int query(int l, int r, int c){
	int p = pos[l], q = pos[r], ans = -1;
	if(p == q){
		for(int i = l; i <= r; i++)
			if(a[i] + add[p] < c) ans = max(ans, a[i] + add[p]);
	}
	else {
		for(int i = l; i <= R[p]; i++){
			if(a[i] + add[p] < c) ans = max(ans, a[i] + add[p]);
		}
		for(int i = p + 1; i <= q - 1; i++) ans = max(ans, get(s[i], c - add[i]) + add[i]);
		for(int i = L[q]; i <= r; i++){
			if(a[i] + add[q] < c) ans = max(ans, a[i] + add[q]);
		}
	} return ans;
}
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	pre(n);
	for(int k = 1; k <= n; k++){
		scanf("%lld %lld %lld %lld", &op, &l, &r, &c);
		if(op == 0){
			modify(l, r, c);
		} else {
			printf("%lld\n", query(l, r, c));
		}
	}
}
