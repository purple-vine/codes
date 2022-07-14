//url : https://atcoder.jp/contests/abc154/tasks/abc154_e
#include <cstdio>
#include <cstring>
using namespace std;
const int M = 1005;
char num[M]; int ans[M][3], ll, k;
int dp(int n, int m, bool l){
    // printf("%d %d %d\n", n, m, l);
    if(m == 0) return 1;
    if(n == ll) return 0;
    if(!l && ans[n][m]) return ans[n][m];
    int cur = 0;
    if(l){
        if(num[n] == '0') cur += dp(n+1, m, l);
        else cur += dp(n+1, m-1, 1) + dp(n+1, m, 0) + (num[n] - '0' - 1) * dp(n+1, m-1, 0);
    }
    else cur = 9 * dp(n+1, m-1, 0) + dp(n+1, m, 0); 
    if(!l) ans[n][m] = cur;
    // printf("%d %d %d %d\n", n, m, l, cur);
    return cur;
}
int main(){
    scanf("%s", num); scanf("%d", &k); ll = strlen(num);
    printf("%d\n", dp(0, k, 1));
}