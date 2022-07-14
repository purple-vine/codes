//url : https://atcoder.jp/contests/agc011/tasks/agc011_b
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
int a[M], n, ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1); long long s = 0;
    for(int i = 1; i <= n; i++){
        s += a[i]; if(2 * s < a[i+1]) ans = i;
    }
    printf("%d\n", n - ans);
}