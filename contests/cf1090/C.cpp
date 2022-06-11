#include <cstdio>
#include <iostream>
using namespace std;
const int M = 200005;
int t, n, a[M], b[M];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for(int i = 1; i <= n; i++) printf("%d ", b[i] - max(b[i-1], a[i]));
        printf("\n");
    }
}