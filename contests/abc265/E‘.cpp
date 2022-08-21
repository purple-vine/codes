#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
// #define int long long
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma GCC target("avx", "sse2")
#define lowbit(x) (x & -x)
using namespace std;
const int M = 505, mod = 998244353;
int fac[M], invfac[M];
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
void mins(int &a, int b) {a -= b; if(a < 0) a += mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
void pre(int n = 500){
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * inv(i) % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}
int n, m, x[M], y[M], a, b, c, d, e, f;
set<pair<int, int> > t;
int tot, px[M*M], py[M*M], pz[M*M], ps[M*M], cnt;
int calc(int x, int y, int z){
    return 1ll * C(x+y+z, x) * C(y+z, y) % mod;
}
signed main(){
    scanf("%d %d %d %d %d %d %d %d", &n, &m, &a, &b, &c, &d, &e, &f);
    pre(500);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &x[i], &y[i]);
        t.insert(make_pair(x[i], y[i]));
    }
    for(int s = 1; s <= n; s++){ // i + j + k
        for(int i = 0; i <= s; i++){
            for(int j = 0; j <= s-i; j++){
                int k = s-i-j; long long xx = 1ll * i*a + 1ll * j*c + 1ll * k*e, yy = 1ll * i*b + 1ll * j*d + 1ll * k*f;
                int ans = calc(i, j, k);
                for(int o = cnt; o >= 1; o--){
                    if(px[o] <= i && py[o] <= j && pz[o] <= k){
                        mins(ans, 1ll * ps[o] * calc(i-px[o], j-py[o], k-pz[o]) % mod);
                    }
                }
                if(t.find(make_pair(xx, yy)) == t.end()){
                    if(i + j + k == n) add(tot, ans); 
                } else {
                    ++cnt; px[cnt] = i; py[cnt] = j; pz[cnt] = k; ps[cnt] = ans;
                }
            }
        }
    }
    printf("%d\n", tot);
    return 0;
}