#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring> 
#ifndef ONLINE_JUDGE
#define debug(f, n) for(int i = 0; i < n; i++) printf("%lld ", f[i]); printf("\n\n");
#else
#define debug(f, n)
#endif 
#define p 998244353
using namespace std;
const int M = 6000005;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
namespace zag{
	#ifndef p
	int qpow(int a, int b, int p){
		long long ans = 1ll;
		for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
		return ans;
	}
	int inv(int k, int p) {return qpow(k, p - 2);}
	#else
	int qpow(int a, int b){
		long long ans = 1ll;
		for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
		return ans;
	}
	int inv(int k) {return qpow(k, p - 2);}
	#endif
	int add(int a, int b) {a += b; return a > p ? a-p : a;}
	int minus(int a, int b) {a -= b; return a < 0 ? a+p : a;}
}
const int G = 3, invG = zag::inv(G);
int tr[M];
void poly_pre(int n){
	for(int i = 0; i < n; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
struct poly{
	vector<int> val;
	poly() {val.clear();}
	poly(int *v, int n) {for(int i = 0; i < n; i++) val.push_back(v[i]);}
	poly(vector<int> &v) {val = v;}
	void setlen(int n) {while((int)val.size() < n) val.push_back(0);}
	int siz() {return val.size();}
	int& operator [] (int i) {
		if(i < (int)val.size()) return val[i];
		while((int)val.size() <= i) val.push_back(0);
		return val[i];
	}
	void print(){
		int i = val.size() - 1; while(val[i] == 0) i--;
		for(int j = 0; j <= i; j++) printf("%lld ", val[j]);
		printf("\n");
	}
	vector<int> NTT(){
		vector<int> f = val; int n = val.size();
		for(int i = 0; i < n; i++) if(i < tr[i])
			swap(f[i], f[tr[i]]);
		for(int l = 2; l <= n; l <<= 1){
			int tg = zag::qpow(G, (p-1)/l); //模l的原根 
			for(int s = 0; s < n; s += l){
				int buf = 1;
				for(int k = s; k < s + l/2; k++){
					int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
					f[k+l/2] = zag::minus(f[k], tt); f[k] = zag::add(f[k], tt);
				}
			}
		} return f;
	}
};
poly INTT(vector<int> val){
	vector<int> f(val); int n = val.size();
	for(int i = 0; i < n; i++) if(i < tr[i])
		swap(f[i], f[tr[i]]);
//	debug(f, n);
	for(int l = 2; l <= n; l <<= 1){
		int tg = zag::qpow(invG, (p-1)/l); //模l的原根 
		for(int s = 0; s < n; s += l){
			int buf = 1;
			for(int k = s; k < s + l/2; k++){
				int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
				f[k+l/2] = zag::minus(f[k], tt); f[k] = zag::add(f[k], tt);
			}
		}
//		debug(f, n);
	} return f;
}
poly f, g; int n, m, len; vector<int> a, b, c; char s1[M], s2[M];
int main(){
	scanf("%s %s", &s1, &s2); n = strlen(s1) - 1; m = strlen(s2) - 1;
	for(int i = 0; i <= n; i++) f[i] = s1[i] - '0';
	for(int i = 0; i <= m; i++) g[i] = s2[i] - '0';
	for(len = 1; len <= n + m; len <<= 1);
	f.setlen(len); g.setlen(len);
	for(int i = 0; i < len; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? len >> 1 : 0);
	a = f.NTT(); b = g.NTT();
	for(int i = 0; i < len; i++) a[i] = 1ll * a[i] * b[i] % p;
	f = INTT(a); int invn = zag::inv(len);
	for(int i = n+m; i >= 0; i--)
		f[i] = 1ll * f[i] * invn % p;
	for(int i = n+m; i >= 1; i--)
		f[i-1] += f[i]/10, f[i] %= 10;
	for(int i = 0; i <= n+m; i++) printf("%d", f[i]);
}
/*
5 5
1 7 4 0 9 4 
8 8 2 4 5 5 
*/
