#include <cstdio>
using namespace std;
const int M = 200005;
int n, a[M], cnt[M];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(a[1] == 1) {printf("No\n"); return 0;}
    cnt[n] = 1;
    for(int i = n-1; i >= 1; i--) cnt[i] = cnt[i+1] + (a[i] != a[i+1]);
    bool f = 0;
    // for(int i = 1; i <= n; i++) printf("%d ", cnt[i]);
    for(int i = 1; i <= n; i++){
        if(i > 1 && a[i] == a[i-1]) break;
        if(i >= cnt[i+1]) {f = 1; break;}
    }
    printf("%s\n", f ? "Yes" : "No");
}