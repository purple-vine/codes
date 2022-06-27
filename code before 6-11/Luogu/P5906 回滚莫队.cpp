#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#define inf (n + 1)
using namespace std;
const int M = 200005, N = 5005;
int c[M], t[M], n, q, b[M], n1, pos[M], L[N], R[N], l, r, sum;
int minn[M], maxx[M], ans[M]; bool in1[M], in2[M];
struct query{
	int l, r, i;
	bool operator < (const query &t) const{
		return pos[l] ^ pos[t.l] ? pos[l] < pos[t.l] : r < t.r;
	}
}p[M];
struct tp {int p, c;}; queue<tp> m1, m2;
void pre(int n){
	int t = sqrt(n), siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		L[i] = t * (i - 1) + 1; R[i] = min(t * i, n);
		for(int j = L[i]; j <= R[i]; j++)
			pos[j] = i;
	}
}
int m1_[M], m2_[M], pl, l_, sum_;
int brute(int l, int r){
	int ans = 0;
	for(int i = l; i <= r; i++) m1_[c[i]] = min(m1_[c[i]], i), m2_[c[i]] = max(m2_[c[i]], i);
	for(int i = l; i <= r; i++) ans = max(ans, m2_[c[i]] - m1_[c[i]]), m1_[c[i]] = inf, m2_[c[i]] = 0;
	return ans;
}
void set(int ll, int rr){
	while(l < ll) minn[c[l]] = inf, maxx[c[l++]] = 0;
	while(r < rr) minn[c[l]] = inf, maxx[c[r++]] = 0;
	while(r > rr) minn[c[l]] = inf, maxx[c[r--]] = 0;
}
void add(int t, int &ans, bool op){
	int cc = c[t];
	if(t < minn[cc]){
		if(op && !in1[cc]) m1.push({cc, minn[cc]}), in1[cc] = 1;
		minn[cc] = t;
	}
	if(t > maxx[cc]){
		if(op && !in2[cc]) m2.push({cc, maxx[cc]}), in2[cc] = 1;
		maxx[cc] = t;
	}
	ans = max(ans, maxx[cc] - minn[cc]);
}
void roll_back(int ll){
	while(!m1.empty()) in1[m1.front().p] = 0, minn[m1.front().p] = m1.front().c, m1.pop();
	while(!m2.empty()) in2[m2.front().p] = 0, maxx[m2.front().p] = m2.front().c, m2.pop();
	l = ll;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]), b[i] = c[i];
	sort(b+1, b+n+1); n1 = unique(b+1, b+n+1) - b - 1; 
	for(int i = 1; i <= n; i++) c[i] = lower_bound(b+1, b+n1+1, c[i]) - b;
	scanf("%d", &q); for(int i = 1; i <= q; i++) scanf("%d %d", &p[i].l, &p[i].r), p[i].i = i;
	pre(n); sort(p+1, p+q+1); for(int i = 1; i <= n; i++) minn[i] = m1_[i] = inf;
	for(int i = 1; i <= q; i++){
		if(pos[p[i].l] == pos[p[i].r]) {ans[p[i].i] = brute(p[i].l, p[i].r); continue;}
		if(pos[p[i].l] > pl){
			set(R[pos[p[i].l]]+1, R[pos[p[i].l]]);
			sum = 0; pl = pos[p[i].l];
		}
		while(r < p[i].r) add(++r, sum, 0);
		ans[p[i].i] = sum; l_ = l;
		while(l > p[i].l) add(--l, ans[p[i].i], 1);
		roll_back(l_);
	}
	for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
