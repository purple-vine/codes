#include <cstdio>
#include <iostream>
// #define int long long
using namespace std;
// min{ x + A + x - B mod (A + x) }
int solve(int A, int B){
    if(B % A == 0) return 0;
    --B;
    int ans = A - B % A - 1;
    for(int l = A, r; l <= B; l = r+1){
        r = B / (B / l);
        ans = min(ans, l - A + l - B % l - 1);
    }
    if(B + 1 - A > 0) ans = min(ans, B + 1 - A);
    return ans;
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", solve(a, b));
        // if(a > 100) continue;
        // for(int i = 0; i <= a; i++){
        //     printf("%d ", a + 2*i - (b-1) % (a+i) - 1);
        // }
        // printf("\n");
    }
}