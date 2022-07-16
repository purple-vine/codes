#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
const int M = 200005;
int t, n, c, q; LL l[M], r[M], len[M], k, x; char s[M];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &c, &q);
        scanf("%s", s); len[0] = strlen(s);
        for(int i = 1; i <= c; i++)
            scanf("%lld %lld", &l[i], &r[i]), len[i] = len[i-1] + r[i] - l[i] + 1;
        for(int i = 1; i <= q; i++){
            scanf("%lld", &x);
            for(int j = c; j >= 1; j--){
                // printf("%d ", x);
                if(len[j-1] < x) x -= (len[j-1] - l[j] + 1);
            }
            printf("%c\n", s[x-1]);
        }
    }
}