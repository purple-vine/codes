#include <cstdio>
using namespace std;
const int M = 200005;
int fa[M], n, m, a[M], siz[M]; bool c[M];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++) scanf("%d", &fa[i]), ++siz[fa[i]];
    while(m--){
        int cnt = 0, ans = 0; scanf("%d", &cnt);
        for(int i = 1; i <= cnt; i++) scanf("%d", &a[i]), c[a[i]] = 1;
        for(int i = 1; i <= cnt; i++){
            if(c[fa[a[i]]]) --ans;
            else ++ans;
            ans += siz[a[i]];
            // printf("a[i] = %d ans = %d\n", a[i], ans);
        }
        for(int i = 1; i <= cnt; i++) c[a[i]] = 0;
        printf("%d\n", ans);
    }
}