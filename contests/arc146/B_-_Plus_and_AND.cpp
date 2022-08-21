#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define LL long long
using namespace std;
const int M = 200005;
struct tp{
    int c, pl;
    bool operator < (const tp &t) const{
        return c < t.c;
    }
} p[M];
// 0 : 正常可选 1：已推平 2：不可选
int n, m, K, a[M], ans, t[M]; bool f[M];
int main(){
    scanf("%d %d %d", &n, &m, &K);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int k = 30; k >= 0; k--){
        // printf("start %d:", k);
        for(int j = 1; j <= n; j++)
            if(t[j] != 2)
                p[j] = {t[j] == 1 ? (1 << k) : 
                (a[j] & (1 << k) ? 0 : (1 << k) - (a[j] & ((1 << k+1) - 1))), j}; 
                // printf("%d ", p[j].c);
            else{
                p[j] = {1000000000, j};
            }
        // printf("\n");
        sort(p+1, p+n+1); LL sum = 0; // printf("choose %d:", k);
        for(int j = 1; j <= K; j++) sum += p[j].c;
        // printf("\n");
        if(sum > m) continue; ans |= (1 << k);
        memset(f, 0, sizeof(f));
        m -= sum; for(int j = 1; j <= K; j++) {
            if(p[j].c) t[p[j].pl] = 1;
            f[p[j].pl] = 1;
        }
        // printf("%d %d\nt: ", m, (1 << k));
        for(int j = 1; j <= n; j++) if(!f[j] && ((a[j] & (1 << k)) == 0)) t[j] = 2;
        // for(int j = 1; j <= n; j++) printf("%d ", t[j]);
        // printf("\n");
    }
    printf("%d\n", ans);
}