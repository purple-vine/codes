#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 200005;
int n, g, a[M];
int gcd(int x, int y) {return y == 0 ? x : gcd(y, x%y);}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(i == 2) g = a[i] - a[i-1];
        g = gcd(g, abs(a[i] - a[i-1]));
    }
    if(g == 1) printf("2\n");
    else printf("1\n");
}