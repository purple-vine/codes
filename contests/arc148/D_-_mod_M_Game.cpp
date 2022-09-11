#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 200005;
int a[M], n, b[M], cnt[M], m;
int count(int t){
    return upper_bound(b+1, b+n+1, t) - lower_bound(b+1, b+n+1, t);
}
int main(){
    scanf("%d %d", &n, &m); n <<= 1;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(b+1, b+n+1); // int n1 = unique(b+1, b+n+1) - b - 1; //printf("%d\n", n1);
    // for(int i = 1; i <= n; i++) ++cnt[lower_bound(b+1, b+n1+1, a[i]) - b];
    for(int i = 1; i <= (m+1)/2; i++){
        if(m % 2 == 1){
            if(count(i) % 2 == 1) {printf("Alice\n", i); return 0;}
        }
        else{
            if((count(i) + count(i+m/2)) % 2 == 1) {printf("Alice\n", i); return 0;}
        }
    }
    if(m % 2 == 1) printf("Bob\n"); 
    else {
        if((m/2) % 2 == 1) printf("Alice\n");
        else printf("Bob\n");
    }
}