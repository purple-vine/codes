#include <cstdio>
using namespace std;
const int M = 105;
int a[M][M], n, u, v, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d %d", &u, &v), a[u][v] = a[v][u] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                if(a[i][j] && a[j][k] && a[k][i]) ans++;
            }
        }
    }
    printf("%d\n", ans);
}