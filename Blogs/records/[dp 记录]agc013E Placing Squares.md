什么组合意义都不是给人看的，来点人能想到的题解

题意：

> $\displaystyle f_i = \begin{cases} 1 & i=0\\ \sum\limits_{j=1}^i f_j (i-j)^2 & i \not\in S \\ 0 & i \in S \end{cases}$
> 
> 给定 $S,|S| \leq 10^5$，求 $f(n),n\leq 10^9$

注意到这里的信息转移是很固定的，即是说，确定一个起始值和一个转移方式后，每个 $f_j$ 其实是比较容易确认的，也是容易用数学方法表示的。

若能找到类似矩乘之类能快速递推的式子，即可像 abc258ex 那样，整段递推，边界手动转移，做到 $O(m \log n)$。

来化一化式子。

$$
\begin{aligned}
f_j &= \sum_{j\leq i} f_j (i-j)^2 \\
    &= \sum_{j < i} f_j(i-j-1)^2 + \sum_{j < i} f_j (i-j-1) + \sum_{j \leq i} f_j \\
\end{aligned}
$$

后面呈现了降次，很好！

令 

$$\begin{cases}s_{2,i}=\sum\limits_{j \leq i} f_j (i-j)^2 \\ s1_i=\sum\limits_{j \leq i} f_j(i-j) \\ s0_i=\sum\limits_{j \leq i} f_j \end{cases}$$

则当 $i$ 不为标记点

$$
\begin{cases}
s_{0,i} =  s_{0,{i-1}} + s_{2,{i-1}} \\
s_{1,i} =  s_{1,{i-1}} + s_{2,{i-1}}+s_{0,{i-1}} \\
s_{2,i} = s_{2,i-1} + 2s_{1,i}+ 2s_{0,{i-1}}
\end{cases}
$$

否则

$$
\begin{cases}
s_{0,i} = s_{0,i-1} \\
s_{1,i} = s_{1,i-1} + s_{0,i-1} \\
s_{2,i} = s_{2,i-1} + 2s_{1,i-1} + s_{0,i-1}
\end{cases}
$$

```cpp
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <initializer_list>
#define LL long long
using namespace std;
const int M = 100005, mod = 1000000007;
struct matrix{
    int a[3][3], n, m;
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
    scanf("%lld %d", &s, &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    matrix dp(3); matrix t({{1, 1, 1}, {0, 1, 2}, {1, 1, 2}});
    matrix t2({{1, 1, 1}, {0, 1, 2}, {0, 0, 1}}); 
    a[0] = -1;
    for(int i = 1; i <= n; i++){
        matrix x = dp * qpow(t, a[i] - a[i-1] - 1);
        dp = x * t2;
    }
    dp = dp * qpow(t, s - a[n] - 1);
    printf("%d\n", dp[0][2]);
}
```