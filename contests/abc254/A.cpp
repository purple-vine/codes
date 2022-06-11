#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n); int t = n % 100;
    if(t < 10) printf("0%d\n", t);
    else printf("%d\n", n % 100);
}