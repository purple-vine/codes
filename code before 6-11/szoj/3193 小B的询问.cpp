#include <cstdio>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
const int M = 55005;
int c[M], s[M], t, n, m, l = 1, r, sum, ans[M], k;
struct query{
	int x, y, i;
	bool operator < (const query &tmp){
		if(x/t != tmp.x/t) return x/t < tmp.x/t;
		if(x/t ^ 1) return y < tmp.y;
		else return y > tmp.y;
	}
}p[M];
void add(int t){
	s[t]++; sum += 2 * s[t] - 1;
}
void del(int t){
	sum -= 2 * s[t] - 1; s[t]--;
}
signed main(){
	scanf("%lld %lld %lld", &n, &m, &k);
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
		ans[p[i].i] = sum;
	}
	for(int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
}
