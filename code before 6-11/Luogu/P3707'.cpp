#include <cstdio>
#include <iostream>
#include <cmath>
//#define double int
//#define int long long
// #define double long double
using namespace std;
const int M = 200005, N = 200005;
int n, pos[M], t, siz, op, l, r, m; double S, T, x[M], y[M];
double powersum(int t){
	return t * (t+1) * (2*t+1) / 6;
}
double getsum(int l, int r){
	return (l+r) * (r-l+1) / 2;
}
namespace st{
	struct node{
		double xs, xf, xy, ys; int n; //x_i, x_i^2, x_i*y_i, y_i 
		double s1, t2, s1, s2; //add:1 set:2
		void upd(node ls, node rs){
			xs = ls.xs + rs.xs; xf = ls.xf + rs.xf;
			xy = ls.xy + rs.xy; ys = ls.ys + rs.ys;
		}
		void operator += (const node &t){ //用于累计答案 
			xs += t.xs; ys += t.ys; xf += t.xf; xy += t.xy; n += t.n;
		}
		void setup(int x, int y, int t){
			xs = x; ys = y; xy = x*y; xf = x*x;
			s1 = t; s2 = t * t; n = 1;
		}
		void print(){
			printf("xs=%.lf xf=%.lf xy=%.lf ys=%.lf op=%d s=%.lf t=%.lf\n", xs, xf, xy, ys, op, s, t);
		}
	}s[M << 2];
	void pushdown(int o, int l, int r){
		int mid = l + r >> 1; 
		if(s[o].s1 || s[o].t1){
			s[o<<1].s1 += s[o].s1; s[o<<1].t1 += s[o].t1;
			s[o<<1].xf += 2 * s[o].s1 * s[o<<1].xs + s[o<<1].n * s[o].s1 * s[o].s1; 
			s[o<<1].xy += s* s[o<<1].ys + s[o<<1].t * s[o<<1].xs + n * s[o].s1 * s[o].t1;
			s[o<<1].xs += s[o<<1].n * s[o].s1;
			s[o<<1].ys += s[o<<1].n * s[o].t1;
			
			s[o<<1|1].s1 += s[o].s1; s[o<<1|1].t1 += s[o].t1;
			s[o<<1|1].xf += 2 * s[o].s1 * s[o<<1|1].xs + s[o<<1|1].n * s[o].s1 * s[o].s1; 
			s[o<<1|1].xy += s* s[o<<1|1].ys + s[o<<1|1].t * s[o<<1|1].xs + n * s[o].s1 * s[o].t1;
			s[o<<1|1].xs += s[o<<1|1].n * s[o].s1;
			s[o<<1|1].ys += s[o<<1|1].n * s[o].t1;
			s[o].s1 = s[o].t1 = 0;
		}
		if(s[o].s2 || s[o].t2){
			s[o<<1].op2 = s
		}
	}
	void build(int o, int l, int r){
		if(l == r) {s[o].setup(x[l], y[l], l); return;}
		int mid = l + r >> 1;
		build(o<<1, l, mid); build(o<<1|1, mid+1, r);
		s[o].upd(s[o<<1], s[o<<1|1]); s[o].n = r - l + 1;
		s[o].s1 = getsum(l, r); s[o].s2 = powersum(r) - powersum(l-1);
	}
	void modify(int o, int l, int r, int x, int y, int op){
		if(x <= l && r <= y) {s[o].set(S, T, op); return;}
		int mid = l + r >> 1; pushdown(o, l, r);
		if(x <= mid) modify(o<<1, l, mid, x, y, op);
		if(y > mid) modify(o<<1|1, mid+1, r, x, y, op);
		s[o].upd(s[o<<1], s[o<<1|1]);
	}
	node query(int o, int l, int r, int x, int y){
		if(x <= l && r <= y) return s[o];
		node ans = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int mid = l + r >> 1; pushdown(o, l, r);
		if(x <= mid) ans += query(o<<1, l, mid, x, y);
		if(y > mid) ans += query(o<<1|1, mid+1, r, x, y);
		return ans;
	}
	void debug(int o, int l, int r){
//		printf("o=%d l=%d r=%d ", o, l, r); s[o].print();
		pushdown(o, l, r);
		if(l == r) return; int mid = l + r >> 1;
		debug(o<<1, l, mid); debug(o<<1|1, mid+1, r);
	}
}
signed main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lf", &x[i]);
	for(int i = 1; i <= n; i++) scanf("%lf", &y[i]);
	st::build(1, 1, n); //st::debug(1, 1, n);
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
		} //st::debug(1, 1, n);
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
