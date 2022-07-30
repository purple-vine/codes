#include <cstdio>
#include <cstring>
#include <assert.h>
using namespace std;
const int M = 70005;
// x : ^   y : |
int cnt[M], a[M], n, x, y, S, T, m = 65536, ans[M], cnt1, cnt2, num[M], xx, yy;
int main(){
    scanf("%d %d", &S, &T);
    while(T--){
        scanf("%d %d %d", &n, &x, &y);
        memset(cnt, 0, sizeof(cnt)); memset(num, 0, sizeof(num));
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]); ++cnt[a[i]];
        }
        bool f = 0; cnt1 = y;
        for(int i = m; i >= 0; i--){
            if(!cnt[i]) {if(f) putchar('0');}
            else {
                // if(!f) f = 1;
                if(cnt[i] % 2 == 1) putchar('1'), ans[i] = 0, f = 1;
                else {
                    if(cnt1) --cnt1, putchar('1'), ans[i] = 1, f = 1;
                    else if(f) putchar('0'), ans[i] = 2;
                }
            }
        }
        xx = 0;
        if(!f) puts("0");
        else puts("");
        ++num[a[1]];
        for(int i = 2; i <= n; i++){
            int t = a[i]; ++num[t];
            if(ans[t] == 1 && num[t] == cnt[t]) putchar('|'), ++yy;
            else if(cnt1) putchar('|'), --cnt1, ++yy;
            else putchar('^'), ++xx;
        } puts("");
        assert(xx == x);
        // for(int i = 1; i <= x; i++) putchar('^');
        // for(int i = 1; i <= y; i++) putchar('|');
        // puts("");
    }
}