#include <cstdio>
using namespace std;
const int M = 2000005;
int n, x, y, a[M], ans;
int main(){
    scanf("%d %d %d", &n, &x, &y);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]); a[i] %= (x+y);
        if(x <= a[i] && x <= y) {puts("First"); return 0;}
        if(y <= a[i] && a[i] < x) {puts("Second"); return 0;}
    }
    for(int i = 1; i <= n; i++)
        if(a[i] >= x) {puts("First"); return 0;}
    puts("Second");
}