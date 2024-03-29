题意：给定 $n=x+y+z$，求满足以下要求的长度为 $n$ 的序列的数目：序列由 $x$ 个 $1$，$y$ 个 $-1$，$z$ 个 $0$ 组成，序列任意前缀和非负，和在 $[l,r]$ 之间。

考虑确定 $z$ 和序列和的方案数。

看做卡特兰数类似折线图考虑。则在不能过线的前提下要到 $(x+1,y-x)$。

过线等价于经过 $y=x-1$。将经过后的路径翻折后经过 $(x+y+1,x-1)$。方案数是 $C_{x+y}^{x}-C_{x+y}^{x-1}$。

$$
l \leq y-x \leq r \\
x+y = n-z \\
\Rightarrow x \in \left [\frac{n-z-r}{2},\frac{n-z-l}{2} \right ] \\
\begin{aligned}
S & = \sum \limits_{z=0}^{n-l} C_{n}^{z} \cdot \sum_{x=\lceil \frac{n-z-r}{2} \rceil} ^ {\lfloor \frac{n-z-l}{2} \rfloor} (C_{n-z}^{x}-C_{n-z}^{x-1}) \\
 & = \sum \limits_{z=0}^{n-l} C_{n}^{z} \cdot (C_{n-z}^{\lfloor \frac{n-z-l}{2} \rfloor }-C_{n-z}^{\lceil \frac{n-z-r}{2} \rceil - 1})
\end{aligned}
$$
$\square$

这里不保证 $p$ 是质数。分离与膜数互质与不互质的地方并重载即可。

代码慢慢写，应该也不难写。

```cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
using namespace std;
const int M = 100005, N = 23;
int mod, phimod, p[N], cnt, n, l, r;
int qpow(int a, int b){
	int ans = 1;
	for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;}
	return ans;
}
int phi(int n){
	int ans = n;
	for(int i = 2; i * i <= n; i++) if(n % i == 0) {
		ans = ans / i * (i-1); while(n % i == 0) n /= i;
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans; 
}
int inv(int k) {return qpow(k, phimod - 1);}
struct num{
    num() {x = 0; memset(md, 0, sizeof(md));}
    num(int k) {
        memset(md, 0, sizeof(md)); if(k == 0) return; 
        for(int i = 1; i <= cnt; i++){
            while(k % p[i] == 0) k /= p[i], ++md[i];
        }
        x = k; invx = inv(k);
    }
    num operator / (const num &t) const{
        num ans; ans.x = 1ll * x * t.invx % mod, ans.invx = 1ll * invx * t.x % mod;
        for(int i = 1; i <= cnt; i++) ans.md[i] = md[i] - t.md[i];
        return ans;
    }
    num operator * (const num &t) const{
        num ans; ans.x = 1ll * x * t.x % mod, ans.invx = 1ll * invx * t.invx % mod;
        for(int i = 1; i <= cnt; i++) ans.md[i] = md[i] + t.md[i];
        return ans;
    }
    int to_num(){
        int ans = x;
        for(int i = 1; i <= cnt; i++) ans = 1ll * ans * qpow(p[i], md[i]) % mod;
        return ans;
    }
    int x, invx, md[N];
} s[M];
int C(int n, int m){
    // printf("n=%d m=%d\n", n, m);
    if(m > n || m < 0) return 0;
    // printf("C(%d, %d) = %d\n", n, m, (s[n] / s[m] / s[n-m]).to_num());
    return (s[n] / s[m] / s[n-m]).to_num();
}
signed main(){
    scanf("%lld %lld %lld %lld", &n, &mod, &l, &r);
    int t = mod;
    for(int i = 2; i * i <= t; i++)
        if(t % i == 0) {p[++cnt] = i; while(t % i == 0) t /= i;}
    if(t > 1) p[++cnt] = t;
    phimod = phi(mod);
    s[0] = num(1);
    for(int i = 1; i <= n; i++) s[i] = s[i-1] * num(i);
    int ans = 0;
    for(int z = 0; z <= n-l; z++){
        ans = (1ll * ans + 1ll * C(n, z) * (C(n-z, (n-z-l)/2) - C(n-z, (n-z-r + 1) / 2 - 1) + mod) % mod) % mod;
        // printf("z=%d ans=%d\n", z, ans);
    }
    printf("%lld\n", ans);
}
```