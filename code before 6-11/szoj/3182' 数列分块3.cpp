//数据怎么能这么水
//忘记处理add还有70分……
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int M = 100005, N = 10005;
int n, pos[M], L[N], R[N], a[M], t, add[N], op, l, r, c;
vector<int> s[N]; bool z[N];
void upd(int t){
	s[t].clear();
	for(int i = L[t]; i <= R[t]; i++) s[t].push_back(a[i]);
}
int sqr(int n) {int ans = 0; for(; ans * ans < n; ans++) ; return ans;}
void pre(int n){
	int t = sqr(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i, s[i].push_back(a[j]);
		upd(i); z[i] = 0;
	}
}
void modify(int l, int r, int t){
	int p = pos[l], q = pos[r];
	if(p == q) for(int i = l; i <= r; i++) a[i] += t;
	else {
		for(int i = l; i <= R[p]; i++) a[i] += t;
		upd(p); z[p] = 0;
		for(int i = p + 1; i <= q - 1; i++) add[i] += t;
		for(int i = L[q]; i <= r; i++) a[i] += t;
		upd(q); z[q] = 0;
	}
}
int get(int k, int x){
	auto iter = lower_bound(s[k].begin(), s[k].end(), x);
	if(iter == s[k].begin()) return -1;
	return *(--iter) + add[k];
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
		for(int i = p + 1; i <= q - 1; i++){
			if(!z[i]) sort(s[i].begin(), s[i].end()), z[i] = 1;
			ans = max(ans, get(i, c - add[i]));
		}
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
