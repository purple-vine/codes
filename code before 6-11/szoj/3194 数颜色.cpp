//该题数据真的太水了
//l写错方向，块长取1，都能过
//个人感觉暴力也能过（ 
//https://www.luogu.com.cn/discuss/397110
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int M = 150005, N = 10005;
int n, m, l = 0, r = 0, k, x, y, cnt, t = 0, L; char op;
struct tp{
	int x, y, t, i;
	bool operator < (const tp &b) const{
		return x/L != b.x/L ? x < b.x : y/L != b.y/L ? (y<b.y) ^ ((x/L)%2) : t<b.t;
	}
} a[M];
struct query{
	int x, y;
}p[M];
int sum, s[1000005], c[M], ans[M];
void add(int t){
	sum += !s[t]++;
}
void del(int t){
	sum -= !--s[t];
}
void deal(int t){
	if(l <= p[t].x && p[t].x <= r){
		del(c[p[t].x]); add(p[t].y);
	}
	swap(c[p[t].x], p[t].y);
} 
int main(){
	scanf("%d %d", &n, &m); L = pow(n, 2.0/3);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1; i <= m; i++){
		scanf(" %c %d %d", &op, &x, &y);
		if(op == 'Q') a[++cnt] = {x, y, k, cnt};
		else p[++k] = {x, y};
	} 
	sort(a + 1, a + cnt + 1); 
	for(int i = 1; i <= cnt; i++){
		while(l < a[i].x) del(c[l++]);
		while(l > a[i].x) add(c[--l]);
		while(r < a[i].y) add(c[++r]);
		while(r > a[i].y) del(c[r--]);
		while(t < a[i].t) deal(++t);
		while(t > a[i].t) deal(t--);
		ans[a[i].i] = sum;
	} for(int i = 1; i <= cnt; i++) printf("%d\n", ans[i]);
}
