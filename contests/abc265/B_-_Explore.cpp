#include <cstdio>
#define int long long
using namespace std;
const int M = 100005;
int n, m, t, a[M], x[M], y[M], c[M];
signed main(){
    scanf("%lld %lld %lld", &n, &m, &t);
    for(int i = 1; i < n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%lld %lld", &x[i], &y[i]), c[x[i]] = y[i];
    for(int i = 1; i < n; i++){
        // if(t <= 0) {printf("No\n"); return 0;}
        t -= a[i]; if(t <= 0) {printf("No\n"); return 0;}
        t += c[i+1];
    }
    if(t <= 0) printf("No\n");
    else printf("Yes\n");
}