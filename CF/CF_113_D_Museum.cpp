#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define mp(a, b) ((a-1) * n + b) // 值域 n*n
#define eps 1e-10
using namespace std;
const int M = 505;
double a[M][M], b[M], p[M]; int n, deg[M], m, s, t; bool f[M][M];
vector<int> e[M];
void guass(int n){
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
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 1; i <= m; i++){
        int x, y; scanf("%d %d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        ++deg[x]; ++deg[y];
    }
    for(int i = 1; i <= n; i++) scanf("%lf", &p[i]);
    for(int i = 1; i <= n*n; i++){
        a[i][i] = 1.0; int x = (i-1) / n + 1, y = (i-1) % n + 1;
        for(int x1 : e[x])
            for(int x2 : e[y])
                if(x1 != x2) a[i][mp(x1, x2)] = - (1-p[x1]) / deg[x1] * (1-p[x2]) / deg[x2];
        for(int x1 : e[x])
            if(x1 != y) a[i][mp(x1, y)] = - (1-p[x1]) / deg[x1] * p[y];
        for(int y1 : e[y])
            if(x != y1) a[i][mp(x, y1)] = - (1- p[y1]) / deg[y1] * p[x];
        if(x != y) a[i][i] -=  p[x] * p[y];
    }
    b[mp(s, t)] = 1.0;
    // for(int i = 1; i <= n*n; i++){
    //     for(int j = 1; j <= n*n; j++){
    //         printf("%lf ", a[i][j]);
    //     } printf("%lf\n", b[i]);
    // }
    guass(n * n);
    for(int i = 1; i <= n; i++){
        printf("%lf ", b[mp(i, i)]);
    }
}