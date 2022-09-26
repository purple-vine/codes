#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 1e-10
using namespace std;
const int M = 305;
double a[M][M], b[M]; int n, deg[M], m, p, q; bool f[M][M];
void guass(){
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++) if(fabs(a[j][i]) > fabs(a[i][i])) {swap(a[i], a[j]); swap(b[i], b[j]);}
        for(int j = 1; j <= n; j++){
            if(i == j) continue; double r = a[j][i] / a[i][i];
            for(int k = 1; k <= n; k++) a[j][k] -= a[i][k] * r;
            b[j] -= r * b[i];
        }
    }
    for(int i = 1; i <= n; i++) b[i] /= a[i][i];
}
/*
f(i) = sum ( f(x) * (1-p) / deg_x )
*/
int main(){
    scanf("%d %d %d %d", &n, &m, &p, &q);
    double r = 1.0 * p / q;
    for(int i = 1; i <= m; i++){
        int x, y; scanf("%d %d", &x, &y); f[y][x] = f[x][y] = 1; ++deg[x]; ++deg[y];
    }
    for(int i = 1; i <= n; i++){
        a[i][i] = 1.0;
        for(int j = 1; j <= n; j++){
            if(!f[i][j]) continue;
            a[i][j] = (r - 1) / deg[j];
        }
    }
    b[1] = 1.0;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         printf("%lf ", a[i][j]);
    //     } printf("%lf\n", b[i]);
    // }
    guass();
    for(int i = 1; i <= n; i++){
        printf("%lf\n", b[i] * r);
    }
}