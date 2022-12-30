// CF839D
#include <cstdio>
using namespace std;
const int M = 1e6 + 5, mod = 1000000007;
int cnt[M], sm[M], s[M], a[M], n, m = 1e6, t[M];
int mu[M], p[M], tt, summu[M]; bool f[M];
int add(int a, int b) {a += b; return a >= mod ? a-mod : a;}
int mins(int a, int b) {a -= b; return a < 0 ? a+mod : a;}
void addn(int &x, int y) {x += y; if(x >= mod) x -= mod;}
void pre(int n){
    summu[1] = f[1] = mu[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!f[i]) p[++tt] = i, mu[i] = -1;
        for(int j = 1; j <= tt; j++){
            int k = p[j] * i; if(k > n) break;
            if(i % p[j] == 0) {f[k] = 1; mu[k] = 0; break;}
            f[k] = 1; mu[k] = -mu[i];
        }
        summu[i] = summu[i-1] + mu[i];
    } 
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ++cnt[a[i]];
    pre(m);
    for(int i = m; i >= 1; i--) 
        for(int j = i; j <= m; j += i) 
            addn(sm[i], cnt[j]);
    t[0] = 1;
    for(int i = 1; i <= n; i++) {
        t[i] = 1ll * t[i-1] * 2 % mod;
        s[i] = 1ll * t[i-1] * i % mod;
    }
    auto calc = [](int t) {
        int ans = 0;
        for(int i = t; i <= m; i += t) {
            addn(ans, mu[i / t] == 1 ? s[sm[i]] : mu[i / t] == -1 ? mod - s[sm[i]] : 0);
        }
        // printf("%d : %d\n", t, ans);
        return ans;
    } ;
    int ans = 0;
    for(int i = 2; i <= m; i++) {
        addn(ans, 1ll * i * calc(i) % mod);
    }
    printf("%d\n", ans);
}