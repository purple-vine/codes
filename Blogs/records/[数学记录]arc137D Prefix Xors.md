FWT/高维前缀和入门题。

题意：给定一个数列 $a$，每次迭代把原数组替代为前缀异或和数组，求经过 $1-m$ 次操作后 $a_n$ 的值。$n \leq 10^6$。

首先，无论是手推找规律还是生成函数硬推，$k$ 次后 $a_i$ 给 $a_n$ 贡献 $\binom{n-i+k-1}{k-1}$ 次。

两次异或相互抵消，故 $a_i$ 对 $a_n$ 有贡献当且仅当 $\binom{n-i+k-1}{k-1}$ 是奇数，使用 Lucas 定理，对于每一位，$n-i+k-1$ 的值都不小于 $k-1$，即 $k-1 \cap n-i+k-1 = k-1$，或 $k-1 \cap n-i=0$。后式的一边已经与 $k$ 无关，意义为 $k-1$ 在全集中的补集含有 $n-i$ 作为子集。可以看成 $n$ 维前缀和，复杂度 $O(n \log n)$。

挺套路，感觉。但是我不会 $n$ 维前缀和，现在会了。我也不会 FWT，现在还是不会。

```cpp
#include <cstdio>
using namespace std;
const int N = 20, M = 1 << N+2;
int u[M], a[M], n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = n-1; i >= 0; i--) scanf("%d", &a[i]), u[i] = a[i];
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j < 1 << 20; j++) {
            if(j & (1 << i)) u[j] ^= u[j ^ (1 << i)];
        }
    }
    for(int i = 1; i <= m; i++) {
        printf("%d ", u[((1 << 20) - 1) ^ (i - 1)]);
    }
}
```