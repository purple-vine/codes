#include <cstdio>
#include <iostream>
using namespace std;
const int M = 200005;
int T, n, s[M], ans, k; char cc;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k); ans = 0;
        for(int i = 1; i <= n; i++) scanf(" %c", &cc), s[i] = s[i-1] + (cc == 'B');
        for(int i = k; i <= n; i++) ans = max(ans, s[i] - s[i-k]);
        printf("%d\n", k - ans);
    }
}