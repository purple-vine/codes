#include <cstdio>
using namespace std;
const int M = 35;
int c[M][M], n;
int main(){
    scanf("%d", &n);
    c[0][0] = 1;
    for(int i = 1; i <= n; i++){
        c[i][0] = 1;
        printf("1 ");
        for(int j = 1; j < i; j++){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}