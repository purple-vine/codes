#include <cstdio>
#include <iostream>
#include <assert.h>
using namespace std;
const int M = 500005;
int n, a[M], dp[M], nxt[M], st[M], top;
// 栈顶为 i 时栈长度最大值
int main(){
    scanf("%d", &n); bool f = 1; int cnt = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int l = 1, r; l <= n; l = r+1){
        r = a[l];
        for(int i = l; i <= r; i++) if(a[i] != r - (i - l)) {f = 0; break;}
        ++cnt;
    }
    if(f) {printf("%d\n", cnt); assert(0);}
    for(int i = 1; i <= n; i++){
        while(top && a[st[top]] < a[i]) nxt[st[top--]] = i;
        st[++top] = i;
    }
    for(int i = 1; i <= top; i++) nxt[st[i]] = n+1;
    // for(int i = 1; i <= n; i++) printf("%d ", nxt[i]);
    dp[0] = 0; nxt[0] = 1;
    for(int i = 0; i <= n; i++){
        if(i && !dp[i]) continue;
        int L = nxt[i], R = nxt[nxt[i]] - 1;
        for(int j = L; j <= R; j++) if(a[j] > a[i]) dp[j] = max(dp[j], dp[i] + 1);
    }
    // for(int i = 1; i <= n; i++) printf(" ans = max(ans. %d ", dp[i]);
    int ans = 0; for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
}