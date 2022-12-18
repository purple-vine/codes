#include <cstdio>
using namespace std;
const int M = 2005;
int main(){
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        int sm = 0, c;
        scanf("%1d", &c); sm = c;
        for(int i = 2; i <= n; i++) {
            scanf("%1d", &c);
            if(c == 0) putchar('+');
            else {
                if(sm == 1) putchar('-'), sm --;
                else putchar('+'), ++sm;
            }
        }
        printf("\n");
    }
}