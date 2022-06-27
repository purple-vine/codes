#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long
#define ULL unsigned long long
using namespace std;
const long long mod = 7528443412579576937;
LL add(LL a, LL b) {return (1ull * a + 1ull * b) % mod;}
LL mul(int a, int b){
	LL ans = 0;
	for(; b; b >>= 1){
		if(b & 1) ans = add(ans, a);
		a = add(a, a);
	}
	return ans;
}
struct matrix{
	LL a[2][2]; int n, m;
	matrix() {}
	matrix(int n_, int m_) {n = n_; m = m_; memset(a, 0, sizeof(a));}
	matrix(int n_) {
		n = m = n_; memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++) a[i][i] = 1;
	}
	matrix operator * (matrix tmp) const{
		matrix t(n, tmp.m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < t.m; j++)
				for(int k = 0; k < m; k++)
					t.a[i][j] = add(t.a[i][j], mul(a[i][k], tmp.a[k][j]));
		return t;
	}
	LL* operator [] (int i){
		return a[i];
	}
};
matrix qpow(matrix a, LL b){
	matrix ans(2);
	for(; b; b >>= 1) {if(b & 1) ans = ans * a; a = a * a;}
	return ans;
}
LL b, d, n;
int main(){
	scanf("%lld %lld %lld", &b, &d, &n);
	matrix a(2, 2), t(1, 2);
	t[0][0] = 1; t[0][1] = (LL)((b + sqrt(d)) / 2);
	a[0][0] = b; a[1][0] = ((-b * b + d) / 4); a[0][1] = 1;
	matrix ans = t * qpow(a, n);
	printf("%lld\n", ans[0][1] - (n % 2 == 1));
	return 0;
}
