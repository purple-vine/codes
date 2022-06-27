#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1000005;
bool laz[M * 4], a[M]; int n, m, tt, l, r; char c[10];
struct node{
	int s00, s01, s10, s11;
	node operator + (const node &tmp) const{
		node ans;
		ans.s00 = s00 + tmp.s00;
		ans.s11 = s11 + tmp.s11;
		ans.s01 = max(s00 + tmp.s01, max(s01 + tmp.s11, max(ans.s00, ans.s11)));
		ans.s10 = max(s11 + tmp.s10, max(s10 + tmp.s00, max(ans.s00, ans.s11)));
		return ans;
	}
	void swap(){
		std::swap(s00, s11); std::swap(s01, s10);
	}
}s[M * 4];
void build(int o, int l, int r){
	if(l == r){
		if(a[l] == 1)
			s[o].s01 = s[o].s10 = s[o].s11 = 1;
		else
			s[o].s01 = s[o].s10 = s[o].s00 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(o << 1, l, mid); build(o << 1 | 1, mid + 1, r);
	s[o] = s[o << 1] + s[o << 1 | 1];
}
void pushdown(int o, int l, int r){
	if(!laz[o]) return;
	laz[o << 1] ^= 1; s[o << 1].swap();
	laz[o << 1 | 1] ^= 1; s[o << 1 | 1].swap();
	laz[o] = 0;
}
void modify(int o, int l, int r, int x, int y){
	if(x <= l && r <= y){
		s[o].swap();
		laz[o] ^= 1; return;
	}
	pushdown(o, l, r); int mid = l + r >> 1;
	if(x <= mid) modify(o << 1, l, mid, x, y);
	if(y > mid) modify(o << 1 | 1, mid + 1, r, x, y);
	s[o] = s[o << 1] + s[o << 1 | 1];
}
void debug(int o, int l, int r){
	printf("%d: %d %d 00:%d 01:%d 10:%d 11:%d\n", o, l, r, s[o].s00, s[o].s01, s[o].s10, s[o].s11);
	int mid = l + r >> 1;
	if(l == r) return;
	debug(o << 1, l, mid); debug(o << 1 | 1, mid + 1, r);
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%1d", &tt);
		if(tt == 7) a[i] = 1;
		else a[i] = 0;
	}
	build(1, 1, n);
//	debug(1, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("%s", c);
		if(c[0] == 'c') printf("%d\n", s[1].s01);
		else{
			scanf("%d %d", &l, &r);
			modify(1, 1, n, l, r);
		}
//		debug(1, 1, n);
	}
}
