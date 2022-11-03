#include <cstdio>
#define LL long long
using namespace std;
const int M = 200005;
LL x[M], n, SG; int y[M], m;
int main(){
    scanf("%lld %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld %d", &x[i], &y[i]);
    }
    if(m == 0) SG = n % 2;
    else {
        SG ^= (x[1] - 1);
        SG ^= (n - x[m]);
        for(int i = 1; i < m; i++) {
            SG ^= (y[i] == y[i+1]);
        }
    }
    
    printf("%s\n", SG == 0 ? "Aoki" : "Takahashi");
}