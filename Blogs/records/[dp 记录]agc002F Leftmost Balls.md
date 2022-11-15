会考时就在做的题，到现在才过（

题意：$n$ 色球每色 $k$ 个排成一排，染白最左边球，求方案数膜 $10^9+7$。$n,k \leq 2000$。

看到题面，一眼 dp。看到数据范围，也很 $O(n^2)$ dp。

但是染白的条件不好直接处理。现在应该转化条件、或转化所求，让 dp 的状态尽可能少。

从整体考虑看来很难，不如直接从白球的视角看问题。

染白是最左边球，所以容易想到任意一段前缀中白球个数不小于彩色球颜色种类数。

可以设计出如下 dp：$dp_{i,j}$ 代表已有 $i$ 白球，$j$ 种颜色时的方案数。

学校中却觉得需要知道已有球的总数，加了一维表示已有球数，强行把转移变成了 $O(n^3)$。

（一个错误的校时思路）试试从后往前 dp，这样就可以一次性把所有同色球放进去，复杂度还挺好看，但是无法钦定球的顺序，也就是完全没法做。

（家中看了题解）这时回到开始思路，如果能一次性放入所有同色球，则复杂度是漂亮的 $O(n^2)$。

不妨把所有贡献放到第一个出现的该色球上，这样就可以批量转移其余 $k-2$ 球了。

还是使用原 dp 状态，现在考虑转移。

放入一个白球时是显然的，

$$dp_{i+1,j} \gets dp_{i,j}$$

放入一种彩球时，新彩球本身有 $n-j$ 种选法，此时剩余 $n - i - j(k-1)$ 个空位，最左的一个给第一个新彩球，剩余 $k-2$ 球在剩余空位中随意放，

$$
dp_{i,j+1} \gets dp_{i,j} \cdot (n-j) \cdot \binom{nk-i-j(k-1)-1}{k-2}
$$

组合数预处理后可以直接递推，复杂度 $O(n^2)$。

其实感觉整体思路比较平凡，不至于评到铜牌更不至于评黑……远古题的遗留罢。

```cpp
#include <cstdio>
using namespace std;
const int M = 4e6 + 5, mod = 1e9 + 7, N = 2005;
int qpow(int a, int b){
    long long ans = 1ll;
    for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
    return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
int fact(int x) {int ans = 1; for(int i = 1; i <= x; i++) ans = 1ll * ans * i % mod; return ans;}
int fac[M], invfac[M], invn[M];
void pre(int n = M - 2){
    fac[0] = invfac[0] = fac[1] = invfac[1] = invn[1] = 1;
    for(int i = 2; i <= n; i++)
        invn[i] = 1ll * (mod - mod/i) * invn[mod%i] % mod,
        fac[i] = 1ll * fac[i-1] * i % mod,
        invfac[i] = 1ll * invfac[i-1] * invn[i] % mod;
}
int C(int n, int m) {return m > n ? 0 : 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;}

int dp[N][N];
int main(){
    int n, k; scanf("%d %d", &n, &k);
    pre(n * k);
    if(k == 1) {puts("1"); return 0;}
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            add(dp[i+1][j], dp[i][j]);
            if(j+1 <= i)
                add(dp[i][j+1], 1ll * dp[i][j] * (n-j) % mod * C(n*k - i - j*(k-1) - 1, k-2) % mod);
        }
    }
    printf("%d\n", dp[n][n]);
}
```