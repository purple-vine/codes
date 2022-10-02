#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int sgn(int x) {return x == 0 ? 0 : x > 0 ? 1 : -1;}
int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if(sgn(x) != sgn(y)) {
        printf("%d\n", abs(x)); return 0;
    } else {
        if(abs(y) > abs(x)) {
            printf("%d\n", abs(x));
        }
        else if(sgn(z) != sgn(y)){
            printf("%d\n", 2 * abs(z) + abs(x));
        } else if(abs(z) < abs(y)) {
            printf("%d\n", abs(x));
        } else {
            printf("-1\n");
        }
    }
} 