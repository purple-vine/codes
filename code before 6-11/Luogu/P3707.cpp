#include <cstdio>
#include <iostream>
#include <cmath>
//#define double int
//#define int long long
// #define double long double
using namespace std;
const int M = 200005, N = 200005;
int n, pos[M], t, siz, op, l, r, m, L, R; double S, T, x[M], y[M];
double cal(int l, int r){
	return (r - l + 1) * (l + r) / 2;
}
double calc(int t){
	return 1.0 * t * (t - 1) * (2 * t - 1) / 6;
}
namespace st{
	struct node{
		double xs, xf, xy, ys; int n, op; //x_i, x_i^2, x_i*y_i, y_i 
		double s, t, s1, s2;
		void clear(){
			xs = xf = xy = ys = n = op = s = t = s1 = s2 = 0;
		}
		void set(int ss, int tt, int op){
			if(op == 1) set1(ss, tt, 1);
			else if(op == 2) set2(ss, tt);
		}
		void set1(int ss, int tt, bool f){
			s = ss; t = tt; op = f == 1 ? 1 : 2;
			xf += 2*s*xs + n*s*s; 
			xy += s*ys + t*xs + n*s*t;
			xs += n*s; ys += n*t;
		}
		void set2(int ss, int tt){
			xs = ys = s1; xf = xy = s2;
			set1(ss, tt, 0);
		}
		void pushdown(node &ls, node &rs){
			if(op == 0) return;
			ls.set(s, t, op); rs.set(s, t, op);
			s = t = op = 0;
		}
		void upd(node ls, node rs){
			xs = ls.xs + rs.xs; xf = ls.xf + rs.xf;
			xy = ls.xy + rs.xy; ys = ls.ys + rs.ys;
		}
		void operator += (const node &t){ //用于累计答案 
			xs += t.xs; ys += t.ys; xf += t.xf; xy += t.xy; n += t.n;
		}
		void setup(int x, int y, int t){
			xs = x; ys = y; xy = x*y; xf = x*x;
			n = 1; s1 = t; s2 = t * t;
		}
		void print(){
			printf("xs=%.lf xf=%.lf xy=%.lf ys=%.lf op=%d s=%.lf t=%.lf\n", xs, xf, xy, ys, op, s, t);
		}
	}s[M << 2];
	void build(int o, int l, int r){
		if(l == r) {s[o].setup(x[l], y[l], l); return;}
		int mid = l + r >> 1;
		build(o<<1, l, mid); build(o<<1|1, mid+1, r);
		s[o].upd(s[o<<1], s[o<<1|1]); s[o].n = r - l + 1;
		s[o].s1 = s[o<<1].s1 + s[o<<1|1].s1; s[o].s2 = s[o<<1].s2 + s[o<<1|1].s2;
	}
	void modify(int o, int l, int r, int x, int y, int op){
		if(x <= l && r <= y) {s[o].set(S, T, op); return;}
		int mid = l + r >> 1; s[o].pushdown(s[o<<1], s[o<<1|1]);
		if(x <= mid) modify(o<<1, l, mid, x, y, op);
		if(y > mid) modify(o<<1|1, mid+1, r, x, y, op);
		s[o].upd(s[o<<1], s[o<<1|1]);
	}
	node query(int o, int l, int r, int x, int y){
		if(x <= l && r <= y) return s[o];
		node ans; ans.clear();
		int mid = l + r >> 1; s[o].pushdown(s[o<<1], s[o<<1|1]);
		if(x <= mid) ans += query(o<<1, l, mid, x, y);
		if(y > mid) ans += query(o<<1|1, mid+1, r, x, y);
		return ans;
	}
	void debug(int o, int l, int r){
//		printf("o=%d l=%d r=%d ", o, l, r); s[o].print();
		s[o].pushdown(s[o<<1], s[o<<1|1]);
		if(l == r) return; int mid = l + r >> 1;
		debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
	}
}
signed main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lf", &x[i]);
	for(int i = 1; i <= n; i++) scanf("%lf", &y[i]);
	st::build(1, 1, n); st::debug(1, 1, n);
	for(int k = 1; k <= m; k++){
		scanf("%d %d %d", &op, &l, &r);
		if(op == 1){
			st::node ans = st::query(1, 1, n, l, r);
//			printf("xy:%.lf xs:%.lf ys:%.lf n:%d xf:%.lf\n", ans.xy, ans.xs, ans.ys, ans.n, ans.xf);
			printf("%lf\n", 1.0 * (1.0*ans.xy - 1.0*ans.xs*ans.ys/ans.n) / (1.0*ans.xf-1.0*ans.xs*ans.xs/ans.n));
//			printf("%Lf\n", (long double)1.0 * (n * ans.xy - ans.xs * ans.ys) / (n * ans.xf - ans.xs * ans.xs));
		} else {
			scanf("%lf %lf", &S, &T);
			st::modify(1, 1, n, l, r, op - 1);
		} st::debug(1, 1, n);
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
