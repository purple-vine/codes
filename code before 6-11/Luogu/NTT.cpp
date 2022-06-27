#include <cstdio>
#include <cmath>
#include <vector>
#define p 998244353
#ifndef ONLINE_JUDGE
#define debug(f) for(int i = 0; i < len; i++) printf("%d ", f[i]); printf("\n");
#endif 
using namespace std;
const int M = 6000005;
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
int minus(int a, int b) {a -= b; return a < 0 ? a+p : a;}
const int G = 3, invG = inv(G);
int tr[M], n, m, len, f[M], g[M];
void NTT(int *f, bool op){
	int n = len;
	for(int i = 0; i < n; i++) if(i < tr[i])
		swap(f[i], f[tr[i]]);
	debug(f);
	for(int l = 2; l <= n; l <<= 1){
		int mid = l >> 1;
		int tg = qpow(op ? G : invG, (p-1)/l); //模l的原根 
		for(int s = 0; s < n; s += l){
			int buf = 1;
			for(int k = s; k < s + mid; k++){
				int tt = 1ll * buf * f[k+mid] % p; buf = 1ll * buf * tg % p;
				f[k+mid] = minus(f[k], tt); f[k] = add(f[k], tt);
			}
		}
	}
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i++) f[i] = (read() + p) % p;
	for(int i = 0; i <= m; i++) g[i] = (read() + p) % p;
	for(len = 1; len <= n + m; len <<= 1);
	for(int i = 0; i < len; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? len >> 1 : 0);
	NTT(f, 1); NTT(g, 1);
	debug(f); debug(g);
	for(int i = 0; i < len; i++) f[i] = 1ll * f[i] * g[i] % p;
	NTT(f, 0); int invn = inv(n+m+1);
	for(int i = 0; i <= n + m; i++)
		printf("%d ", 1ll * f[i] * invn % p);
}
