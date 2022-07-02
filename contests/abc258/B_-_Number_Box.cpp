#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;
const int M = 15;
int a[M][M], n, dx[8] = {0, 0, 1, -1, -1, -1, 1, 1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
LL ans = 0ll;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%1d", &a[i][j]);
    for(int i = 0; i < 8; i++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                LL cur = 0; int xx = x, yy = y;
                for(int k = 0; k < n; k++){
                    // printf("xx=%d yy=%d\n", xx, yy);
                    cur = cur*10 + a[xx][yy];
                    xx = (xx + dx[i] + n) % n; yy = (yy + dy[i] + n) % n;
                }
                // printf("%lld\n", cur);
                ans = max(ans, cur);
            }
        }
    }
    printf("%lld", ans);
}