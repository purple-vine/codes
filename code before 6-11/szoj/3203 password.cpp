#include <cstdio>
#include <cstring>
#include <algorithm>
#define p 19260817
#define int long long 
using namespace std;
const int M = 15;
struct matrix{
	int a[M][M], n, m;
	matrix operator * (const matrix &tmp) const{
		matrix t; memset(t.a, 0, sizeof(t.a)); t.n = n; t.m = tmp.m;
		for(int i = 1; i <= t.n; i++)
			for(int j = 1; j <= t.m; j++)
				for(int k = 1; k <= m; k++)
					t.a[i][j] = (t.a[i][j] + a[i][k] * tmp.a[k][j]) % p;
		return t;
	}
}a, t;
matrix qpow(matrix a, int k){
	matrix t; t.n = t.m = a.n; memset(t.a, 0, sizeof(t.a));
	for(int i = 1; i <= t.n; i++) t.a[i][i] = 1;
	for(; k; k >>= 1){
		if(k & 1) t = t * a;
		a = a * a;
	}
	return t;
}
int n, m;
signed main(){
	scanf("%d", &m);
	a.a[1][1] = 1; a.a[1][2] = 2; a.a[1][3] = 4; a.n = 1; a.m = 3;
	t.a[1][3] = t.a[2][1] = t.a[2][3] = t.a[3][2] = t.a[3][3] = 1; t.n = t.m = 3;
	while(m--){
		scanf("%d", &n);
		matrix ans = a * qpow(t, n);
		printf("%d\n", ans.a[1][1]);
	}
}
