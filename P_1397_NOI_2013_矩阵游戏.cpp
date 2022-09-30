#include <cstring>
#include <cstdio>
#include <initializer_list>
using namespace std;
const int mod = 1000000007, M = 105;
struct matrix{
    int a[M][M], n, m;
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
    void print(){
        // printf("%s:\n", s);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) printf("%d ", a[i][j]);
            printf("\n");
        }
    }
};
matrix qpow(matrix t, long long k){
    matrix ans(t.n);
    for(; k; k >>= 1){
        if(k & 1) ans = ans * t;
        t = t * t;
    }
    return ans;
}
matrix a, b; int n; long long k;
int main(){
    
    a.n = a.m = n;
    qpow(a, k).print();
    // b.print();
}