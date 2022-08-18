#include <cstdio>
#include <cmath>
using namespace std;
const int M = 1005;
struct edge{
    int to, nxt, x, t;
}e[M << 1];
int head[M], cnt1, n, k[M];
void link(int u, int v, int x, int t){
    e[++cnt1] = {v, head[u], x, t}; head[u] = cnt1;
}
int num1[M]; double num2[M], t[M];
void dfs(int u){
    for(int i = head[u]; i; i = e[i].nxt){
        int v = e[i].to, w = e[i].x;
        // printf("u=%d v=%d\n", u, v);
        if(e[i].t == 0){
            t[v] = t[u] * w / 100.0;
            //num1[v] = num1[u]; num2[v] = num2[u] * e[i].x / 100.0;
        } else {
            t[v] = t[u] * w / 100.0 * t[u] * w / 100.0;
            // num1[v] = num1[u] + 1; num2[v] = num2[u] * e[i].x / 100.0 * e[i].x / 100.0;
        }
        dfs(v);
    }
}
bool check(double u){
    t[1] = u; dfs(1); //printf("u=%lf\n", u);
    // for(int i = 1; i <= n; i++) printf("%lf ", t[i]);
    for(int i = 1; i <= n; i++) if(k[i] > t[i]) return 0;
    return 1;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int a, b, x, t;
        scanf("%d %d %d %d", &a, &b, &x, &t);
        link(a, b, x, t);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &k[i]);
    double l = 0, r = 2e9;
    for(int i = 1; i <= 500; i++){
        double mid = (l+r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
    // num1[1] = 1; num2[1] = 1.0; dfs(1);
}