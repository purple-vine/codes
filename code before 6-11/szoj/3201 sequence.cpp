#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long 
using namespace std;
const int M = 85;
struct matrix{
	int a[M][M], n, m;
	matrix operator * (const matrix &tmp) const{
		matrix t; memset(t.a, 0, sizeof(t.a)); t.n = n; t.m = tmp.m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= t.m; j++)
				for(int k = 1; k <= m; k++)
					t.a[i][j] += a[i][k] * tmp.a[k][j];
		return t;
	}
}t, a, a2, ans;
matrix qpow(matrix a, int k){
	matrix t; t.n = t.m = a.n; memset(t.a, 0, sizeof(t.a));
	for(int i = 1; i <= t.n; i++) t.a[i][i] = 1;
	for(; k; k >>= 1){
		if(k & 1) t = t * a;
		a = a * a; // 把快速幂模板打错的我…… 
	}
	return t;
}
int n, s, m, k;
signed main(){
	scanf("%lld %lld %lld %lld", &n, &s, &m, &k); t.n = 1; t.m = n;
	for(int i = 1; i <= n; i++) scanf("%lld", &t.a[1][i]);
	a.n = a.m = a2.n = a2.m = n;
	for(int i = 1; i <= n; i++) a.a[i % n + 1][i] = 1, a2.a[i][i] = 1;
	a2.a[s][s] = 0; a2.a[s][m] = 1; a2.a[m][m] = 0; a2.a[m][s] = 1;
	ans = t * qpow(a2 * a, k);
	for(int i = 1; i <= n; i++) printf("%lld ", ans.a[1][i]);
}
