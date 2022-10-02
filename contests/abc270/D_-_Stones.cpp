#include <cstdio>
using namespace std;
const int M = 10005;
int num[M][2], a[M], n, k;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++) scanf("%d", &a[i]);
    num[1][0] = 1; num[0][0] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(a[j] > i) break;
            if(a[j] + num[i - a[j]][1] > num[i][0]) {
                num[i][0] = a[j] + num[i - a[j]][1];
            }
        }
        num[i][1] = i - num[i][0];
    }
    printf("%d\n", num[n][0]);
}