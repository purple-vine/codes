#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
// mark：不开到 1e7+5 会神秘 WA，但是开到 1e7+5 不会 MLE……
const int M = 1e7+5, p = 1004535809;
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
// int inv(int k) {return qpow(k, p - 2);}
int add(int a, int b) {a += b; return a > p ? a-p : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+p : a;}

const int G = 3, invG = qpow(G, p-2);

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


void NTT(int *g, int n, int type){
    static int f[M];
    //F(x) = FL(x^2) + x*FR(x^2)
    //F(W^k) = FL(w^k) + W^k*FR(w^k)
    //F(W^{k+n/2}) = FL(w^k) - W^k*FR(w^k)
    cpy(f, g, n);
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
    if(type) mul(f, n, qpow(n, p-2));
    cpy(g, f, n); clr(f, n);
}

void polymul(int *f, int *g, int len, int lim){
    static int k1[M];
    int n = 1; for(; n <= len+len; n <<= 1);
    cpy(k1, g, n);
    NTT(f, n, 0); NTT(k1, n, 0);
    px(f, k1, n); NTT(f, n, 1);
    clr(f + lim, n - lim); clr(k1, n);
}


int n, m, s, w[M];
int f[M], g[M], fac[M], invfac[M], c[M], mn, inv[M];
int C(int n, int m) {return m > n ? 0 :  1ll * fac[n] * invfac[m] % p * invfac[n-m] % p;}
int main(){
    // freopen("io/color1.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &s);
    assert(m <= 1e5+5);
    fac[0] = invfac[0] = 1;
    inv[1] = 1;
    for(int i = 2; i <= max(n, m); i++)
        inv[i] = 1ll * (p - p/i) * inv[p%i] %p;
    for(int i = 1; i <= max(n, m); i++)
        fac[i] = 1ll * fac[i-1] * i % p,
        invfac[i] = 1ll * invfac[i-1] * inv[i] % p;
    int lim = min(n/s, m); ++lim;
    for(int i = 0; i < lim; i++){
        f[i] = 1ll * C(m, i) * fac[n] % p 
               * qpow(invfac[s], i) % p * invfac[n - i * s] % p
               * qpow(m-i, n - i*s) % p * fac[i] % p, 
        g[i] = (i & 1) ? p - invfac[i] : invfac[i];
    }
    // print(f, lim); print(g, lim);
    reverse(f, f+lim);
    polymul(f, g, lim, lim);
    reverse(f, f+lim);
    int ans = 0, w = 0;
    for(int i = 0; i < lim; i++){
        w = read();
        ans = (ans + 1ll * w * f[i] % p * invfac[i] % p) % p;
    }
    printf("%d\n", ans);
}
/*
5
1 6 3 4 9
*/