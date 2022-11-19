这阵子没一道题能自己想出来，开道黄题以下找找信心 qwq

又一道比 C 简单的 D。

题意：给出 $n$ 个 $6$ 位及以下数字，问有几对数字的和在十进制下无进位。$n \leq 10^6$。

值域小就可以为所欲为！

把第一个数每个数位改成 $9$ 减当前数位，则需要查询每一维的数值分别小于给定数的数的个数，考虑做一个六维前缀和，则直接查表即可知道答案。复杂度 $O(n)$，这里认为值域与 $n$ 同阶。

刚刚写了一道二进制多维前缀和 [arc137D](https://www.cnblogs.com/purplevine/p/16906170.html)，现在再来一道十进制多维前缀和。atc 好贴心，还注意到了新学知识点后的练习。

注意如果一个数所有数位不超过 $4$ 则会被和自己统计一次。

```cpp
#include <cstdio>
#include <tuple>
#include <map>
#include <cmath>
#define LL long long
using namespace std;
const int M = 1e6 + 5;
using num = tuple<int, int, int, int, int, int>;
LL a[M], sum[M]; int n;
int qpow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) ans = ans * a;
        a = a * a;
    }
    return ans;
}
bool chk(int t) {
    while(t) {
        if(t % 10 >= 5) return 0;
        t /= 10;
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ++sum[a[i]];
    }
    int w = 1000000;
    for(int i = 0; i < 6; i++) {
        int pw = qpow(10, i);
        for(int j = 0; j < w; j++) {
            if((j / pw) % 10) sum[j] += sum[j - pw];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += sum[w - 1 - a[i]];
        if(chk(a[i])) --ans;
    }
    printf("%d\n", ans / 2);
}
```