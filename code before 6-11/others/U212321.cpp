#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 1000005, mod = 1e9+7;
int c[M], s[M], t, n, m, l = 1, r, sum, anss = 1, inv[M], ans[M];
int read(){
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
struct query{
	int x, y, i;
	bool operator < (const query &b) const{
		return x/t != b.x/t ? x < b.x : y/t != b.y/t ? (y<b.y) ^ ((x/t)%2) : i<b.i;
	}
}p[M];
void pre(int n){ 
  inv[1] = 1;
  for(int i = 2; i <= n; i++)
      inv[i] = 1ll * (mod - mod/i) * inv[mod%i] % mod;
}
void add(int t){
//	printf("add %d with ans = %d\n", t, anss);
	++s[t];
	if(s[t] - 1) anss = 1ll * anss * inv[s[t]-1] % mod * s[t] % mod;
//	printf("now anss = %d\n", anss);
}
void del(int t){
//	printf("del %d with ans = %d\n", t, anss);
	--s[t];
	if(s[t]) anss = 1ll * anss * inv[s[t]+1] % mod * s[t] % mod;
//	printf("now anss = %d\n", anss);
}
int main(){
	n = read(); m = read(); pre(n);
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 1; i <= m; i++){
		p[i].x = read(); p[i].y = read(); p[i].i = i;
	}
	t = sqrt(n); anss = 1; sort(p+1, p+m+1);
	for(int i = 1; i <= m; i++){
//		printf("x = %d y = %d\n", p[i].x, p[i].y);
		while(r < p[i].y) add(c[++r]);
		while(l > p[i].x) add(c[--l]);
		while(r > p[i].y) del(c[r--]);
		while(l < p[i].x) del(c[l++]);
		ans[p[i].i] = anss;
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
