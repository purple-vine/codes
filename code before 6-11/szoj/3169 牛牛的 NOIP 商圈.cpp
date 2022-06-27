#include <cstdio>
#include <cstring>
#define p 1000000007
using namespace std;
const int M = 259;
struct matrix{
	int a[M][M], n, m;
	matrix(int N, int M, bool f) : n(N), m(M) {
		memset(a, 0, sizeof(a));
		if(f) for(int i = 0; i < n; i++) a[i][i] = 1;
	}
	matrix operator * (const matrix &tmp) const{
		matrix t(n, tmp.m, 0);
		for(int i = 0; i < t.n; i++)
			for(int j = 0; j < t.m; j++)
				for(int k = 0; k < m; k++)
					t.a[i][j] = (t.a[i][j] + 1ll * a[i][k] * tmp.a[k][j]) % p;
		return t;
	}
	void print(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) printf("%d ", a[i][j]);
			printf("\n");
		}
	}
};
matrix qpow(matrix a, long long k){
	matrix t(a.n, a.n, 1);
	for(; k; k >>= 1){
		if(k & 1) t = t * a;
		a = a * a; 
	} return t;
}
int m, mx, anss; long long n;
bool chk(int t){
	int s = t & 3;
	for(int i = 1; t && i < m; i++){
		t >>= 2; if((t & 3) != s) return 1; //牢记 (k & 3) 不加括号的错误 
	} return 0;
}
matrix make(){
	matrix ans(mx + 1, mx + 1, 0);
	for(int i = 0; i <= mx; i++){
		for(int j = 0; j < 4; j++){
			int t = (i << 2) | j;
			ans.a[i][t & mx] += chk(t);
		}
	} return ans;
}
int plus(int a, int b){
	a += b; return a > p ? a - p : a;
}
int main(){
	scanf("%lld %lld", &n, &m);
	mx = (1 << (m - 1 << 1)) - 1;
	matrix ans = make();
	ans = qpow(ans, n - 1);
	for(int i = 0; i <= mx; i++){
		for(int j = 0; j < 4; j++){
			int s1 = ((j << (m - 1 << 1)) | i);
			if(chk(s1))
				anss = plus(anss, ans.a[i][s1 >> 2]);
		}
	}
	printf("%lld\n", anss);
}
