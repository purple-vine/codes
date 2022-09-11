#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 50005;
char s[M], ps[M], ans[M]; int cnt[M], n, maxx, pl[M], cnt1, lpl;
bool checkmin(){
    for(int i = 1; i <= n; i++) if(ans[i] != ps[i]) return ans[i] > ps[i];
    return 0;
}
int main(){
    scanf("%d", &n); scanf("%s", s+1); 
    for(int i = 1; i <= n; i++) ps[i] = s[n-i+1] == 'd' ? 'p' : 'd';
    for(int i = 1; i <= n; i++){
        if(s[i] == 'p' && !lpl) lpl = i;
        if(s[i] == 'p') cnt[i] = cnt[i-1] + 1;
        if(cnt[i] > maxx) pl[cnt1 = 1] = i, maxx = cnt[i];
        else if(cnt[i] == maxx) pl[++cnt1] = i;
    }
    memcpy(ans, s, n+5);
    for(int i = lpl; i <= n; i++){
        memcpy(ps, s, n+5);
        for(int j = lpl; j <= i; j++) ps[j] = s[lpl + i - j] == 'p' ? 'd' : 'p';
        if(checkmin()){
            memcpy(ans, ps, n+5);
        }
    }
    printf("%s\n", ans+1);
}