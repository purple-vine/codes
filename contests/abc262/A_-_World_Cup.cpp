#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);;
    for(int i = 0; i <= 4; i++){
        if((n+i) % 4 == 2) {printf("%d\n", n+i); return 0;}
    }
}