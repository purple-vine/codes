#include <cstdio>
using namespace std;
int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int ans = (n + 2) / 3 + 1;
        if(n == 7) {printf("2 4 1\n"); continue;}
        printf("%d %d %d\n", ans - 1, ans, n - 2 * ans + 1);
    }
}