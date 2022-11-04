#include <cstdio>
using namespace std;
const int M = 300005;
int a[M], n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(a[n] - a[n-1] >= 2) {printf("Alice\n"); return 0;}
    int res = a[n] - n;
    if(res % 2 == 0) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}