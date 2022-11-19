// arc124D
#include <cstdio>
#include <iostream>
using namespace std;
const int M = 3e5 + 5;
int n, m, p[M], k, a, b; bool col[M], vis[M];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n+m; i++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++) col[i] = 1;
    for(int i = 1; i <= n+m; i++) {
        if(vis[i]) continue;
        int j = i, len = 0, cnt = 0;
        do {
            cnt += col[j]; ++len;
            vis[j] = 1; j = p[j]; 
        } while(j != i);
        ++k;
        if(cnt == 0 && len > 1) ++a;
        else if(cnt == len && len > 1) ++b;
    }
    printf("%d\n", n + m - k + 2*max(a, b));
}