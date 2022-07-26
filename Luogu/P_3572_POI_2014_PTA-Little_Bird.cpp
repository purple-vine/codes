#include <cstdio>
using namespace std;
const int M = 1000005;
int q[M], l, r, n, a[M], Q, k, dp[M];
bool cmp(int i, int j){
    return dp[i] != dp[j] ? dp[i] < dp[j] : a[i] > a[j];
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &k); q[l = r = 1] = 1;
        for(int i = 2; i <= n; i++){
            while(l <= r && q[l] < i - k) ++l;
            dp[i] = dp[q[l]] + (a[q[l]] <= a[i]);
            while(l <= r && !cmp(q[r], i)) --r;
            q[++r] = i;
            // printf("%d-%d-%d ", dp[i], l, r);
        }
        printf("%d\n", dp[n]);
    }
}