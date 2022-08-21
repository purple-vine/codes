#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    printf("%d\n", n/3 * min(3*x, y) + n%3 * x);
}