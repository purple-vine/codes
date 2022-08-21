#include <cstdio>
#include <iostream>
using namespace std;
int T, n, m;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        if(n == 1 && m == 1) printf("0\n");
        else printf("%d\n", 2 * min(n, m) + max(n, m) - 2);
    }
}