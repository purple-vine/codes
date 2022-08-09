#include <cstdio>
using namespace std;
const int M = 500005;
int n, a[M], cnt; long long ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == i) cnt++;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == i) continue;
        ans += (a[a[i]] == i);
    }
    printf("%lld\n", 1ll * cnt * (cnt-1) / 2 + ans / 2);
}