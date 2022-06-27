#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long 
using namespace std;
const int M = 7, N = 600005;
char get(){
    char cc = getchar();
    while(cc < 'a' || cc > 'z') cc = getchar();
    return cc;
}
struct matrix{
    int a[M][M], n, m;
    matrix operator * (const matrix &tmp) const{
        matrix t; memset(t.a, 0, sizeof(t.a)); t.n = n; t.m = tmp.m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= t.m; j++)
                for(int k = 1; k <= m; k++)
                    t.a[i][j] += a[i][k] * tmp.a[k][j];
        return t;
    }
}t, z[N], op2, op3, ans;
int n, m, k, p, q, x[M], y[M]; char c[M];
signed main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        z[i].n = 1; z[i].m = 3; z[i].a[1][3] = 1;
        scanf("%d %d", &z[i].a[1][1], &z[i].a[1][2]); //以此纪念两层循环都用i调了两天的我 
    }
    t.n = t.m = op2.n = op2.m = ans.n = ans.m = op3.n = op3.m = 3;
    for(int i = 1; i <= 3; i++) t.a[i][i] = ans.a[i][i] = 1;
    op2.a[1][1] = op3.a[2][2] = -1; op2.a[2][2] = op2.a[3][3] = op3.a[1][1] = op3.a[3][3] = 1;
    for(int i = 1; i <= m; i++){
        c[i] = get();
        if(c[i] == 'm') scanf("%d %d", &x[i], &y[i]);
        if(c[i] == 'm'){
            t.a[3][1] = x[i]; t.a[3][2] = y[i];
            ans = t * ans;
        }
        else if(c[i] == 'x') ans = op2 * ans;
        else ans = op3 * ans;
    }
    for(int i = 1; i <= n; i++){
        z[i] = z[i] * ans;
        printf("%d %d\n", z[i].a[1][1], z[i].a[1][2]);
    }
}
