#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005, N = 20005;
int fa[N], num[N], ans[M], n, m, q, siz[N];
int find(int p){
	return fa[p] == p ? p : fa[p] = find(fa[p]);
}
void merge(int u, int v){
	u = find(u); v = find(v);
	if(u != v) fa[u] = v, siz[v] += siz[u];
}
struct A {int x, y, l;} a[M];
struct B {int t, num;} b[N];
bool cmp1(A a, A b) {return a.l < b.l;}
bool cmp2(B a, B b) {return a.t < b.t;}
int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i++)
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].l);
	for(int i = 1; i <= q; i++){
		scanf("%d", &b[i].t);
		b[i].num = i;
	}
	sort(a + 1, a + m + 1, cmp1);
	sort(b + 1, b + q + 1, cmp2);
	for(int k = 1, cnt = 0, p = 0; k <= q; k++){
		int t = b[k].t;
		for(; a[p].l <= t && p <= m; p++){
			int u = find(a[p].x), v = find(a[p].y);
			if(u != v) cnt += siz[u] * siz[v], merge(u, v);
		}
		ans[b[k].num] = cnt * 2;
	}
	for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}
