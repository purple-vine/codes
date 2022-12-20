#include <cstdio>
#include <vector>
#define int long long
using namespace std;
const int M = 1e5 + 5;
int a[M], s[M], n, cnt[M], dp[M];
#define s(j, x) (dp[j-1] + a[j] * (x - s[j] + 1) * (x - s[j] + 1))
vector<int> q[M]; // 存决策编号
// f_i = max(f_{j-1} + a_i (s_i - s_j + 1) ^ 2)
int calc(int x, int y) { // y 比 x 优的时间
    int l = 1, r = n, ans = n+1;
    while(l <= r) {
        int mid = l + r >> 1;
        if(s(y, mid) >= s(x, mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
signed main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = ++cnt[a[i]];
    }
    #define Q q[a[i]]
    #define R Q[Q.size()-1]
    #define RR Q[Q.size()-2]
    for(int i = 1; i <= n; i++) {  
        while(Q.size() > 1 && calc(R, RR) <= calc(i, R)) Q.pop_back();
        Q.push_back(i);
        while(Q.size() > 1 && calc(R, RR) <= s[i]) Q.pop_back();
        dp[i] = s(R, s[i]);
        // printf("%d %d\n", Q[Q.size()-1] , dp[i]);
        // printf("%d:", i); for(auto u : Q) printf("%d ", u);
        // printf("\n");
    }
    printf("%lld\n", dp[n]);
}