#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int M = 100005, N = 10005;
int n, pos[M], L[N], R[N], a[M], t, op, l, r, c, s[N]; bool z[N];
void pre(int n){
	int t = sqrt(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i;
	}
}
int deal(int l, int r, int c){
	int p = pos[l], ans = 0;
	if(z[p]) {
		if(s[p] == c) return r - l + 1;
		for(int i = L[p]; i <= R[p]; i++) a[i] = s[p];
		for(int i = l; i <= r; i++) a[i] = c;
		z[p] = 0; return 0;
	}
	for(int i = l; i <= r; i++) ans += a[i] == c, a[i] = c;
	return ans;
}
int query(int l, int r, int c){
	int p = pos[l], q = pos[r], ans = 0;
	if(p == q) return deal(l, r, c);
	else {
		ans += deal(l, R[p], c) + deal(L[q], r, c);
		for(int i = p + 1; i <= q - 1; i++) ans += deal(L[i], R[i], c);
	} return ans;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	pre(n);
	for(int k = 1; k <= n; k++){
		scanf("%d %d %d", &l, &r, &c);
		printf("%d\n", query(l, r, c));
	}
}
