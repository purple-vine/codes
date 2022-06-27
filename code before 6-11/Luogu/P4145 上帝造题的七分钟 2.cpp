#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long
using namespace std;
const int M = 200005, N = 10005;
int n, pos[M], L[N], R[N], a[M], t, op, l, r, c, sum[M], m; bool z[N];
void pre(int n){
	int t = sqrt(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i, sum[i] += a[j];
	}
}
void deal(int k){
	z[k] = 1; sum[k] = 0;
	for(int i = L[k]; i <= R[k]; i++){
		a[i] = sqrt(a[i]); sum[k] += a[i]; if(a[i] > 1) z[k] = 0;
	}
}
void modify(int l, int r){
	int p = pos[l], q = pos[r];
	if(p == q){
		if(!z[p]) for(int i = l; i <= r; i++) sum[p] -= a[i], a[i] = sqrt(a[i]), sum[p] += a[i];
	}
	else {
		if(!z[p]) for(int i = l; i <= R[p]; i++) sum[p] -= a[i], a[i] = sqrt(a[i]), sum[p] += a[i];
		for(int i = p + 1; i <= q - 1; i++) if(!z[i]) deal(i);
		if(!z[q]) for(int i = L[q]; i <= r; i++) sum[q] -= a[i], a[i] = sqrt(a[i]), sum[q] += a[i];
	}
}
int query(int l, int r){
	int p = pos[l], q = pos[r], ans = 0;
	if(p == q){
		for(int i = l; i <= r; i++) ans += a[i];
	}
	else {
		for(int i = l; i <= R[p]; i++) ans += a[i];
		for(int i = p + 1; i <= q - 1; i++) ans += sum[i];
		for(int i = L[q]; i <= r; i++) ans += a[i]; 
	} return ans;
}
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	pre(n); scanf("%d", &m);
	for(int k = 1; k <= m; k++){
		scanf("%lld %lld %lld", &op, &l, &r);
		if(op == 0){
			modify(min(l, r), max(l, r));
		} else {
			printf("%lld\n", query(min(l, r), max(l, r)));
		}
	}
}
