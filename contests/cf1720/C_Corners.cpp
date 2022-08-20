#include <cstdio>
#include <iostream>
#define c ans = max(ans, 2);
using namespace std;
const int M = 1005;
bool a[M][M]; int n, m, T;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%1d", &a[i][j]), a[i][j] = 1 - a[i][j];
        int ans = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 1) {
                    ++cnt, ans = max(ans, 1);
                    if(a[i-1][j-1] && (!a[i-1][j] || !a[i][j-1]))
                        ans = max(ans, 2); 
                    if(a[i-1][j+1] && (!a[i-1][j] || !a[i][j+1]))
                        ans = max(ans, 2);
                    if(a[i+1][j-1] && (!a[i][j-1] || !a[i+1][j]))
                        ans = max(ans, 2);
                    if(a[i+1][j+1] && (!a[i+1][j] || !a[i][j+1]))
                        ans = max(ans, 2);
                    if(a[i+1][j] && (!a[i+1][j+1] || !a[i+1][j-1]))
                        c;
                    if(a[i-1][j] && (!a[i-1][j-1] || !a[i-1][j+1]))
                        c;
                    if(a[i][j-1] && (!a[i+1][j-1] || !a[i-1][j-1]))
                        c;
                    if(a[i][j+1] && (!a[i+1][j+1] || !a[i-1][j+1]))
                        c;
                    ans = max(ans, 1);
                }
            }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                a[i][j] = 0;
        printf("%d\n", n*m - cnt - (2 - ans));
    }
}