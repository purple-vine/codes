#include <cstdio>
#include <vector>
using namespace std;
const int M = 5e6 + 5;
int m = 5e6;
const int mod = 998244353;
struct modint {
    int x;
    modint(int o = 0) {x = o;}
    modint &operator = (int o) {return x = o, *this;}
    modint &operator += (modint o) {return x = x+o.x >= mod ? x+o.x-mod : x+o.x, *this;}
    modint &operator -= (modint o) {return x = x-o.x < 0 ? x-o.x+mod : x-o.x, *this;}
    modint &operator *= (modint o) {return x = 1ll*x*o.x%mod, *this;}
    modint &operator ^= (int b) {
        modint a = *this, c = 1;
        for(; b; b >>= 1, a *= a) if(b & 1) c *= a;
        return x=c.x, *this;
    }
    modint &operator /= (modint o) {return *this *= o ^= mod-2;}
    friend modint operator + (modint a, modint b) {return a += b;}
    friend modint operator - (modint a, modint b) {return a -= b;}
    friend modint operator * (modint a, modint b) {return a *= b;}
    friend modint operator / (modint a, modint b) {return a /= b;}
    friend modint operator ^(modint a,int b) {return a ^= b;}
    friend bool operator == (modint a, int b) {return a.x == b;}
    friend bool operator != (modint a, int b) {return a.x != b;}
    bool operator ! () {return !x;}
    modint operator - () {return x ? mod-x : 0;}
    bool operator < (const modint &b) const {return x < b.x;}
};
inline modint qpow(modint x, int y) {return x ^ y;}

vector<modint> fac, ifac, iv;
inline void initC(int n) {
    if(iv.empty()) fac = ifac = iv = vector<modint>(2,1);
    int m = iv.size(); ++n;
    if(m >= n) return;
    iv.resize(n), fac.resize(n), ifac.resize(n);
    for(int i = m; i <= n; i++) {
        iv[i] = iv[mod%i] * (mod - mod/i);
        fac[i] = fac[i-1] * i, ifac[i] = ifac[i-1] * iv[i];
    }
}
inline modint C(int n, int m) {
    if(m<0 || n<m) return 0;
    return initC(n), fac[n] * ifac[m] * ifac[n-m];
}
inline modint sign(int n) {return (n&1) ? (mod-1) : (1);}
int main() {
    vector<modint> D(M);
    initC(m);
    D[0] = 1; D[1] = 0;
    for(int i = 1; i <= m; i++) 
        D[i+1] = D[i] * 4 * i * (i+1) + D[i-1] * 8 * (i+1) * i * i;
    int T; scanf("%d", &T);
    while(T--) {
        int n, k; scanf("%d %d", &n, &k);
        printf("%d\n", C(n, k) * C(n, k) * fac[k] * qpow(2, k) * D[n-k]);
    }
}