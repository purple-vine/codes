#include <cstdio>
#include <cstring>
using namespace std;
const int M = 705, mod = 1000000007;
int add(int a, int b) {return (a += b) > mod ? a-mod : a;}
void addto(int &a, int b) {if((a += b) > mod) a -= mod;}
int dp[M][M][3][3], p[M], n, st[M], t; char s[M];
int main(){
    scanf("%s", s + 1); n = strlen(s+1);
    for(int i = 1; i <= n; i++){
        if(s[i] == '(') st[++t] = i;
        else p[i] = st[t], p[st[t]] = i, t--;
    }
    // for(int i = 1; i <= n; i++) printf("%d\n", p[i]);
    // for(int i = 0; i <= n; i++)
    //     for(int j = 0; j < 3; j++)
    //         for(int k = 0; k < 3; k++)
    //             dp[i+1][i][j][j] = 1;
    for(int k = 1; k < n; k += 2){ //长度
        for(int l = 1; l <= n-k; l++){ //左端点
            int r = l + k; if(s[l] != '(' || s[r] != ')') continue;
            // printf("%d %d\n", l, r);
            if(r == l+1){
                dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
                continue;
            }
            if(p[l] == r) {
                for(int j = 0; j < 3; j++){
                    for(int k = 0; k < 3; k++){
                        if((j > 0 && k > 0) || (j == 0 && k == 0)) continue;
                        for(int l1 = 0; l1 < 3; l1++){
                            for(int r1 = 0; r1 < 3; r1++){
                                if((j != 0 && j == l1) || (k != 0 && k == r1)) continue;
                                // printf("%d %d %d %d %d %d %d\n", l, r, j, k, l1, r1, dp[l+1][r-1][l1][r1]);
                                addto(dp[l][r][j][k], dp[l+1][r-1][l1][r1]);
                            }
                        }
                    }
                }
            } else {
                int rr = p[l];
                for(int j = 0; j < 3; j++){
                    for(int k = 0; k < 3; k++){
                        for(int l1 = 0; l1 < 3; l1++){
                            for(int r1 = 0; r1 < 3; r1++){
                                if((l1 != 0 && r1 == l1)) continue;
                                addto(dp[l][r][j][k], 1ll * dp[l][rr][j][l1] * dp[rr+1][r][r1][k] % mod);
                            }
                        }
                    }
                }
                // for(int j = 1; j < 3; j++){
                //     for(int k = 1; k < 3; k++)
                //         dp[l][r][j][k] += dp[l][r1][j][0] * dp[r1+1][r][0][k];
                // }
                // for(int j = 1; j < 3; j++){
                //     for(int c = 1; c < 3; c++)
                //         dp[l][r][0][j] += dp[l][r1][0][c] * dp[r1+1][r][0][j], 
                //         dp[l][r][j][0] += dp[l][r1][j][0] * dp[r1+1][r][c][0];
                // }
                // for(int k1 = 0; k1 < 3; k1++){
                //     for(int k2 = 0; k2 < 3; k2++){
                //         if(k1 != k2) dp[l][r][0][0] += dp[l][r1][0][k1] * dp[r1+1][r][k2][0];
                //     }
                // }
            }
        } 
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = i; j <= n; j++){
    //         for(int k = 0; k < 3; k++){
    //             for(int l = 0; l < 3; l++){
    //                 if(dp[i][j][k][l]) printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, l, dp[i][j][k][l]);
    //             }
    //         }
    //     }
    // }
    int ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            addto(ans, dp[1][n][i][j]);
        }
    }
    printf("%d\n", ans);
}