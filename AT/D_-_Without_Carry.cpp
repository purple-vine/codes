// arc136D
#include <cstdio>
#include <tuple>
#include <map>
#include <cmath>
#define LL long long
using namespace std;
const int M = 1e6 + 5;
LL a[M], sum[M]; int n;
int qpow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) ans = ans * a;
        a = a * a;
    }
    return ans;
}
bool chk(int t) {
    while(t) {
        if(t % 10 >= 5) return 0;
        t /= 10;
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ++sum[a[i]];
    }
    int w = 1000000;
    for(int i = 0; i < 6; i++) {
        int pw = qpow(10, i);
        for(int j = 0; j < w; j++) {
            if((j / pw) % 10) sum[j] += sum[j - pw];
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += sum[w - 1 - a[i]];
        if(chk(a[i])) --ans;
    }
    printf("%lld\n", ans / 2);
}