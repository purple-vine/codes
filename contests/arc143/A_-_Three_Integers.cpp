#include <cstdio>
#include <iostream>
using namespace std;
long long a, b, c, ans;
int main(){
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a > b) swap(a, b); if(a > c) swap(a, c); if(b > c) swap(b, c);
    if(a < c - b) {puts("-1"); return 0;}
    ans += c-b; a = c-b; c = b;
    printf("%lld\n", ans + b);
}