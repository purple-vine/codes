#include <cstdio>
#include <iostream>
using namespace std;
const int M = 25;
int n, k, l[M], r[M], w[M], a[M], cnt, fa[M], siz[M];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y){
    // printf("merge %d %d\n", x, y);
    if((x = find(x)) != (y = find(y)))
        fa[x] = y, siz[y] += siz[x];
}
long long ans = 1e18;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &l[i], &r[i], &w[i]);
    for(int i = 0; i < (1 << n); i++){
        cnt = 0; long long sum = 0;
        for(int j = 1; j <= n; j++) fa[j] = j, siz[j] = 1;
        for(int j = 1; j <= n; j++){
            if(i & (1 << (j-1))) a[++cnt] = j; //, printf("%d ", j);
            else sum += w[j];
        } //printf("\n");
        for(int j = 1; j <= cnt; j++)
            for(int k = j+1; k <= cnt; k++)
                if(max(l[a[j]], l[a[k]]) <= min(r[a[j]], r[a[k]])) merge(a[j], a[k]);
        for(int j = 1; j <= n; j++) if(siz[j] > k) sum = -1;
        if(sum != -1) ans = min(ans, sum);
        // printf("sum=%d\n\n", sum);
    }
    printf("%lld\n", ans);
}
/*
5 2
1 4 1
3 6 2
5 8 5
7 10 2
9 12 1
*/