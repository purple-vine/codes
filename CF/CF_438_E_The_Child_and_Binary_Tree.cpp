#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int M = 2000005, p = 998244353;
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
    if(type) mul(f, n, inv(n));
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

void polyinv(int *k, int len){
    static int v[M], r[M], tp[M];
	// f(x) = 2*r(x) - r(x)^2 * F(x) (mod x^n)
    //      = r(x) * (2 - r(x) * F(x))
    //f_{n}(x) = 2 * f_{n-1}(x) - f_{n-1}(x) ^ 2 * F(x)
	//r:前n/2位 f:前n位 
	int n = 1; for(; n <= len; n <<= 1);
    v[0] = inv(k[0]);
    for(int l = 2; l <= n; l <<= 1){
        cpy(r, v, l/2); mul(r, l/2, 2);
        NTT(v, l << 1, 0); px(v, v, l << 1);
        // 下面拷 l 位就够了，不要拷 l<<1 位
        cpy(tp, k, l); NTT(tp, l << 1, 0); px(v, tp, l << 1);
        NTT(v, l << 1, 1); clr(v + l, l);
        mins(v, r, v, l);
    }
    cpy(k, v, n); clr(v, n<<1); clr(r, n<<1); clr(tp, n<<1);
}

void polyln(int *g, int len){
    static int l[M];
    cpy(l, g, len);
    qiudao(l, len); polyinv(g, len);
    polymul(g, l, len, len); jifen(g, len-1);
    clr(l, len);
}

void polysqrt(int *g, int len){
    static int s[M], s2[M];
    // f_{n}(x) = (F(x) + f_{n-1}(x) ^ 2) / (2 * f_{n-1}(x))
    int n = 1; for(; n <= len; n <<= 1) ;
    s[0] = 1;
    for(int l = 2; l <= n; l <<= 1){
        cpy(s2, s, l); NTT(s2, l, 0); px(s2, s2, l);
        NTT(s2, l, 1); add(s2, s2, g, l);
        mul(s, l, 2); polyinv(s, l); 
        polymul(s, s2, l, l);
    }
    cpy(g, s, len); clr(s, n); clr(s2, n);
}


void polyexp(int *g, int len){
    static int x1[M], x2[M], x3[M];
    // f_t(x) = f_{t-1} - (ln(f_{t-1}) - F(x)) * f_{t-1}
    //        = (1 - ln(f_{t-1}) + F(x)) * f_{t-1}           
    int n = 1; for(; n <= len; n <<= 1) ;
    x1[0] = 1;
    for(int l = 2; l <= n; l <<= 1){
        cpy(x2, x1, l); polyln(x2, l); mins(x2, x2, g, l);
        cpy(x3, x1, l);
        polymul(x2, x3, l, l); mins(x1, x1, x2, l);
    }
    cpy(g, x1, len); clr(x1, n); clr(x2, n); clr(x3, n);
}
int n, m;
int f[M], g[M], fac[M], invfac[M], c[M], mn;
int main(){
    /*
    F(x) = 2 / (1 + sqrt(1 + 4 * G(x)))
    */
	scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]), f[c[i]] = -1;
        mn = max(mn, c[i]);
    }
    mn = max(m+1, mn+1);
    mul(f, mn, 4); ++f[0];
    polysqrt(f, mn); ++f[0];
    polyinv(f, mn); mul(f, mn, 2);
    for(int i = 1; i <= m; i++) printf("%d\n", f[i]);
}
/*
5
1 6 3 4 9
*/