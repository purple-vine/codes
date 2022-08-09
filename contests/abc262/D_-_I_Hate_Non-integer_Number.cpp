#include <cstdio>
#include <cstring>
using namespace std;
const int M = 105, mod = 998244353;
void add(int &x, int y) {if((x += y) > mod) x -= mod;}
int n, a[M], f[M][M], ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int t = 1; t <= n; t++){
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for(int i = 1; i <= n; i++){
            int num = a[i] % t;
            for(int j = t; j >= 1; j--){
                for(int k = 0; k < t; k++){
                    add(f[j][(k+num) % t], f[j-1][k]);
                }
            }
        }
        add(ans, f[t][0]);
    }
    printf("%d\n", ans);
}