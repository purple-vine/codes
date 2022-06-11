#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    srand(time(0));
    printf("10\n");
    for(int t = 1; t <= 10; t++){
        printf("10\n");
        int n = 10;
        for(int i = 1; i <= n; i++) printf("%d ", rand() % 10); \
        printf("\n");
    }
    
}