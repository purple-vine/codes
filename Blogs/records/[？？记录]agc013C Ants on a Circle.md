好题。

题意：$n$ 只蚂蚁在圆周上以同样速度顺或逆时针爬行，相遇时同时转向，$t$ 时间后求每只蚂蚁坐标。

首先是经典结论：等速同时转向等价于交换身份。

接着，忽略蚂蚁的交换编号，所有蚂蚁的相对位置不变。

因此，可以固定一只蚂蚁找其新编号，也可以固定一个位置找其对应蚂蚁。前者看着好做一点。

维护第一只蚂蚁，把 $0$ 看做基准，则每一只蚂蚁顺时针越过一次 $0$ 线，这只蚂蚁的编号应加一；每一次逆时针越过，它的编号应减一。

于是做完了。我学校中的想法是对每只蚂蚁二分新编号，但是晚上才发现这样处理不了环。cmd 的记录相对 Luogu 题解给了我更多启示，而 [兔队的做法](https://www.cnblogs.com/PinkRabbit/p/AGC013.html) 更接近我上午的想法。

```cpp
#include <cstdio>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
const int M = 1e5 + 5;
LL n, l, t, ans[M], cnt; 
int main() {
    scanf("%lld %lld %lld", &n, &l, &t);
    for(int i = 0; i < n; i++) {
        LL x, s; scanf("%lld %lld", &x, &s);
        if(s == 1) {
            cnt += (x + t) / l; cnt = (cnt % n + n) % n;
        } else {
            cnt -= ceil(1.0 * (t-x) / l); cnt = (cnt % n + n) % n;
        }
        ans[i] = ((x + (s == 1 ? t : -t)) % l + l) % l;
    }
    sort(ans, ans+n);
    for(int i = 0; i < n; i++) {
        printf("%d\n", ans[(i + cnt) % n]);
    }
}
```