#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int M = 305;
int f[M][M][M];
int n, m, pi, pj, pt, pk; 
string a, b;
void chkmin(int &x, int y) {
    if(y < x) x = y;
}
string calc(int k, int n, int m) {
    if(k + n + m == 0) return "";
    int pn = n - (a[n] == ')'), pm = m - (b[m] == ')');
    if(f[k+1][pn][pm] + 1 == f[k][n][m]) return calc(k+1, pn, pm) + ')';
    pn = n - (a[n] == '('), pm = m - (b[m] == '(');
    return calc(k-1, pn, pm) + '(';
}
void rev(string &x) {
    int n = x.length();
    for(int i = 0; i < n/2; i++) swap(x[i], x[n - i - 1]);
    for(int i = 0; i < n; i++) x[i] = '(' + ')' - x[i];
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    n = a.length(); m = b.length();
    rev(a); rev(b);
    a = ' ' + a; b = ' ' + b;
    memset(f, 0x3f, sizeof(f));
    f[0][0][0] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= max(n, m); k++) {
                int pn = i - (a[i] == ')'), pm = j - (b[j] == ')');
                chkmin(f[k][i][j], f[k+1][pn][pm] + 1);
                pn = i - (a[i] == '('), pm = j - (b[j] == '(');
                if(k) chkmin(f[k][i][j], f[k-1][pn][pm] + 1);
            }
        }
    }
    string ans = {(char)('(' + 10)};
    int mnlen = 998244353;
    for(int k = 0; k <= max(n,m); k++) {
        mnlen = min(mnlen, f[k][n][m] + k);
        // printf("%d\n", f[k][n][m]);
    }
    for(int k = 0; k <= max(n,m); k++) {
        if(mnlen == f[k][n][m] + k) ans = min(ans, calc(k, n, m) + string(k, ')'));
    }
    rev(ans);
    cout << ans << endl;
}