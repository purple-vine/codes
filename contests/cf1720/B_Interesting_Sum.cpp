#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100005;
int n, a[M];
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        printf("%d\n", a[n] + a[n-1] - a[1] - a[2]);
    }
}