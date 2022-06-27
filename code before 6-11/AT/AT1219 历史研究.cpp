#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int M = 100005, N = 1005;
int c[M], t[M], n, q, s[M], b[M], n1, pos[M], L[N], R[N], l, r;
long long ans[M], sum;
struct query{
	int l, r, i;
	bool operator < (const query &t) const{
		return pos[l] ^ pos[t.l] ? pos[l] < pos[t.l] : r < t.r;
	}
}p[M];
void pre(int n){
	int t = sqrt(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i;
	}
}
int cnt[M], pl, l_, sum_;
long long brute(int l, int r){
	long long ans = 0;
	for(int i = l; i <= r; i++) cnt[c[i]]++;
	for(int i = l; i <= r; i++) ans = max(ans, 1ll * cnt[c[i]] * b[c[i]]);
	for(int i = l; i <= r; i++) cnt[c[i]]--;
	return ans;
}
void del(int t) {--s[t];}
void add(int t, long long &ans){
	++s[t]; ans = max(ans, 1ll * s[t] * b[t]);
}
int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]), b[i] = c[i];
	sort(b+1, b+n+1); n1 = unique(b+1, b+n+1) - b - 1; 
	for(int i = 1; i <= n; i++) c[i] = lower_bound(b+1, b+n1+1, c[i]) - b;
	for(int i = 1; i <= q; i++) scanf("%d %d", &p[i].l, &p[i].r), p[i].i = i;
	pre(n); sort(p+1, p+q+1);
	for(int i = 1; i <= q; i++){
		if(pos[p[i].l] == pos[p[i].r]) {ans[p[i].i] = brute(p[i].l, p[i].r); continue;}
		if(pos[p[i].l] > pl){
			while(r < R[pos[p[i].l]]) add(c[++r], sum);
			while(r > R[pos[p[i].l]]) del(c[r--]);
			while(l < R[pos[p[i].l]] + 1) del(c[l++]);
			sum = 0; pl = pos[p[i].l];
		}
		while(r < p[i].r) add(c[++r], sum);
		ans[p[i].i] = sum; l_ = l;
		while(l > p[i].l) add(c[--l], ans[p[i].i]);
		while(l < l_) del(c[l++]);
	}
	for(int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
