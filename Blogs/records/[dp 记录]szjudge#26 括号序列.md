dp 部分平凡，但是后面找最值是值得深思的。

题意：给出两个由左右括号形成的字符串，求在长度最小的基础上字典序最小的合法括号序列，使给出字符串均为其子串。$|s|,|t| \leq 300$。

首先看着非常 dp。因为有子序列，需要把匹配几位塞进 dp 状态。接着因为括号序列要合法，要把当前几个未闭合左括号塞进 dp 状态中。前两维相同时第三维间还有转换，那就把长度也塞进去。信息好多啊，甚至只需要开成 `bool` 数组。然后好像就不行了。$O(n^4)$ 跑 $300$，怎么可能。

$dp_{i,j,k,l}$：与 $s$ 匹配 $i$ 位，$t$ 匹配 $j$ 位，剩余 $k$ 个未闭合左括号，当前长度为 $l$，是否可行。

转移：

$$
\begin{aligned}
dp_{i+[s_i=')'],j+[s_j=')'],k-1,l+1} &\gets& dp_{i,j,k,l} \\
dp_{i+[s_i='('],j+[s_j='('],k+1,l+1} &\gets& dp_{i,j,k,l}
\end{aligned}
$$

赛时就想到这里了。不想写，不想调，GG。

究其原因，是 dp 设的东西太多了。好像只要最小化长度啊，为什么要把长度的所有情况的是否合法都塞进去，存个最小长度不就行了。

把第四位压掉 dp 改成 `int` 类型，前三维表意不变，然后会发现转移混乱。原来有 $l$ 一定增大的条件，可以按 $l$ 枚举，现在好像没什么好的顺序啊。

那就不要用当前状态更新未来状态的方法了，枚举之前状态更新当前状态。

$$
\begin{aligned}
dp_{i,j,k} & \stackrel{\min}{\longleftarrow} & dp_{i-[s_i=')'],j-[s_j=')'],k+1}+1 \\
dp_{i,j,k,l} &\stackrel{\min}{\longleftarrow}& dp_{i-[s_i='('],j-[s_j='('],k-1}+1
\end{aligned}
$$

注意到其实不一定 $k=0$ 的状态才有用，可以手动在后补 $k$ 个右括号来使其合法。容易发现这样子是最优情况。

长度限制解决了，那字典序呢？有 dp 数组了，可以回溯时优先回溯字典序小者来满足最优性。

但是 dp 是从后往前最优啊？那就把原字符串翻转一下，最前的数就到最后了。

为了让翻转后还能匹配，翻转后左右括号应交换位置。

然后就做完了。感觉这题不错，难度也不大，为什么没有人赛时做出来呢。

std 写得好漂亮，学到了一些 `string` 的新用法。

```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int M = 305;
int f[M][M][M];
int n, m, pi, pj, pt, pk; 
string a, b;
void chkmin(int &x, int y) {
    if(y < x) x = y;
}
string calc(int k, int n, int m) {
    if(k + n + m == 0) return "";
    int pn = n - (a[n] == ')'), pm = m - (b[m] == ')');
    if(f[k+1][pn][pm] + 1 == f[k][n][m]) return calc(k+1, pn, pm) + ')';
    pn = n - (a[n] == '('), pm = m - (b[m] == '(');
    return calc(k-1, pn, pm) + '(';
}
void rev(string &x) {
    int n = x.length();
    for(int i = 0; i < n/2; i++) swap(x[i], x[n - i - 1]);
    for(int i = 0; i < n; i++) x[i] = '(' + ')' - x[i];
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    n = a.length(); m = b.length();
    rev(a); rev(b);
    a = ' ' + a; b = ' ' + b;
    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= max(n, m); k++) {
                int pn = i - (a[i] == ')'), pm = j - (b[j] == ')');
                chkmin(f[k][i][j], f[k+1][pn][pm] + 1);
                pn = i - (a[i] == '('), pm = j - (b[j] == '(');
                if(k) chkmin(f[k][i][j], f[k-1][pn][pm] + 1);
            }
        }
    }
    string ans = {(char)('(' + 10)};
    int mnlen = 998244353;
    for(int k = 0; k <= max(n,m); k++) {
        mnlen = min(mnlen, f[k][n][m] + k);
    }
    for(int k = 0; k <= max(n,m); k++) {
        if(mnlen == f[k][n][m] + k) ans = min(ans, calc(k, n, m) + string(k, ')'));
    }
    rev(ans);
    cout << ans << endl;
}
```