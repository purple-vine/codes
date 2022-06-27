#include <cstdio>
#include <iostream>
#include <cmath>
#define int long long
// #define double long double
using namespace std;
const int M = 200005, N = 200005;
int n, pos[M], t, siz, op, l, r, m; double S, T, x[M], y[M];
namespace zag{
	int sqrt(int t){
		int ans = 0;
		for(; ans * ans <= t; ans++);
		return ans - 1;
	}
}
struct node{
	double xs, xf, xy, ys; int op, l, r, n; //x_i, x_i^2, x_i*y_i, y_i 
	double s, t, s1, s2; //sum l-r, sum l^2-r^2 
	void change1(int ss, int tt){
		s = ss; t = tt; op = 1;
		xf += 2*s*xs + n*s*s;
		xy += s*ys + t*xs + n*s*t;
		xs += n*s; ys += n*t;
	}
	void change2(int ss, int tt){
		s = ss; t = tt; op = 2;
		xf = n*s*s + 2*s*s1 + s2; xs = s1 + n * s;
		xy = n*s*t + (s+t)*s1 + s2; ys = s1 + n * t;
	}
	void pushdown(){
		if(op == 1){
			for(int i = l; i <= r; i++)
				x[i] += s, y[i] += t;
		} else if(op == 2) {
			for(int i = l; i <= r; i++)
				x[i] = s + i, y[i] = t + i;
		} s = t = op = 0;
	}
	void operator += (const node &t){
		xs += t.xs; ys += t.ys; xf += t.xf; xy += t.xy; n += t.n;
	}
	void minus(int x, int y){
		xs -= x; ys -= y; xy -= x*y; xf -= x*x; n--;
	}
	void add(int x, int y){
		xs += x; ys += y; xy += x*y; xf += x*x; n++;
	}
	void print(){
		printf("xs=%d xf=%d xy=%d ys=%d l=%d r=%d n=%d op=%d s=%d t=%d\n", xs, xf, xy, ys, l, r, n, op, s, t);
	}
}s[N];
void pre(int n){
	t = zag::sqrt(n); siz = ceil(1.0 * n / t);
	for(int i = 1; i <= siz; i++){
		s[i].l = t * (i - 1) + 1; s[i].r = min(t * i, n); s[i].n = s[i].r - s[i].l + 1;
		for(int j = s[i].l; j <= s[i].r; j++){
			pos[j] = i; s[i].xs += x[j]; s[i].ys += y[j];
			s[i].xf += x[j] * x[j]; s[i].xy += x[j] * y[j];
			s[i].s1 += j; s[i].s2 += j * j;
		}
	}
}
void deal1(int p, int l, int r){
	for(int i = l; i <= r; i++)
		s[p].minus(x[i], y[i]), x[i] += S, y[i] += T, s[p].add(x[i], y[i]);
}
void modify1(int l, int r){
	int p = pos[l], q = pos[r];
	if(p == q){
		s[p].pushdown();
		deal1(p, l, r);
	} else {
		s[p].pushdown(); s[q].pushdown();
		deal1(p, l, s[p].r);
		for(int i = p + 1; i <= q - 1; i++) s[i].change1(S, T);
		deal1(q, s[q].l, r);
	}
}
void deal2(int p, int l, int r){
	for(int i = l; i <= r; i++)
		s[p].minus(x[i], y[i]), x[i] = S + i, y[i] = T + i, s[p].add(x[i], y[i]);
}
void modify2(int l, int r){
	int p = pos[l], q = pos[r];
	if(p == q){
		s[p].pushdown();
		deal2(p, l, r);
	} else {
		s[p].pushdown(); s[q].pushdown();
		deal2(p, l, s[p].r);
		for(int i = p + 1; i <= q - 1; i++) s[i].change2(S, T);
		deal2(q, s[q].l, r);
	}
}
node query(int l, int r){
	int p = pos[l], q = pos[r]; node ans = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if(p == q){
		s[p].pushdown();
		for(int i = l; i <= r; i++) ans.add(x[i], y[i]);
	}
	else {
		s[p].pushdown(); s[q].pushdown();
		for(int i = l; i <= s[p].r; i++) ans.add(x[i], y[i]);
		for(int i = p + 1; i <= q - 1; i++) ans += s[i];
		for(int i = s[q].l; i <= r; i++) ans.add(x[i], y[i]);
	} return ans;
}
signed main(){
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lf", &x[i]);
	for(int i = 1; i <= n; i++) scanf("%lf", &y[i]);
	pre(n);
	for(int k = 1; k <= m; k++){
		scanf("%lld %lld %lld", &op, &l, &r);
		if(op == 1){
			node ans = query(l, r);
//			printf("xy:%lld xs:%lld ys:%lld n:%lld xf:%lld\n", ans.xy, ans.xs, ans.ys, ans.n, ans.xf);
			printf("%lf\n", 1.0 * (1.0*ans.xy - 1.0*ans.xs*ans.ys/ans.n) / (1.0*ans.xf-1.0*ans.xs*ans.xs/ans.n));
//			printf("%Lf\n", (long double)1.0 * (n * ans.xy - ans.xs * ans.ys) / (n * ans.xf - ans.xs * ans.xs));
		} else {
			scanf("%lf %lf", &S, &T);
			op == 2 ? modify1(l, r) : modify2(l, r);
		}
		for(int i = 1; i <= siz; i++){
			s[i].pushdown(); //s[i].print();
		}
//		for(int i = 1; i <= n; i++) printf("%d ", x[i]);
//		printf("\n");
//		for(int i = 1; i <= n; i++) printf("%d ", y[i]);
//		printf("\n");
	}
}
/*
3 5
1 2 3
1 2 3
1 1 3
2 2 3 -3 2
1 1 2
3 1 2 2 1
1 1 3
*/
