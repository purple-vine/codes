// arc137D
#include <cstdio>
using namespace std;
const int N = 20, M = 1 << N+2;
int u[M], a[M], n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = n-1; i >= 0; i--) scanf("%d", &a[i]), u[i] = a[i];
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j < 1 << 20; j++) {
            if(j & (1 << i)) u[j] ^= u[j ^ (1 << i)];
        }
    }
    for(int i = 1; i <= m; i++) {
        printf("%d ", u[((1 << 20) - 1) ^ (i - 1)]);
    }
}