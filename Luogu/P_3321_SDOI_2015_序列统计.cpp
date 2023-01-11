#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#define poly vector<int>
using namespace std;
const int M = 4e4 + 5, p = 1004535809, mod = 1004535809;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int qpow(int a, int b, int p = mod) {
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
void cpy(int *f, int *g, int n = M){
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
void print(poly x) {
    for(int u : x) printf("%d ", u);
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
    if(type) mul(f, n, inv(n));
    cpy(g, f, n); clr(f, n);
}

void polymul(int *f, int *g, int len, int lim) {
    static int k1[M];
    int n = 1; for(; n <= len+len; n <<= 1);
    cpy(k1, g, n);
    NTT(f, n, 0); NTT(k1, n, 0);
    px(f, k1, n); NTT(f, n, 1);
    for(int i = lim; i < n; i++) (f[i%lim] += f[i]) %= mod; // !important
    clr(f + lim, n - lim); clr(k1, n);
}

int n, m, x, k;
int f[35][M], ans[M];
int main() {
    // freopen("test.out", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &x, &k);
    vector<int> fac;
    for(int i = 1; i < m-1; i++) if((m-1) % i == 0) fac.push_back(i);
    int g = 0;
    for(int i = 1; i < m; i++) {
        bool f = 1;
        for(auto x : fac) 
            if(qpow(i, x, m) == 1) {f = 0; break;}
        if(f) {g = i; break;}
    }
    // printf("g=%d\n", g);
    map<int, int> h;
    for(int i = 0; i < m-1; i++) h[qpow(g, i, m)] = i;
    --m; // !important
    x = h[x]; 
    for(int i = 1; i <= k; i++) {
        int c; scanf("%d", &c); if(c) ++f[0][h[c]];
    }
    // printf("\n");
    // print(f[0], m);
    for(int i = 1; i <= 31; i++) {
        cpy(f[i], f[i-1]);
        polymul(f[i], f[i], m, m);
        // printf("2^%d:", i);  print(f[i], m);
    }
    ans[0] = 1;
    for(int i = 31; i >= 0; i--) {
        if((n >> i) & 1) polymul(ans, f[i], m, m);
    }
    printf("%d\n", ans[x]);
}
/*
819644598 71 64 34
0 3 6 7 10 16 19 21 25 31 32 34 38 40 41 42 43 44 45 46 48 49 51 54 55 56 57 58 59 65 67 68 69 70
*/