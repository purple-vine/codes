#include <cstdio>
using namespace std;
int n, k, a[300005];
int main(){
    scanf("%d %d", &n, &k);
    if(n - 2 * k < 0) {puts("-1"); return 0;}
    for(int i = 1; i <= k; i++) a[n - 2*k + i] = n - k + i;
    int p = 1+k;
    for(int i = 1; i <= k; i++){
        while(a[p]) p++;
        a[p] = i;
    }
    p = 1;
    for(int i = k+1; i <= n-k+1; i++){
        while(a[p]) p++;
        a[p] = i;
    }
    // if(p > n+1) puts("-1");
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}