  
  
巧妙的思维题。只用并查集，但评蓝不过分。  
  
好早前打%你赛时做过此题，当时我们都骗分AC，%一发 LZY，这题考场上写出了正解。  
  
先不管已有的点，计算在这种情况下一共能最多出现多少点，再减去原有的数目。后面提到的会交出一个点默认交出的这个点是可以被生成的。  
  
从**平行于横纵轴的直线**的方面考虑。若两条平行于 $x$ 轴的线上有一对 $x$ 坐标相同的点，显然，这两条线上所有点的横坐标将会一一对应相等。于是考虑使用**并查集**将这两条线合并起来，如果有一条竖线交其中一条线于一个点，明显地，它也会交与这条线在同并查集中的其他线于另一个横坐标相同的点。  
  
开一个 `vector` 数组存所有 $x$ 相同的点，即可完成合并。注意：$x$ 与 $y$ 不要搞反。  
```cpp  
#include <cstdio>  
#include <vector>  
using namespace std;  
const int M = 100005;  
struct bcj{  
    int n, fa[M], siz[M];  
    void init(int n_){  
        n = n_; for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;  
    }  
    int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}  
    void merge(int u, int v){  
        u = find(u); v = find(v);  
        if(u != v) fa[u] = v, siz[v] += siz[u];  
    }  
}s1;  
int n, x[M], y[M], m = 100000; vector<int> xy[M];  
bool vis[M]; long long ans;  
int main(){  
    scanf("%d", &n);  
    for(int i = 1; i <= n; i++){  
        scanf("%d %d", &x[i], &y[i]);  
        xy[x[i]].push_back(y[i]);  
    }  
    s1.init(m); s2.init(m);  
    for(int i = 1; i <= m; i++)  
        for(int j = 1; j < xy[i].size(); j++) s1.merge(xy[i][0], xy[i][j]);  
    for(int i = 1; i <= n; i++){  
        int yy = s1.find(y[i]);  
        if(vis[x[i]]) continue; vis[x[i]] = 1;  
        ans += 1ll * s1.siz[yy];  
    }  
    printf("%lld\n", ans - n);  
}  
```  
<br>  
  

-----
分类：记录