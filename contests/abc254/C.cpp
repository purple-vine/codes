#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 200005;
int a[M], n, k; vector<int> c[M], b;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        c[i%k].push_back(a[i]);
    }
    for(int i = 0; i < k; i++) sort(c[i].begin(), c[i].end());
    for(int i = 0; i < n/k; i++){
        for(int j = 0; j < k; j++){
            if(c[j].size() > i){
                b.push_back(c[j][i]);
            }
        }
    }
    if(is_sorted(b.begin(), b.end())) printf("Yes");
    else printf("No\n");
}