#include <cstdio>
using namespace std;
const int M = 15;
int n, m, a[M];
void dfs(int p, int l){
    if(p == n+1) {
        for(int i = 1; i <= n; i++) printf("%d ", a[i]);
        printf("\n"); return;
    }
    for(int i = l; i <= m - (n-p); i++){
        a[p] = i; dfs(p+1, i+1);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    dfs(1, 1);
}