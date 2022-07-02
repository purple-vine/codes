#include <cstdio>
using namespace std;
int a;
int main(){
    scanf("%d", &a);
    if(a % 60 < 10) printf("%d:0%d", 21+(a/60), a%60);
    else printf("%d:%d", 21+(a/60), a%60);
}