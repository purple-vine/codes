#include <cstdio>
using namespace std;
int x, z, t; long long y;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %lld %d", &x, &y, &z);
        puts(x <= z && 1ll * (2*z-x-2)*(x+1)/2+1 >= y ? "Renko" : "Merry");
    }
    return 0;
}