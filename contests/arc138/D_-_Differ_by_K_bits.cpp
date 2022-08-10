#include <cstdio>
using namespace std;
const int M = 19;
bool f[1 << M]; int a[1 << M], n, k, st[1 << M], tt;
void pre(){
    for(int i = 0; i < (1 << n); i++)
        if(__builtin_popcount(i) == k) st[++tt] = i;
}
bool dfs(int dep){
    // printf("%d %d\n", dep, a[dep-1]);
    if(dep == (1 << n)){
        for(int i = 0; i < (1 << n); i++) printf("%d ", a[i]);
        return 1; 
    }
    for(int i = 1; i <= tt; i++){
        int to = (a[dep-1] ^ st[i]); if(f[to]) continue;
        f[to] = 1; a[dep] = to; if(dfs(dep+1)) return 1; f[to] = 0;
    }
    return 0;
}
int main(){
    scanf("%d %d", &n, &k);
    if(n == 1 && k == 1) {printf("1\n0 1\n"); return 0;}
    if(k % 2 == 0 || n >= k) {printf("No\n"); return 0;}
    printf("Yes\n");
    pre(); f[0] = 1; dfs(1);
}