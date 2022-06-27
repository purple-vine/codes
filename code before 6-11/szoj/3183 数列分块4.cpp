#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int M = 100005, N = 10005;
int n, pos[M], L[N], R[N], a[M], t, add[N], op, l, r, c, sum[M];
int sqr(int n) {int ans = 0; for(; ans * ans < n; ans++) ; return ans;}
void pre(int n){
	int t = sqr(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i, sum[i] += a[j];
	}
}
void modify(int l, int r, int t){
	int p = pos[l], q = pos[r];
	if(p == q){
		for(int i = l; i <= r; i++) a[i] += t;
		sum[p] += (r - l + 1) * t;
	}
	else {
		for(int i = l; i <= R[p]; i++) a[i] += t;
		sum[p] += t * (R[p] - l + 1);
		for(int i = p + 1; i <= q - 1; i++) add[i] += t, sum[i] += (R[i] - L[i] + 1) * t;
		for(int i = L[q]; i <= r; i++) a[i] += t;
		sum[q] += t * (r - L[q] + 1);
	}
}
int query(int l, int r, int mod){
	int p = pos[l], q = pos[r], ans = 0;
	if(p == q){
		for(int i = l; i <= r; i++) ans = (ans + a[i]) % mod;
		ans = (ans + add[p] * (r - l + 1) % mod) % mod;
	}
	else {
		for(int i = l; i <= R[p]; i++) ans = (ans + a[i]) % mod;
		ans = (ans + add[p] * (R[p] - l + 1) % mod) % mod;
		for(int i = p + 1; i <= q - 1; i++) ans = (ans + sum[i]) % mod;
		for(int i = L[q]; i <= r; i++) ans = (ans + a[i]) % mod;
		ans = (ans + add[q] * (r - L[q] + 1) % mod) % mod;
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
			printf("%lld\n", query(l, r, c + 1));
		}
	}
}
