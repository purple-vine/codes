  
  
[前置：后缀数组](https://www.luogu.com.cn/blog/443664/hou-zhui-shuo-zu-xue-xi-bi-ji)  
  
给定一个长度为 $n$ 的字符串，以及一个常数 $k$，求出现次数至少为 $k$ 次的最长子串，以及所有满足这个性质的子串中左端点的最右可能。   
  
出现至少 $k$ 次，意味着至少是 $k-1$ 个后缀的公共前缀。也就是有连续 $k-1$ 个 $height$ 大于 $0$。（想想 $lcp(sa_i,sa_j) = \min_{i \leq k < j} lcp(sa_i, sa_{i+1})$）  
  
但是我们还要求最长。出现至少 $k$ 次的最长子串就是所有连续 $k-1$ 个 $height$ 的最小值中的最大值（所有 $\min$ 中的 $\max$，用单调队列维护 $\min$）。这个可以用单调队列。同时，还要维护连续 $k$ 个 $sa$，来求左端点的最右可能（$\max$）。这个用单调队列也可以轻松维护。复杂度 $O(n \log n)$，瓶颈在求 $sa$ 与 $height$，后面的处理是 $O(n)$ 的。  
  
LCP 是两个后缀之间的关系，所以留 $k-1$ 项。而 $sa$ 不是，所以留 $k$ 项。这里让我调了两天。而 $k=1$ 时要特判输出 `0 n`。  
  
双倍经验：[SP10079](https://www.luogu.com.cn/problem/SP10079) & [P2852](https://www.luogu.com.cn/problem/P2852)，后者不需要维护 $sa$，所以更简单一些。  
```cpp  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <iostream>  
#include <set>  
#define clr(x) memset(x, 0, sizeof(x))  
const int M = 1000005;  
int sa[M], rk[M << 1], cnt[M], id[M], prerk[M << 1], h[M]; char s[M];  
void get_sa(char *s, int n){  
    int m = std::max(256, n);  
    for(int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];  
    for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];  
    for(int i = n; i; i--) sa[cnt[rk[i]]--] = i;  
    for(int i = 0; (1 << i) <= n; i++){  
        int t = (1 << i);  
        memset(cnt, 0, sizeof(cnt));  
        for(int j = 1; j <= n; j++) id[j] = sa[j];  
        for(int j = 1; j <= n; j++) ++cnt[rk[id[j] + t]];  
        for(int j = 1; j <= m; j++) cnt[j] += cnt[j-1];  
        for(int j = n; j; j--) sa[cnt[rk[id[j] + t]]--] = id[j];  
        memset(cnt, 0, sizeof(cnt));  
        for(int j = 1; j <= n; j++) id[j] = sa[j];  
        for(int j = 1; j <= n; j++) ++cnt[rk[id[j]]];  
        for(int j = 1; j <= m; j++) cnt[j] += cnt[j-1];  
        for(int j = n; j; j--) sa[cnt[rk[id[j]]]--] = id[j];  
        memcpy(prerk, rk, sizeof(rk));  
        for(int p = 0, j = 1; j <= n; j++){  
            if(prerk[sa[j]] == prerk[sa[j-1]] && prerk[sa[j]+t] == prerk[sa[j-1]+t])  
                rk[sa[j]] = p;  
            else rk[sa[j]] = ++p;  
        }  
    }  
    for(int i = 1, k = 0; i <= n; i++){  
        if(k) --k;  
        while(s[i+k] == s[sa[rk[i]-1] + k]) ++k;  
        h[rk[i]] = k;  
    }  
}   
int n; int hs[M], sas[M], l1, r1, l2, r2; //hs需要最小值，sas需要最大值   
int main(){  
    int k = 0;  
    while(scanf("%d", &k)){  
        if(k == 0) return 0;  
        scanf(" %s", s+1); n = strlen(s+1);  
        if(k == 1) {printf("%d 0\n", n); continue;}  
        get_sa(s, n); int l = 1, r = n, ans = 0, pl = 0;  
        l1 = 1; r1 = 0; l2 = 1; r2 = 0;  
        for(int i = 1; i <= n; i++){  
            while(l1 <= r1 && h[hs[r1]] >= h[i]) r1--;  
            hs[++r1] = i;  
            while(hs[r1] - hs[l1] + 1 > k - 1) l1++; //hs 中留 k-1 项   
            while(l2 <= r2 && sa[sas[r2]] <= sa[i]) r2--;  
            sas[++r2] = i;  
            while(sas[r2] - sas[l2] + 1 > k) l2++; //sas 中留 k 项   
            int t = h[hs[l1]], maxpl = sa[sas[l2]];  
            if(t > ans) ans = t, pl = maxpl;  
            else if(t == ans) pl = std::max(pl, maxpl);  
        }  
        if(ans == 0) printf("none\n");  
        else printf("%d %d\n", ans, pl-1);  
        clr(sa); clr(rk); clr(cnt); clr(id); clr(prerk); clr(h); clr(s);  
    }   
    return 0;  
}  
```  
<br>  
  

-----
分类：记录