  
  
[szoj原题](http://www.szoj.net/problem/3177)  
  
[luogu原题](https://www.luogu.com.cn/problem/P2151)  
  
题意：给定一张带边权无向图，求 $A->B$ 长度为 $t$ 路径数，其中不能走回刚走过的边。  
  
若无最后一点限制，可以直接建邻接矩阵矩乘。  
  
我们很难控制走什么边，但我们可以控制从什么转移到什么，于是考虑从边转移至边。  
  
初始矩阵：$1 \cdot 2m$， 其中为 $1$ 的边是 $A$ 的出边。  
  
转移矩阵：一个 $2m \cdot 2m$ 的 $01$ 矩阵， $i$ 行 $j$ 列为 $1$ 表示 $i$ 的终点为 $j$ 的起点，且 $(i-1) \ xor \ 1 + 1 \ \ != j$。  
  
对 $B$ 的入边求和即为答案。  
  
总结：思考什么方便通过转移约束。  
```cpp  
#include <cstdio>  
#include <cstring>  
#define int long long  
#define p 45989  
#define F(i, n) for(int i = 1; i <= n; i++)  
using namespace std;  
const int M = 205;  
struct edge{  
    int to, nxt;  
}e[M << 1];  
int head[M], cnt1;  
void link(int u, int v){  
    e[++cnt1].to = v; e[cnt1].nxt = head[u]; head[u] = cnt1;  
}  
struct matrix{  
    int a[M][M], n, m;  
    matrix(int n_, int m_, bool f){  
        n = n_; m = m_; memset(a, 0, sizeof(a));  
        if(f) F(i, n) a[i][i] = 1;  
    }  
    matrix() {}  
    matrix operator * (const matrix &tmp) const{  
        matrix t; t.n = n; t.m = tmp.m; memset(t.a, 0, sizeof(t.a));  
        F(i, n) F(j, t.m) F(k, m) t.a[i][j] = (t.a[i][j] + a[i][k] * tmp.a[k][j]) % p;  
        return t;  
    }  
    void print(){  
        printf("%d %d\n", n, m);  
        F(i, n) {F(j, m) printf("%d ", a[i][j]); printf("\n");}  
        printf("\n");  
    }  
};  
matrix qpow(matrix a, int k){  
    matrix t(a.n, a.n, 1);  
    for(; k; k >>= 1){  
        if(k & 1) t = t * a;  
        a = a * a;   
    } return t;  
}  
int n, m, t, a, b, u, v, ans;  
signed main(){  
    scanf("%lld %lld %lld %lld %lld", &n, &m, &t, &a, &b);  
    for(int i = 1; i <= m; i++) scanf("%lld %lld", &u, &v), link(u, v), link(v, u);  
    matrix s2(2 * m, 2 * m, 0), s1(1, 2 * m, 0);  
    for(int i = 1; i <= 2 * m; i++)  
        for(int j = head[e[i].to]; j; j = e[j].nxt)  
            s2.a[i][j] = 1;  
    for(int i = 1; i <= 2 * m; i++) s2.a[i][(i - 1 ^ 1) + 1] = 0;  
    for(int i = head[a]; i; i = e[i].nxt) s1.a[1][i] = 1;  
//  s1.print(); s2.print();  
    s1 = s1 * qpow(s2, t - 1); //s1.print();  
    for(int i = head[b]; i; i = e[i].nxt) ans = (ans + s1.a[1][(i - 1 ^ 1) + 1]) % p;  
    printf("%lld\n", ans);  
}  
```  
<br>  
  

-----
分类：记录