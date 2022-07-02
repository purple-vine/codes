#include <cstdio>
using namespace std;
const int M = 500005;
int n, m, op, x, ss; char s[M];
int main(){
    scanf("%d %d %s", &n, &m, s);
    while(m--){
        scanf("%d %d", &op, &x);
        if(op == 2) {printf("%c\n", s[(x-1+ss+n)%n]);}
        else ss = ((ss - x) % n + n) % n;
    }
}