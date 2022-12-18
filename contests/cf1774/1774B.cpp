#include <cstdio>
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--) {
        int n, m, k; scanf("%d %d %d", &n, &m, &k);
        int lim = (n - 1) / k + 1;
        // printf("%d\n", lim);
        bool f = 1; int cnt = 0, a;
        for(int i = 1; i <= m; i++) {
            scanf("%d", &a);
            if(a > lim) f = 0;
            else if(a == lim) ++cnt;
        }
        if(cnt > (n-1) % k + 1) f = 0;
        puts(f ? "Yes" : "No");
    }
}