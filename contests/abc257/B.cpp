#include <cstdio>
using namespace std;
const int M = 205;
int n, k, q, a[M], l;
int main(){
    scanf("%d %d %d", &n,  &k, &q);
    for(int i = 1; i <= k; i++)  scanf("%d", &a[i]);
    while(q--){
        scanf("%d", &l);
        if(a[l+1] > a[l]+1) a[l]++;
        else if(l == k && a[l] < n) a[l]++;
    }
    for(int i = 1; i <= k; i++) printf("%d ", a[i]);
}