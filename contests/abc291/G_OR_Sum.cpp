#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#define LL long long
#define poly vector<int>
using namespace std;
const int M = 6e6 + 20, p = 998244353, mod = 998244353;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int qpow(int a, int b){
    if(b < 0) return qpow(qpow(a, p-2), b);
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

int n, m, x[M], y[M], f[M], g[M], a[M], b[M], ans[M]; 
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for(int t = 0; t < 9; t++) {
    for(int i = 1; i <= n; i++) x[i] = 1 - ((a[i] >> t) & 1);
    for(int i = 1; i <= n; i++) y[i] = 1 - ((b[i] >> t) & 1);
    for(int i = 0; i < n; i++) f[i] = x[n - i];
    for(int i = 0; i < n; i++) g[i+n] = g[i] = y[i+1];
    polymul(f, g, 2*n, 2*n);
    // print(f, 2*n);
    for(int i = n; i < 2*n; i++) ans[i - n + 1] += ((n - f[i]) << t);
    clr(f, 2*n); clr(g, 2*n);
  }
  int res = 0;
  for(int i = 1; i <= n; i++) res = max(res, ans[i]);
  printf("%d\n", res); 
}