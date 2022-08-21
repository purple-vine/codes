#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int M = 505, mod = 998244353;
int dp1[M][M], dp2[M][M], n, m, a, b, c, d, e, f, s[5][4];
void add(int &x, int y) {x += y; if(x > mod) x -= mod;}
void mins(int &a, int b) {a -= b; if(a < 0) a += mod;}
set<pair<int, int> > t;
pair<int, int> get(int i, int j, int k){
    return make_pair(i*a + j*c + k*e, i*b + j*d + k*f);
}
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    for(int i = 1; i <= m; i++){
        int x, y; scanf("%d %d", &x, &y);
        t.insert(make_pair(x, y));
    }
    dp1[0][0] = 1;
    for(int s = 0; s < n; s++){
        for(int i = 0; i <= s; i++){
            for(int j = 0; j <= s-i; j++){
                int k = s - i - j;
                if(t.find(get(i+1, j, k)) == t.end()) add(dp2[i+1][j], dp1[i][j]);
                if(t.find(get(i, j+1, k)) == t.end()) add(dp2[i][j+1], dp1[i][j]);
                if(t.find(get(i, j, k+1)) == t.end()) add(dp2[i][j], dp1[i][j]);
            }
        }
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dp1[i][j] = dp2[i][j], dp2[i][j] = 0;
    }
    int ans = 0; for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) add(ans, dp1[i][j]);
    printf("%d\n", ans);
}