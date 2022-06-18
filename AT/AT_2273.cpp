#include <cstdio>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
const int M = 100005;
int a[M], p[M], n, op[M], cnt; LL maxx, s1[M], s2[M]; char c;
signed main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i != 1) scanf("  %c", &c);
        else c  = '+';
        op[i] = c == '+' ? 1 : -1;
        scanf("%d", &a[i]); if(op[i] == -1) p[++cnt] = i;
        s1[i] = s1[i-1] + 1ll * a[i] * op[i]; s2[i] = s2[i-1] + 1ll * abs(a[i]);
    }
    p[cnt+1] = n+1;
    for(int i = 1; i <= cnt; i++){
        int pl = p[i], pl2 = p[i+1]; 
        LL ans = s1[pl-1] - (s2[pl2-1] - s2[pl-1]) + s2[n] - s2[pl2-1];
        // printf("+%d -%d +d%\n", s1[pl-1], (s2[pl2-1] - s2[pl-1]), s2[n] - s2[pl2-1]);
        maxx = max(maxx, ans);
    }
    printf("%lld\n", max(maxx, s1[n])); 
}