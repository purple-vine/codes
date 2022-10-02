#include <cstdio>
#include <assert.h>
using namespace std;
const int M = 1005;
bool used[M * M]; int a[M][M], n;
void three(){
    printf("3 9 1\n5 7 8\n4 2 6");
}
void four(){
    printf("15 11 16 12\n13 3 6 9\n14 7 8 1\n4 2 10 5");
    // exit(0);
}
void five(){
    printf("11 13 15 17 19\n21 23 25 1 3\n5 7 9 24 22\n20 18 16 14 12\n10 8 6 4 2");
}
void six(){
    printf("11 9 7 5 3 1\n35 33 31 29 27 25\n23 21 19 17 15 13\n2 4 6 8 10 12\n14 16 18 20 22 24\n26 28 30 32 34 36");
}
void seven(){
    printf("15 17 19 21 23 25 27 \n29 31 33 35 37 39 41\n43 45 47 49 1 3 5\n7 9 11 13 14 12 10\n8 6 4 2 48 46 44\n42 40 38 36 34 32 30\n28 26 24 22 20 18 16");
}
void eight(){
    printf("15 13 11 9 7 5 3 1 \n47 45 43 41 39 37 35 33 \n63 61 59 57 55 53 51 49 \n31 29 27 25 23 21 19 17 \n2 4 6 8 10 12 14 16 \n18 20 22 24 26 28 30 32 \n34 36 38 40 42 44 46 48\n50 52 54 56 58 60 62 64");
}
int main(){
    scanf("%d", &n);
    if(n == 3) {three(); return 0;}
    if(n == 4) {four(); return 0;}
    // assert(n <= 4);
    if(n == 5) {five(); return 0;}
    if(n == 6) {six(); return 0;}
    if(n == 7) {seven(); return 0;}
    if(n == 8) {eight(); return 0;}
    for(int i = 1; i < n; i++){
        a[i][i+1] = 3 * (2*i-1); used[3 * (2*i-1)] = 1;
    }
    for(int i = 1; i < n; i++){
        a[i+1][i] = 6*i; used[6*i] = 1;
    }
    int t = 3 * (2 * (n-1)), num = (n*n+1)/2 - (n-2) * (n-1) / 2 - (n-1);
    // printf("num=%d\n", num);
    for(int i = 1; i <= num; i++){
        a[i][i] = t + 3 * (2 * i - 1); used[t + 3 * (2 * i - 1)] = 1;
    }
    t = 6 * (n-1);
    for(int i = num+1; i <= n; i++){
        int k = i - n/2;
        a[i][i] = t + 6 * k; used[t + 6*k] = 1;
    }
    // for(int i = n; i >= 1; i--){
    //     for(int j = 1; j <= n; j++){
    //         printf("%d ", a[j][i]);
    //     } printf("\n");
    // }
    int p1 = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i-2; j++){
            while(used[p1]) p1 += 2;
            used[p1] = 1;
            a[j][i] = p1; p1 += 2;
        }
    }
    p1 = 2;
    for(int i = 1; i <= n; i++){
        for(int j = i+2; j <= n; j++){
            while(used[p1]) p1 += 2;
            used[p1] = 1;
            a[j][i] = p1; p1 += 2;
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            printf("%3d ", a[j][i]);
        } printf("\n");
    }
    for(int i = 1; i <= n*n; i++){
        if(!used[i]) printf("%d ", i), assert(-1);
    }
}