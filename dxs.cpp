#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int M = 300005, p = 998244353;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
	return ans;
}
int inv(int k) {return qpow(k, p - 2);}
int add(int a, int b) {a += b; return a > p ? a-p : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+p : a;}

const int G = 3, invG = inv(G);
int tr[M];
void px(int *ans, int *b, int n){
	for(int i = 0; i < n; i++)
		ans[i] = 1ll * ans[i] * b[i] % p;
} 
void mul(int *f, int n, int t){
    for(int i = 0; i < n; i++)
        f[i] = 1ll * f[i] * t % p;
}
void print(int *val, int n){
	for(int j = 0; j < n; j++) printf("%d ", val[j]);
	printf("\n");
}
void clr(int *f, int n = M-5){
    for(int i = 0; i < n; i++)
        f[i] = 0;
}
void cpy(int *f, int *g, int n){
    for(int i = 0; i < n; i++)
        f[i] = g[i];
}
void print(char s[], int *val, int n){
	printf("%s:", s);
	for(int j = 0; j < n; j++) printf("%d ", val[j]);
	printf("\n");
}
void add(int *ans, int *f, int *g, int n){
    for(int i = 0; i < n; i++)
        ans[i] = add(f[i], g[i]);
}
void mins(int *ans, int *f, int *g, int n){
    for(int i = 0; i < n; i++)
        ans[i] = mins(f[i], g[i]);
}
void qiudao(int *f, int n){
    for(int i = 1; i < n; i++)
        f[i-1] = 1ll * i * f[i] % p;
    f[n-1] = 0;
}
int invn[M];
void jifen(int *f, int n){
    for(int i = n; i > 0; i--)
        f[i] = 1ll * f[i-1] * inv(i) % p;
    f[0] = 0;
}
void pre(int n){
    invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * invn[p%i] * (p - p/i) % p;
}

void NTT(int *g, int n, int type){
    //F(x) = FL(x^2) + x*FR(x^2)
    //F(W^k) = FL(w^k) + W^k*FR(w^k)
    //F(W^{k+n/2}) = FL(w^k) - W^k*FR(w^k)
    int *f = new int[M]; clr(f); cpy(f, g, n);
	for(int i = 0; i < n; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
	for(int i = 0; i < n; i++) if(i < tr[i])
		swap(f[i], f[tr[i]]);
	for(int l = 2; l <= n; l <<= 1){
		int tg = qpow(type ? G : invG, (p-1)/l);
		for(int s = 0; s < n; s += l){
			int buf = 1;
			for(int k = s; k < s + l/2; k++){
				int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
				f[k+l/2] = mins(f[k], tt); f[k] = add(f[k], tt);
			}
		}
	} 
    if(type) mul(f, n, inv(n));
    cpy(g, f, n);
}

void mul(int *f, int *g, int len, int lim){
    int *tmp = new int[M];
    int n = 1; for(; n <= len+len; n <<= 1);
    clr(tmp, n); cpy(tmp, g, n);
    NTT(f, n, 0); NTT(tmp, n, 0);
    px(f, tmp, n); NTT(f, n, 1);
    clr(f + lim, n - lim); clr(tmp, n);
    delete[] tmp;
}

void inv(int *k, int len){
	// f(x) = 2*r(x) - r(x)^2 * F(x) (mod x^n)
    //      = r(x) * (2 - r(x) * F(x))
	//r:前n/2位 f:前n位 
    int *f = new int[M], *r = new int[M], *tmp = new int[M], *tmp2 = new int[M];
    clr(r); clr(tmp); clr(tmp2);
	int n = 1; for(; n <= len; n <<= 1);
    f[0] = inv(k[0]);
    for(int l = 2; l <= n; l <<= 1){
        cpy(r, f, l/2); mul(r, l/2, 2);
        NTT(f, l << 1, 0); px(f, f, l << 1);
        // 下面拷 l 位就够了，不要拷 l<<1 位
        cpy(tmp, k, l); NTT(tmp, l << 1, 0); px(f, tmp, l << 1);
        NTT(f, l << 1, 1); clr(f + l, l);
        mins(f, r, f, l);
    }
    cpy(k, f, n);
    delete[] f, r, tmp, tmp2;
}

void ln(int *g, int len){
    int *f = new int[M]; cpy(f, g, len);
    qiudao(f, len); inv(g, len);
    mul(g, f, len, len); jifen(g, len-1);
    delete[] f;
}

int n, m;
int a[M], b[M], ans[M];
int main(){
	scanf("%d", &n);
    for(int i = 0; i < n; i++) a[i] = (read() + p) % p;
    ln(a, n); print(a, n);
}
/*
5
1 6 3 4 9
*/