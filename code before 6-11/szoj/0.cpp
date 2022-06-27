#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(a, len) for(int i = 0; i < len; i++) printf("%d ", a[i]);\
	printf("\n");
using namespace std;
const int M = 6000005, p = 998244353;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
namespace missa{
	int qpow(int a, int b){
		int ans = 1;
		for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}
		return ans;
	}
	int inv(int k) {return qpow(k, p - 2);}
	int add(int a, int b) {a += b; return a > p ? a-p : a;}
	int minus(int a, int b) {a -= b; return a < 0 ? a+p : a;}
}
const int G = 3, invG = missa::inv(G);
int tr[M];
void poly_pre(int n){
	for(int i = 0; i < n; i++)
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
struct poly{
	vector<int> val;
	poly() {val.clear();}
	poly(int k) {val.clear(); val[0] = k;}
	poly(int *v, int n) {for(int i = 0; i < n; i++) val.push_back(v[i]);}
	poly(vector<int> &v) {val = v;}
	void setlen(int n) { //设置次数为n
		while((int)val.size() <= n) val.push_back(0);
		while((int)val.size() > n + 1) val.pop_back();
	}
	int siz() {return val.size() - 1;}
	int& operator [] (int i) {
		if(i < (int)val.size()) return val[i];
		while((int)val.size() <= i) val.push_back(0);
		return val[i];
	}
	void print(){
		for(int j = 0; j < (int)val.size(); j++) printf("%d ", val[j]);
		printf("\n");
	}
	vector<int> NTT(){
		vector<int> f = val; int n = val.size();
		for(int i = 0; i < n; i++) if(i < tr[i])
			swap(f[i], f[tr[i]]);
		for(int l = 2; l <= n; l <<= 1){
			int tg = missa::qpow(G, (p-1)/l); //模l的原根 
			for(int s = 0; s < n; s += l){
				int buf = 1;
				for(int k = s; k < s + l/2; k++){
					int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
					f[k+l/2] = missa::minus(f[k], tt); f[k] = missa::add(f[k], tt);
				}
			}
		} return f;
	}
};
poly INTT(vector<int> val){
	poly f(val); int n = val.size();
	for(int i = 0; i < n; i++) if(i < tr[i])
		swap(f[i], f[tr[i]]);
	for(int l = 2; l <= n; l <<= 1){
		int tg = missa::qpow(invG, (p-1)/l); 
		for(int s = 0; s < n; s += l){
			int buf = 1;
			for(int k = s; k < s + l/2; k++){
				int tt = 1ll * buf * f[k+l/2] % p; buf = 1ll * buf * tg % p;
				f[k+l/2] = missa::minus(f[k], tt); f[k] = missa::add(f[k], tt);
			}
		}
	} 
	int invn = missa::inv(n);
	for(int i = 0; i < n; i++) f[i] = 1ll * f[i] * invn % p;	
	return f;
}
int n, k, d[M], len, ans; poly f, g;
int main(){
	scanf("%d %d", &n, &k); n /= 2;
	for(len = 1; len <= n*9; len <<= 1);
	poly_pre(len); f.setlen(len-1);
	for(int i = 1; i <= k; i++)
		scanf("%d", &d[i]), f[d[i]] = 1;
	vector<int> a = f.NTT();
	for(int i = 0; i <= len; i++){
		a[i] = missa::qpow(a[i], n);
	}
	f = INTT(a); 
	for(int i = 0; i <= n*9; i++){
		ans = (ans + 1ll * f[i] * f[i] % p) % p;
//		printf("f[%d] = %d\n", i, f[i]);
	}
	printf("%d\n", ans);
//	printf("this is the end\n");
	return 0;
}
/*
4 2
1 8
*/
