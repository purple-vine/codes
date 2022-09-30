#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define int long long
#define LL long long
using namespace std;
int mod, a, c, x, n, g;
LL add(LL a, LL b) {a += b; return a > mod ? a-mod : a;}
inline LL mul(LL a, LL b){
    LL ans = 0;
    for(; b; b >>= 1){
        // printf("in nul as=%lld b=%lld\n", ans, b);
        if(b & 1) ans = add(ans, a);
        a = add(a, a);
    }
    return ans;
}
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
                    t[i][j] = add(t[i][j], mul(a[i][k], tmp.a[k][j]));
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
signed main(){
    scanf("%lld %lld %lld %lld %lld %lld", &mod, &a, &c, &x, &n, &g);
    a %= mod; c %= mod; x %= mod;
    matrix s(1, 2); s[0][0] = x; s[0][1] = c;
    matrix tran(2, 2); tran[0][0] = a; tran[1][0] = tran[1][1] = 1;
    tran = tran ^ n; s = s * tran;
    printf("%d\n", s[0][0] % g);
}