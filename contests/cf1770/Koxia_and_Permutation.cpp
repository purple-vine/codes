#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int M = 2e5 + 5;
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d %d", &n, &k);
        vector<int> a(n+1);
        vector<bool> f(n+1);
        queue<int> q;
        if(k == 1) {
            for(int i = 1; i <= n; i++) printf("%d ", i);
            printf("\n");
        } else {
            for(int i = 0; i < n/k; i++) {
                a[i * k + 1] = n - i;
                a[(i + 1) * k] = i + 1;
                f[n-i] = f[i+1] = 1;
            }
            for(int i = 1; i <= n; i++) if(!f[i]) q.push(i);
            for(int i = 1; i <= n; i++) if(!a[i]) a[i] = q.front(), q.pop();
            for(int i = 1; i <= n; i++) printf("%d ", a[i]);
            printf("\n");
        }
    }
}