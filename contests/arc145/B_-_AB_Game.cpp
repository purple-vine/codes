#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
LL n, a, b;
int main(){
    scanf("%lld %lld %lld", &n, &a, &b);
    if(n < a) printf("0\n");
    else if(a <= b) printf("%lld\n", n-a+1);
    else {
        int k = (n-b+1) / a;
        printf("%lld\n", k * b + min(b, max(n - (k+1) * a + 1, 0ll)));
    }
}