#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long 
using namespace std;
const int M = 15; int mod;
struct matrix{
	int a[M][M], n, m;
	matrix operator * (const matrix &tmp) const{
		matrix t; memset(t.a, 0, sizeof(t.a)); t.n = n; t.m = tmp.m;
		for(int i = 1; i <= t.n; i++)
			for(int j = 1; j <= t.m; j++)
				for(int k = 1; k <= m; k++)
					t.a[i][j] = (t.a[i][j] + a[i][k] * tmp.a[k][j]) % mod;
		return t;
	}
}t, a, ans;
matrix qpow(matrix a, int k){
	matrix t; t.n = t.m = a.n; memset(t.a, 0, sizeof(t.a));
	for(int i = 1; i <= t.n; i++) t.a[i][i] = 1;
	for(; k; k >>= 1){
		if(k & 1) t = t * a;
		a = a * a;
	}
	return t;
}
void set(int i, int j, int k) {t.a[j][i] = k;}
int n, p, q, r, tt, u, v, w, x, y, z;
int xx[18] = {1, 2, 2, 2 , 3, 4, 4, 4, 5, 6, 6, 6, 6 , 9, 9 , 10, 10, 11};
int yy[18] = {2, 4, 6, 11, 4, 2, 6, 7, 6, 2, 4, 8, 10, 9, 11, 10, 11, 11};
signed main(){
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &n, &mod, &p, &q, &r, &tt, &u, &v, &w, &x, &y, &z);
	t.n = t.m = 11; a.n = 1; a.m = n;
	a.a[1][1] = a.a[1][3] = a.a[1][5] = a.a[1][9] = a.a[1][10] = a.a[1][11] = 1; a.a[1][2] = a.a[1][4] = a.a[1][6] = 3;
	a.a[1][7] = w; a.a[1][8] = z;
	for(int i = 0; i < 18; i++) set(xx[i], yy[i], 1);
	set(6, 11, 2); set(9, 10, 2);
	set(2, 1, q); set(2, 2, p); set(2, 9, r); set(2, 10, tt); set(4, 3, v); set(4, 4, u);
	set(6, 5, y); set(6, 6, x); set(7, 7, w); set(8, 8, z);
	ans = a * qpow(t, n - 1);
	printf("nodgd %d\nCiocio %d\nNicole %d\n", ans.a[1][1], ans.a[1][3], ans.a[1][5]);
}
/*
1, 3, 1, 3, 1, 3, w, z, 1, 1, 1

	1 2 3 4 5 6 7 8 9 10 11
	
1	0 1 0 0 0 0 0 0 0 0 0
2	q p 0 1 0 1 0 0 r t 1
3	0 0 0 1 0 0 0 0 0 0 0
4	0 1 v u 0 1 1 0 0 0 0
5	0 0 0 0 0 1 0 0 0 0 0
6	0 1 0 1 y x 0 1 0 1 2
7	0 0 0 0 0 0 w 0 0 0 0
8	0 0 0 0 0 0 0 z 0 0 0
9	0 0 0 0 0 0 0 0 1 2 1
10	0 0 0 0 0 0 0 0 0 1 1
11	0 0 0 0 0 0 0 0 0 0 1
*/
