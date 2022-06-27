#include <cstdio>
#include <iostream>
using namespace std;
const int M = 100005;
int h[M], n, hh, w, st[M], top; long long ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    h[0] = h[n + 1] = 0;
    for(int i = 0; i <= n + 1; i++){
        while(top > 0 && h[st[top]] >= h[i]){
            int hh = h[st[top--]], w;
            if(top == 0) w = i - 1;
            else w = i - st[top] - 1;
            ans = max(ans, 1ll * hh * w);
        } st[++top] = i;
    }
    printf("%lld\n", ans);
    return 0;
}
