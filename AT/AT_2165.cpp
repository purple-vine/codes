//time : 2022-05-22 17:36
//problem id : AT2165 AGC006D
//status : AC
//from : https://www.luogu.com.cn/training/178674
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#define c(x) (a[x] >= t)
using namespace std;
const int M = 200005;
int a[M], n;
bool check(int t){
    for(int i = 1; i <= n-1; i++){
        if(c(n-i) == c(n-i+1)) return c(n-i);
        if(c(n+i) == c(n+i-1)) return c(n+i);
    }
    return c(1);
}
bool vis[M];
int main(){
    // srand(time(0));
    scanf("%d", &n); int ans = 0;
    for(int i = 1; i <= 2*n-1; i++) scanf("%d", &a[i]);
    int l = 1, r = 2*n-1;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    printf("%d\n", ans);
}