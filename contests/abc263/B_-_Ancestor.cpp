#include <cstdio>
using namespace std;
const int M = 150;
int p[M], n, ans[M];
int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &p[i]); ans[i] = ans[p[i]] + 1;
    }
    printf("%d\n", ans[n]);
}