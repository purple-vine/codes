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
const int G = 3;
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
};
poly INTT(vector<int> val){
	printf("val in INTT:"); //debug(val, val.size()-1);
	printf(" back\n");
}
int n, k, d[M], len, ans; poly f, g;
int main(){
	scanf("%d %d", &n, &k); n /= 2;
	for(len = 1; len <= n*9; len <<= 1);
	poly_pre(len); f.setlen(len-1);
	for(int i = 1; i <= k; i++)
		scanf("%d", &d[i]), f[d[i]] = 1;
	vector<int> a(len+100);// = f.NTT();
//	for(int i = 0; i <= len; i++){
//		a[i] = missa::qpow(a[i], n/2);
//	}
	printf("a after qpow:"); debug(a, len);
	printf("in"); INTT(a); 
	printf("out");
	for(int i = 0; i <= n/2; i++){
		ans = (ans + 1ll * f[i] * f[i] % p) % p;
	}
	printf("%d\n", ans);
	printf("this is the end\n");
	return 0;
}
/*
4 2
1 8
*/
