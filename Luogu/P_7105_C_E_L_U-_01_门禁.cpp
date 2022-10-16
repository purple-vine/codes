#include <cstdio>
using namespace std;
const int M = 20;
double p[M][M]; int n, t[1 << M], cnt;
double c[M][1 << M], ans; //c[i][S] : \pai _ {j \in S} (1 - p_{i, j})
double f[1 << M]; int pl[1 << M];
double r[1 << M];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%lf", &p[i][j]);
    for(int i = 0; i < n; i++) pl[1 << i] = i+1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < (1 << n); j++){
            c[i][j] = 1;
            for(int k = j; k; k -= k & -k) c[i][j] *= (1 - p[i][pl[k & -k]]);
        }
    }
    for(int S = 1; S < (1 << n); ++S){
        f[S] = 1;
        int l = S & -S, k = S ^ l; cnt = 0;
        for(int s = k; s; s = (s-1) & k){
            t[++cnt] = s; // printf("S=%d T=%d\n", S, s);
        }
        t[++cnt] = 0;
    r[0] = 1;
    for(int i = 1; i <= n; i++) r[1 << i-1] = c[i][((1 << n) - 1) ^ S];
    for(int i = cnt; i >= 1; i--){
        int T = t[i], U = T & -T;
        r[T] = r[U] * r[T ^ U];
    }
        for(int i = 2; i <= cnt; i++){
            int T = t[i] ^ l;
            // printf("S=%d T=%d\n", S, T);
            double cnt = 1;
            for(int j = T; j; j -= j & -j) cnt *= c[pl[j & -j]][S ^ T]; //,
            // printf("%d %d %lf\n", pl[j & -j], S^T, c[pl[j & -j]][S ^ T]);
            f[S] -= f[T] * cnt;
            // printf("%lf:::\n", f[T] * cnt);
        }
        // printf("ans1 %d %lf\n", S, f[S]);
        int K = ((1 << n) - 1) ^ S;
        double r = 1;
        for(int i = 1; i <= n; i++) if(S & (1 << i-1)){
            for(int j = 1; j <= n; j++) if(K & (1 << j-1)){
                r *= (1 - p[i][j]);
            }
        }
        // printf("ans2 %d %lf %lf\n", S, r * f[S], ans);
        ans += r * f[S];
    }
    printf("%lf\n", ans);
}