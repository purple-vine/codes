//time : 22-7-26 21:28
//problem url : https://www.luogu.com.cn/problem/P6218
//status : not submitted
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 205;
int f[M][M][2], n, l, r, a[M], cnt;
int c[M][M];
int dp(int n, int m, bool l){ //填到 n 位，后恰好 m 个 0，l 为 1 表示前面都是顶着限制填的
    if(f[n][m][l]) return f[n][m][l];
    if(m < 0) return 0;
    if(cnt - n + 1 < m) return 0; 
    // if(m == cnt - n + 1 && !l) return 1;
    if(n == cnt + 1) return m == 0;
    if(!l) return c[cnt-n+1][m];
    int ans = 0;
    if(l) {
        if(a[n] == 0) ans += dp(n+1, m-1, 1); // 限制是 0 的情况，只能填 0
        else ans += dp(n+1, m-1, 0) + dp(n+1, m, 1); // 限制是 1，可以选择 0 或 1
    } else {
        ans += dp(n+1, m-1, 0) + dp(n+1, m, 0); // 前者填 0，后者填 1
    }
    // printf("%d %d %d %d\n", n, m, l, ans);
    return f[n][m][l] = ans; 
}
void pre(int n = 200){
    c[0][0] = c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= n; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}
int solve(int n){
    cnt = 0; memset(f, 0, sizeof(f));
    for(; n; n >>= 1) a[++cnt] = n & 1;
    reverse(a+1, a+cnt+1);
    int ans = 0;
    // 下面一句处理第一位是 0 的情况，i 表示共填几位，j 表示其中几个 0，第一位一定是 1
    for(int i = 2; i < cnt; i++) for(int j = (i+1)/2; j < i; j++) ans += c[i-1][j];
    // printf("%d\n", ans);
    // 从第二位填起，第一位一定是 1
    for(int i = (cnt+1)/2; i <= cnt-1; i++) ans += dp(2, i, 1);
    return ans;
}
int main(){
    int n; pre();
	// while(~scanf("%d", &n)){
	// 	printf("%d\n", solve(n) + 1);
    //     memset(f, 0, sizeof(f));
	// }
    scanf("%d %d", &l, &r);
    // printf("%d %d %d\n", solve(r), solve(l-1), solve(r) - solve(l-1));
    printf("%d\n", solve(r) - solve(l-1));
}