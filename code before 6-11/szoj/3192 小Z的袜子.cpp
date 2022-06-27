#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int M = 55005;
int c[M], s[M], t, n, m, l = 1, r, sum;
struct query{
	int x, y, i;
	bool operator < (const query &tmp){
		if(x/t != tmp.x/t) return x/t < tmp.x/t;
		if(x/t ^ 1) return y < tmp.y;
		else return y > tmp.y;
	}
}p[M];
int gcd(int x, int y){
	return y == 0 ? x : gcd(y, x%y);
}
struct anss{
	int u, v;
	void out(){
		if(v == 0) {puts("0/1"); return;}
		int g = gcd(u, v); printf("%d/%d\n", u/g, v/g);
	}
}ans[M];
void add(int t){
	sum += 2* (++s[t]) - 1;
}
void del(int t){
	sum -= 2 * (s[t]--) - 1;
}
signed main(){
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld", &p[i].x, &p[i].y); p[i].i = i;
	}
	t = pow(n, 2.0/3); sort(p+1, p+m+1);
	for(int i = 1; i <= m; i++){
		while(r < p[i].y) add(c[++r]);
		while(l > p[i].x) add(c[--l]);
		while(r > p[i].y) del(c[r--]);
		while(l < p[i].x) del(c[l++]);
		ans[p[i].i].u = sum;
	}
	for(int i = 1; i <= m; i++) ans[i].out();
}
