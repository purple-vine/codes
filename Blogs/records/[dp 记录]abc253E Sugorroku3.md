> 值得一提的是，在数学期望递推、数学期望动态规划中，我们通常把终止状态作为初值，把起始状态作为目标，倒着进行计算。这是因为在很多情况下，起始状态是唯一的，而终止状态很多。根据数学期望的定义，若我们正着计算，则还需求出从起始状态到达每个终止状态的概率，与 $F$ 值相乘才能得到答案，增加了难度，也容易出错。
>
> lyd《算进》

打完 vp 来补前几天的题

---------

题意：站在 $1$ 处，从 $i$ 同等概率走向 $i,i+1,\cdots,i+a_i$，求到达 $n$ 步数期望。

首先这不能正推，因为分别到达每个地方的概率不是 $1$。

设 $f_i$ 表示从 $i$ 走到 $n$ 的步数期望，则：

$$
\begin{aligned}
f_i  = & \dfrac{\sum\limits_{j=0}^{a_i} f_{i+j}}{1+a_i}+1\\
     = & \dfrac{\sum\limits_{j=1}^{a_i} f_{i+j}}{1+a_i}+1 + \frac{f_i}{a_i+1} \\
\end{aligned}
$$

$$
\frac{a_i}{a_i+1} f_i  =  \dfrac{\sum\limits_{j=1}^{a_i} f_{i+j}}{1+a_i}+1 \\

f_i = \dfrac{\sum\limits_{j=1}^{a_i} f_{i+j}}{a_i} + \frac{a_i+1}{a_i}
$$

用线段树维护区间和即可。

如果直接维护后缀数组，能做到 $O(n)$。

题不难，专门写出来只是为了提醒自己期望一定要倒推。清楚记得绿豆蛙的归宿一题，却因为没写过，忽略了这个常识。

```cpp
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
const int M = 200005, mod = 998244353;
int qpow(int a, int b){
	long long ans = 1ll;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int inv(int k) {return qpow(k, mod - 2);}
int addd(int a, int b) {a += b; return a > mod ? a-mod : a;}
int minus(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
int a[M], n, op, l, r, m, f[M];
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
struct sg{
    int s[M << 2];
    void upd(int o, int l, int r, int x){
        if(l == r) {s[o] = f[x]; return;}
        int mid = l+r >> 1;
        x <= mid ? upd(o<<1, l, mid, x) : upd(o<<1|1, mid+1, r, x);
        s[o] = addd(s[o<<1], s[o<<1|1]);
    }
    int query(int o, int l, int r, int x, int y){
        if(x <= l && r <= y) return s[o];
        int mid = l + r >> 1; int ans = 0;
        if(x <= mid) add(ans, query(o<<1, l, mid, x, y));
        if(y > mid) add(ans, query(o<<1|1, mid+1, r, x, y));
        return ans;
    }
}t; 
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%d", &a[i]);
    for(int i = n-1; i >= 1; i--){
        f[i] = addd(1ll * t.query(1, 1, n, i+1, i+a[i]) * inv(a[i]) % mod,
                    addd(1, inv(a[i]))
                    );
        t.upd(1, 1, n, i);
    }
    printf("%d\n", f[1]);
}
```