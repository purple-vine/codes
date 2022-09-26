#include <cstdio>
#include <cstring>
#define p 1000000007
#define F(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int M = 205;
int add(int a, int b) {return (a += b) > p ? a-p : a;}
struct edge{
	int to, nxt;
}e[M << 1];
int head[M], cnt1;
void link(int u, int v){
	e[++cnt1].to = v; e[cnt1].nxt = head[u]; head[u] = cnt1;
}
struct matrix{
    int a[M][M], n, m;
    matrix(int n_, int m_, bool f){
		n = n_; m = m_; memset(a, 0, sizeof(a));
		if(f) F(i, n) a[i][i] = 1;
	}
	matrix() {}
    matrix operator * (const matrix &tmp) const{
        matrix t; t.n = n; t.m = tmp.m; memset(t.a, 0, sizeof(t.a));
        F(i, n) F(j, t.m) F(k, m) t.a[i][j] = add(t.a[i][j], 1ll * a[i][k] * tmp.a[k][j] % p);
        return t;
    }
	void print(){
		printf("%d %d\n", n, m);
		F(i, n) {F(j, m) printf("%d ", a[i][j]); printf("\n");}
		printf("\n");
	}
};
matrix qpow(matrix a, long long k){
	matrix t(a.n, a.n, 1);
	for(; k; k >>= 1){
		if(k & 1) t = t * a;
		a = a * a; 
	} return t;
}
int calc(long long k){
    int ans = 0;
    for(; k; k -= (k & -k)) ++ans;
    return ans;
}
int n, m, t, b, u, v, ans; long long k, a[M];
int main(){
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	matrix s2(n, n, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            if(calc(a[i] ^ a[j]) % 3 == 0) s2.a[i][j] = 1;
    }
//	s1.print(); s2.print();
	s2 = qpow(s2, k - 1); // s2.print();
	for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans = add(ans, s2.a[i][j]);
	printf("%d\n", ans);
}