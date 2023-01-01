#include <cstdio>
#include <vector>
#include <set>
#define int long long
using namespace std;
const int M = 105;
int p[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int a[M], n;
signed main() {
    int t; scanf("%lld", &t);
    auto chk = [](int p) -> bool {
        vector<int> f(p);
        for(int i = 1; i <= n; i++) ++f[a[i] % p];
        for(int i = 0; i < p; i++) if(f[i] < 2) return 0;
        return 1;
    } ;
    while(t--) {
        scanf("%lld", &n);
        set<int> t;
        bool f = 1;
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            if(t.find(a[i]) != t.end()) f = 0;
            t.insert(a[i]);
        }
        for(int i = 1; i <= 25; i++) {
            if(chk(p[i])) f = 0;
        }
        if(f) printf("YES\n");
        else printf("NO\n");
    }
}