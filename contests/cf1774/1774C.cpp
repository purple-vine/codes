#include <cstdio>
#include <set>
using namespace std;
const int M = 3e5 + 5;
int main(){
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        bool f = 0; 
        int l = 1, r = 1, a;
        for(int i = 2; i <= n; i++) {
            scanf("%1d", &a);
            if(a == 0) {
                l = 1;
            } else {
                r = i, ++l;
            }
            printf("%d ", r - l + 1);
        }
        printf("\n");
    }
}