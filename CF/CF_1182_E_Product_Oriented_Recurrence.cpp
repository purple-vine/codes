#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int mod = 1000000007, phi = 1000000006;
long long n; int f1, f2, f3, c;
struct matrix{
    int a[3][3], n, m;
    matrix(int n_, int m_) {n = n_; m = m_; memset(a, 0, sizeof(a));}
    matrix(int n_) {
        n = m = n_; memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) a[i][i] = 1;
    }
    int* operator [] (int i){
        return a[i];
    }
    matrix operator * (const matrix &tmp) {
        matrix t(n, tmp.m);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    t[i][j] = (t[i][j] + 1ll * a[i][k] * tmp.a[k][j] % phi) % phi;
        return t;
    }
    matrix operator ^ (long long tmp) const{
        matrix ans(3), t = *this;
        for(; tmp; tmp >>= 1){
            if(tmp & 1) ans = ans * t;
            t = t * t;
        }
        return ans;
    }
    void print(string s){
        cout << s << ":\n";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d ", a[i][j]);
            } printf("\n");
        } printf("\n");
    }
    bool operator == (const matrix &tmp) const{
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) if(a[i][j] != tmp.a[i][j]) return 0;
        return 1;
    }
};
int qpow(int a, long long b){
    int ans = 1;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = a * a % mod;}
    return ans;
}
int inv(int a) {return qpow(a, mod-2);}
signed main(){
    scanf("%lld %lld %lld %lld %lld", &n, &f1, &f2, &f3, &c);
    int h0 = 1ll * f3 * qpow(c, 3) % mod,
        h1 = 1ll * f2 * qpow(c, 2) % mod,
        h2 = 1ll * f1 * qpow(c, 1) % mod;
    matrix tran(3, 3);
    tran[0][0] = tran[0][1] = tran[1][0] = tran[1][2] = tran[2][0] = 1;
    tran = tran ^ (n-1);
    int ans = 1ll * qpow(h0, tran[0][2]) * qpow(h1, tran[1][2]) % mod
                  * qpow(h2, tran[2][2]) % mod;
    ans = 1ll * ans * qpow(inv(c), n % phi) % mod;
    printf("%lld\n", ans);
}