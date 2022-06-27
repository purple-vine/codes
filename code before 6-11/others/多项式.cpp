#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int M = 6000005, p = 998244353;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
namespace zag{
	int qpow(int a, int b){
		long long ans = 1ll;
		for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
		return ans;
	}
	int inv(int k) {return qpow(k, p - 2);}
	int add(int a, int b) {a += b; return a > p ? a-p : a;}
	int minus(int a, int b) {a -= b; return a < 0 ? a+p : a;}
}
const int G = 3, invG = zag::inv(G);
int tr[M];
vector<int> px(vector<int> a, vector<int> b){
	int n = min(a.size(), b.size()); vector<int> ans(n);
	for(int i = 0; i < n; i++)
		ans[i] = 1ll * a[i] * b[i] % p;
	return ans; 
} 
struct poly{
	vector<int> val;
	poly() {val.clear();}
	poly(int n) {for(int i = 0; i < n; i++) val.push_back(0);}
	poly(int *v, int n) {for(int i = 0; i < n; i++) val.push_back(v[i]);}
	poly(const std::initializer_list<int> &v) {for(auto i : v) val.push_back(i);}
	poly(vector<int> v) {val = v;}
	void setlen(int n) { //设置的是次数 
		while((int)val.size() <= n) val.push_back(0);
		while((int)val.size() > n + 1) val.pop_back();
	}
	void checklen(int n){
		while((int)val.size() <= n) val.push_back(0);
	}
	int siz() {return val.size() - 1;} //返回的是次数 
	int& operator [] (int i) {
//		if(i < (int)val.size()) return val[i];
//		while((int)val.size() <= i) val.push_back(0);
		return val[i];
	}
	poly operator * (int k) {
		poly g = *this;
		int n = val.size();
		for(int i = 0; i < n; i++) g[i] = 1ll * g[i] * k % p;
		return g;
	} 
	poly operator + (poly t) {
		int n0 = (int)val.size(), n = max(n0, t.siz()+1); poly ans(n-1); checklen(n-1);
		for(int i = 0; i < n; i++) ans[i] = (val[i] + t[i]) % p;
		return setlen(n0-1), ans;
	} 
	poly operator - (poly t) {
		int n0 = (int)val.size(), n = max(n0, t.siz()+1); poly ans(n-1); checklen(n-1);
		for(int i = 0; i < n; i++) ans[i] = (val[i] - t[i]) % p;
		return setlen(n0-1), ans;
	} 
	void print(){
		for(int j = 0, n = (int)val.size(); j < n; j++) printf("%d ", val[j]);
		printf("\n");
	}
	void print(char s[]){
		printf("%s:", s);
		for(int j = 0, n = (int)val.size(); j < n; j++) printf("%d ", val[j]);
		printf("\n");
	}
	vector<int> NTT(int L, int R){ //r-l需为2的幂次 
		vector<int> f; f.clear(); for(int i = L; i < R; i++) f.push_back(val[i]);
		int n = R - L;
		for(int i = 0; i < n; i++)
			tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
		for(int i = 0; i < n; i++) if(i < tr[i])
			swap(f[i], f[tr[i]]);
		for(int l = 2; l <= n; l <<= 1){
			int tg = zag::qpow(G, (p-1)/l);
			for(int s = 0; s < n; s += l){
				int buf = 1;
				for(int k = s; k < s + l/2; k++){
					int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
					f[k+l/2] = (f[k] - tt + p) % p; f[k] = (f[k] + tt) % p;
				}
			}
		} return f;
	}
	vector<int> NTT(){
		return NTT(0, val.size()); //val.size()即多项式次数+1需为2的幂次 
	}
	vector<int> NTT(int len){ //需保证len+1是2的幂次 
		checklen(len);
		return NTT(0, len+1);
	}
};
poly INTT(vector<int> val){ //需保证val.size()是2幂次 
	poly f(val); int n = val.size();
	for(int i = 0; i < n; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
	for(int i = 0; i < n; i++) if(i < tr[i])
		swap(f[i], f[tr[i]]);
	for(int l = 2; l <= n; l <<= 1){
		int tg = zag::qpow(invG, (p-1)/l);
		for(int s = 0; s < n; s += l){
			int buf = 1;
			for(int k = s; k < s + l/2; k++){
				int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
				f[k+l/2] = (f[k] - tt + p) % p; f[k] = (f[k] + tt) % p;
			}
		}
	} f = f * zag::inv(n); return f;
}
poly operator * (poly f, poly g){
	int n = f.siz(), m = g.siz();
	int len; for(len = 1; len <= n + m; len <<= 1);
	f.setlen(len-1); g.setlen(len-1);
	vector<int> a = f.NTT(), b = g.NTT();
	for(int i = 0; i < len; i++) a[i] = 1ll * a[i] * b[i] % p;
	f = INTT(a); f.setlen(n+m);
	return f;
}
poly inv(poly k){
	// f(x)=2*r(x)-r(x)^2*F(x)(mod x^n)
	//r:前n/2位 f:前n位 
	poly f, r; int n = 1, n0 = k.siz(); for(; n <= (int)k.siz(); n <<= 1);
	r[0] = zag::inv(k[0]); k.setlen(n-1);
	for(int len = 2; len <= n; len <<= 1){
		poly two({2});
		f = r * (two - r * k);
		f.setlen(len-1);
		r = f; 
	}
	return f.setlen(k.siz()), f;
}
int n, m; poly f;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) f[i] = (read() + p) % p;
	f = inv(f); f.print();
}
/*
5
1 6 3 4 9
*/
