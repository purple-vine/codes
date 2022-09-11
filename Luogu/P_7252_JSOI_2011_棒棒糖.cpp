#include <cstdio>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
const int M = 50005;
int n, a[M], m; vector<int> v[M];
default_random_engine e(time(0));
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), v[a[i]].push_back(i);
    while(m--){
        int s, t;
        scanf("%d %d", &s, &t); int l = t - s + 1; bool f = 0;
        for(int i = 1; i <= 45; i++){
            int p = e() % (t-s+1) + s;
            if(upper_bound(v[a[p]].begin(), v[a[p]].end(), t) - lower_bound(v[a[p]].begin(), v[a[p]].end(), s) > l/2){
                printf("%d\n", a[p]); f = 1; break;
            }
        }
        if(!f) printf("0\n");
    }
}