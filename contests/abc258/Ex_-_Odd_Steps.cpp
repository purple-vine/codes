#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <initializer_list>
#define LL long long
using namespace std;
const int M = 100005, mod = 998244353;
struct matrix{
    int a[2][2], n, m;
    matrix() {}
    matrix(int n_, int m_) {n = n_; m = m_; memset(a, 0, sizeof(a));}
    matrix(int n_) {
        n = m = n_; memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) a[i][i] = 1;
    }
    matrix(initializer_list<initializer_list<int>> list){
        n = list.size(); int l = 0;
        for(auto i : list){
            int v = 0; m = i.size();
            for(auto j : i) a[l][v++] = j;
            ++l; 
        }
    }
    int* operator [] (int i){
        return a[i];
    }
    matrix operator * (const matrix &tmp) {
        matrix t(n, tmp.m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < t.m; j++)
                for(int k = 0; k < m; k++)
                    t[i][j] = (t[i][j] + 1ll * a[i][k] * tmp.a[k][j] % mod) % mod;
        return t;
    }
    void print(string s){
        cout << s << ":\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) printf("%d ", a[i][j]);
            printf("\n");
        }
    }
};
matrix qpow(matrix a, LL b){
    matrix ans(a.n); //ans.print("ans");
    for(; b; b >>= 1){
        if(b & 1) ans = ans * a;
        a = a * a;
    }
    return ans;
}
int n; LL s, a[M];
int main(){
    scanf("%d %lld", &n, &s);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    matrix dp({{1, 0}}); matrix t({{1, 1}, {1, 0}});
    // a[++n] = s;
    for(int i = 1; i <= n; i++){
        matrix x = dp * qpow(t, a[i] - a[i-1] - 1);
        // qpow(t, a[i]-a[i-1]-1).print("a[i]-a[i-1]-1");
        dp[0][1] = x[0][0]; dp[0][0] = x[0][1];
        // dp.print("dp");
    }
    dp = dp * qpow(t, s - a[n] - 1);
    printf("%d\n", dp[0][0]);
}