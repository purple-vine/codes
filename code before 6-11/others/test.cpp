#include <cstdio>
using namespace std;
int c[10], n, minn = 1e9, pl, val;
void dfs(int len, int sum){
    if(len == 0) return;
    for(int i = 9; i >= 0; i--){
        if(c[i] <= sum) {printf("%d", i); dfs(len-1, sum-c[i]); return;}
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i <= 9; i++){
        scanf("%d", &c[i]);
        if(c[i] <= minn) minn = c[i], pl = i;
        printf("minn = %d\n", minn);
    }
    for(int i = 0; i <= 9; i++) printf("%d ", c[i]);
    int len = n / minn; for(int i = 0; i <= 9; i++) c[i] -= minn; val = n % minn;
    dfs(len, val); return 0;
}
