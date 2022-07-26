#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", 2*n);
    if(n % 4) printf("%d", n % 4);
    for(int i = 1; i <= (n/4); i++) printf("4");
}