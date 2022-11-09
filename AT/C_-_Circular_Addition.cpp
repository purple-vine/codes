// arc136C
#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
const int M = 2e5 + 5;
LL a[M], ans1, ans2; int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ans2 = max(ans2, a[i]);
        if(i > 1) ans1 += abs(a[i] - a[i-1]);
    }
    ans1 += abs(a[1] - a[n]);
    ans1 /= 2;
    printf("%lld\n", max(ans1, ans2));
}