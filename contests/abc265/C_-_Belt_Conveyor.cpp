#include <cstdio>
using namespace std;
const int M = 505;
char a[M][M]; int n, m, d[M][M]; bool vis[M][M];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char op; scanf(" %c", &op);
            if(op == 'U') d[i][j] = 0;
            else if(op == 'D') d[i][j] = 1;
            else if(op == 'L') d[i][j] = 2;
            else if(op == 'R') d[i][j] = 3;
        }
    }
    int x = 1, y = 1;
    while(1) {
        if(vis[x][y]) {printf("-1\n"); return 0;} vis[x][y] = 1;
        int xx = x + dx[d[x][y]], yy = y + dy[d[x][y]];
        // printf("%d %d\n", xx, yy);
        if(xx < 1 || xx > n || yy < 1 || yy > m) {printf("%d %d\n", x, y); return 0;}
        x = xx; y = yy;
    }
}