//url : https://atcoder.jp/contests/agc038/tasks/agc038_a
#include <cstdio>
using namespace std;
int n, m, a, b;
int main(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            putchar('0' + (j <= a) ^ (i <= b));
        putchar('\n');
    }
}