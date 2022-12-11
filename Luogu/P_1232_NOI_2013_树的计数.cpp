#include <cstdio>
using namespace std;
const int M = 2e5 + 5;
int read(){
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
int n, bfs[M], pos[M], dfs[M], dif[M], dfn[M];
void solve(int l, int r) {++dif[l]; --dif[r+1];}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) dfn[read()] = i;
    for(int i = 1; i <= n; i++) pos[dfn[read()]] = i;
    for(int i = 1; i <= n; i++) dfn[pos[i]] = i;
    solve(1, 1);
    double ans = 1;
    for(int i = 1; i < n; i++) {
        if(pos[i] < pos[i+1] - 1) solve(pos[i], pos[i+1] - 1);
        if(dfn[i] > dfn[i+1]) ++ans, solve(i, i);
    }
    int t = 0;
    for(int i = 1; i < n; i++) {
        t += dif[i];
        ans += t ? 0 : 0.5;
    }
    printf("%.3lf\n", ans+1);
}