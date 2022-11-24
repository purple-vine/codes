#include <cstdio>
using namespace std;
const int M = 21, mod = 1000000007;
int sum[1 << M], a[1 << M], n, pw[1 << M];
void addn(int &x, int y) {if((x += y) >= mod) x -= mod;}
int main(){
    scanf("%d", &n); int all = (1 << 20) - 1;
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = 1ll * pw[i-1] * 2 % mod;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ++sum[all ^ a[i]];
    for(int i = 0; i < 20; i++) 
        for(int j = 0; j < 1 << 20; j++)
            if(j & (1 << i)) sum[j] += sum[j ^ (1 << i)];
    int ans = 0;
    for(int i = 0; i < 1 << 20; i++) {
        addn(ans, (__builtin_popcount(all ^ i) & 1) ? (mod - pw[sum[i]]) : pw[sum[i]]);
    }
    printf("%d\n", ans);
    
}