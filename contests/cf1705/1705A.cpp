#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 10005;
int t, n, a[M], x;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &x);
        for(int i = 1; i <= 2*n; i++) scanf("%d", &a[i]);
        sort(a+1, a+2*n+1); bool f = 0;
        for(int i = 1; i <= n; i++) if(a[i+n] - a[i] < x) {puts("NO"); f = 1; break;}
        if(!f) puts("YES");
    }
}