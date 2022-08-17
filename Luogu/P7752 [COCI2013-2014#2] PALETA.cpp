#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int M = 1000005, mod = 1000000007;
int qpow(int a, int b) {int ans = 1; for(; b; b >>= 1) {if(b & 1) ans = 1ll * ans * a % mod; a = 1ll * a * a % mod;} return ans;}
int n, k, ans = 1, tim, calc[M], f[M], dfn[M], cnt, ss, cnt2;
int top;
int dfs(int x){
    int xx = x;
    for(; ;){
        // if(f[x] == x) return 1;
        if(dfn[x]) return dfn[x] >= dfn[top] ? cnt - dfn[x] + 1 : 0;
        dfn[x] = ++cnt; x = f[x]; 
    }
}
void work(int x){
    top = x; int siz = dfs(x);
    if(siz > 0){
        ans = 1ll * ans * calc[siz] % mod; ss += siz;
    } 
}
int main(){
    scanf("%d %d", &n, &k);
    calc[0] = 1; calc[1] = k; calc[2] = 1ll * k * (k-1) % mod; calc[3] = 1ll * k * (k-1) * (k-2) % mod;
    for(int i = 4; i <= n; i++){
        calc[i] = (1ll * (k-1) * calc[i-2] % mod + 1ll * (k-2) * calc[i-1] % mod) % mod;  
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for(int i = 1; i <= n; i++) if(!dfn[i]) work(i);
    // printf("%d %d\n", ans, ss);
    printf("%d\n", 1ll * ans * qpow(k-1, n-ss) % mod);
}