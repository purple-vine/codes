#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int main(){
    for(int i = 1; i <= 5; i++) scanf("%d", &a[i]);
    sort(a+1, a+6);
    if((a[1] == a[3] && a[3] != a[4] && a[4] == a[5]) || (a[1] == a[2] && a[2] != a[3] && a[3] == a[5])) printf("Yes\n");
    else printf("No\n");
    return 0;
}