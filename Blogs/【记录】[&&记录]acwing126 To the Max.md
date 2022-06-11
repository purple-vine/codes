  
  
[link](https://www.acwing.com/problem/content/128/)  
  
开刷《算导》的开始。  
  
题意简述：给定一个 $n \cdot n$ 矩阵，求其中子矩阵的数值和最大值，$n \leq 100$。  
  
思路：  
  
第一眼想到前缀和，但是二维前缀和的变量太多了，固定其中几个变量也显然没用。考虑往简单的情况——一维想。  
  
对于一维，答案可以在 $O(n)$ 中求出，于是，可以枚举 $l,r$，把第 $l-r$ 行压到一起，再按一维的情况处理。  
  
复杂度 $O(n^3)$  
  
code:  
```cpp  
#include <cstdio>  
#include <iostream>   
#define inf 1000000000  
using namespace std;  
const int M = 105;  
int a[M][M], sum[M][M], n, ans = -inf; //sum[i][j]代表第i列前j项的和   
int main(){  
    scanf("%d", &n);  
    for(int i = 1; i <= n; i++)  
        for(int j = 1; j <= n; j++)  
            scanf("%d", &a[i][j]);  
    for(int i = 1; i <= n; i++)  
        for(int j = 1; j <= n; j++)  
            sum[i][j] = sum[i][j-1] + a[j][i];  
    for(int i = 1; i <= n; i++){  
        for(int j = i; j <= n; j++){  
            int temp = 0, maxx = inf, tempans = 0;  
            for(int k = 1; k <= n; k++){  
                temp = max(0, temp + sum[k][j] - sum[k][i-1]);  
                tempans = max(tempans, temp); maxx = max(maxx, sum[k][j] - sum[k][i-1]);  
//              printf("i=%d j=%d k=%d ans=%d temp=%d sum[k][j]=%d sum[k][i-1]=%d\n", i, j, k, ans, temp, sum[k][j], sum[k][i-1]);  
            }  
            if(maxx < 0) tempans = maxx;  
            ans = max(ans, tempans);  
        }  
    }  
    printf("%d\n", ans);  
}  
/*  
4  
-3 -2 -7 -7  
-9 -2 -6 -2  
-4 -1 -4  -1  
-1 -8  -4 -2  
*/  
```  
<br>  
  

-----
分类：记录