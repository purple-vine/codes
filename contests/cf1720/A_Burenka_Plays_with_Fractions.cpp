#include <cstdio>
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if(a * d == b * c) {printf("0\n"); continue;}
        if(a == 0 || c == 0) {printf("1\n");  continue;}
        if(a * d % (b * c) == 0 || b * c % (a * d) == 0){
            printf("1\n"); continue;
        }
        printf("2\n");
    }
}