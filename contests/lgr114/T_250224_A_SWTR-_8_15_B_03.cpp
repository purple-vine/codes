#include <cstdio>
using namespace std;
int main(){
    int s, t, n, m;
    scanf("%d %d", &s, &t);
    while(t--){
        scanf("%d %d", &n, &m);
        printf("%d ", n * m - (n - n/2) * (m - m/2));
        printf("0.0\n");
    }

}