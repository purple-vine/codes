  
  
第一道自己做出来的 2000\-2400 的 AT 题（顺便建议此题评绿），~~还是做核酸时想到的，与本题另一题解不同~~，所以来发个题解。  
  
如果正着做，需要维护两条边的信息，较为麻烦。所以正难则反。考虑到值域较小，我们可以从值域下手。  
  
记所有数字的总和为 $S$，考虑到当且仅当有一边的长度大于等于另两边之和，即有一边的长度大于等于 $\lceil \dfrac{S}{2} \rceil$ 时，不能组成三角形，我们可以**枚举这个最长边的长度和这条最长边由几个数字拼成**。不妨让这条边染成红色，这时剩下的数字可以随便选择一个没有用过的颜色。  
  
当 $S$ 是奇数时，这个三角形最多有一条边 $\geq \lceil \dfrac{S}{2} \rceil$，此时每个不符合要求的三角形仅会在统计最长边时被统计一次。但是，当 $S$ 为偶数时，三边为 $\left\{\dfrac{S}{2},\dfrac{S}{2},0 \right\}$ 的三角形会被统计两次。解决方案是统计会导致这种情况的方案数，在最后统计出来不合法的方案数中去除掉这么多。  
  
设 $f_{i,j}$ 表示用 $i$ 个数字拼成 $j$ 的方案数。转移方程：$f_{j+1,k+a_i} \gets f_{j,k}$，因为用 $f_j$ 更新 $f_{j+1}$，我们需要从大到小枚举 $f_j$，不让一个决策被多次使用。  
  
找到一个 $f_{i,j}$，其中 $j \geq \lceil \dfrac{S}{2} \rceil$ 后，还有 $n-i$ 个数字可以被染上剩下的两个颜色中的一个，也就是一共找到了 $f_{i,j} \cdot 2^{n-i}$ 个不合法的方案。  
```cpp  
#include <cstdio>  
using namespace std;  
const int M = 305, N = 90005, mod = 998244353;  
int f[M][N], n, a[M], S, t[M], ans, ans1;  
int add(int a, int b) {return (a += b) > mod ? a-mod : a;}  
int qpow(int a, int b, int p){  
    long long ans = 1ll;  
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % p; a = 1ll * a * a % p;}  
    return ans;  
}  
signed main(){  
    scanf("%lld", &n);  
    t[0] = 1;  
    for(int i = 1; i <= n; i++) t[i] = add(t[i-1], t[i-1]);  
    for(int i = 1; i <= n; i++)  
        scanf("%lld", &a[i]), S += a[i];  
    f[0][0] = 1;  
    for(int i = 1; i <= n; i++)  
        for(int j = i; j >= 0; j--)  
            for(int k = 0; k <= S; k++)  
                f[j+1][k+a[i]] = add(f[j+1][k+a[i]], f[j][k]);  
    int minn = (S >> 1) + (S & 1);  
    for(int i = 0; i <= n; i++){  
        for(int j = minn; j <= S; j++){  
            ans = add(ans, 1ll * f[i][j] * t[n-i] % mod);  
        }  
        if(S % 2 == 0) ans1 = add(ans1, f[i][S >> 1]);  
    }  
    ans -= ans1;  
    printf("%lld\n", (qpow(3, n, mod) - 1ll * ans * 3 % mod + mod) % mod);  
    //3^n 是全部，ans还要*3是因为假定了最长边涂红色。  
}   
```  
<br>  
  

-----
分类：题解