#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int M = 105;
priority_queue<int> q;
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d %d", &n, &m);
        vector<int> a(n), b(m);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]), q.push(-a[i]);
        for(int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
            int t = q.top(); q.pop();
            q.push(-b[i]);
        }
        long long ans = 0ll;
        while(!q.empty()) {
            ans -= 1ll * q.top();
            q.pop();
        }
        printf("%lld\n", ans);
    }
}