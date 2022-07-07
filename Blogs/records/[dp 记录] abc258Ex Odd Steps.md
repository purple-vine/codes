题意转化：给定 $n$ 个整数和 $S$，选一个从小到大排序的数列，$0$ 和 $S$ 必选，使相邻两数奇偶性不同，给出的 $n$ 个数不能选。求方案数。
$S \leq 10^{18},n \leq 10^5$

看着非常 $dp$，但是 $S$ 极大，于是就是矩乘优化 $dp$ 了。

令 $dp_i$ 表示所选数均 $\leq i$ 的情况，但又需要知道奇偶性以转移，于是 $dp_{i,0/1}$ 表示所选数最大为 $i$，所选最大数膜 $2$ 余数为 $i+0/1$ 的情况。此时，我们要求的是 $dp_{i-1,0}$，因为最后还要选 $S$ 出来。这样转化，我们看着丢失了直接获得答案的能力，但与此相比，我们可以以 $O(1)$ 而非 $O(n)$ 的代价递推，并仍能通过 $O(1)$ 的代价获得答案。

$$  
\left\{  
\begin{array}{ll}  
dp_{i,0} & \gets & dp_{i-1,1} + dp_{i-1, 0} \cdot [\text{if i could be chosen}] \\  
dp_{i,1} & \gets & dp_{i-1,0}
\end{array}  
\right.  
$$  

将 $n$ 个 $a_i$ 作为分界，两个 $a_i$ 之间用矩乘转移，否则朴素转移，即得。

```cpp
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
    matrix ans(a.n);
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
    for(int i = 1; i <= n; i++){
        matrix x = dp * qpow(t, a[i] - a[i-1] - 1);
        dp[0][1] = x[0][0]; dp[0][0] = x[0][1];
    }
    dp = dp * qpow(t, s - a[n] - 1);
    printf("%d\n", dp[0][0]);
}
```