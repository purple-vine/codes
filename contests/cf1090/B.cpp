#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int M = 5000005;
int T, n, a[M], b[M];
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        int pl = 0; vector<int> v;
        for(int i = 1; i <= n; i++) {
            if(b[i] != 0) pl = i;
            else v.push_back(a[i]);
        }
        if(!pl) {printf("YES\n"); continue;}
        bool f = 1;
        for(int i = 0; i < v.size(); i++) 
            if(v[i] > a[pl] - b[pl]) {f = 0; printf("NO\n"); break;}
        if(!f) continue;
        if(a[pl] < b[pl]) {printf("NO\n"); continue;}
        if(n == 1) {printf(a[1] >= b[1] ? "YES\n" : "NO\n"); continue;}
        for(int i = 1; i <= n; i++) if(b[i] != 0 && a[i]-b[i] != a[pl]-b[pl]) {
            f = 0; printf("NO\n"); break;
        }
        if(f) printf("YES\n");
    }
}