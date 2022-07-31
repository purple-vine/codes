#include <cstdio>
#include <algorithm>
#define no {puts("No"); return 0;}
using namespace std;
int n; char s[500005];
bool judge(){
    for(int i = 1; i <= n; i++){
        int l = i, r = n-i+1;
        if(s[l] == s[r]) continue;
        if(s[l] == 'A' && s[r] == 'B'){
            if(l == 1) return 0;
            if(!(s[l-1] == 'A' || s[r+1] == 'B')) return 0;
        }
        if(s[l] == 'B' && s[r] == 'A'){
            if(r == l+1) return 0;
            else s[l+1] = 'B';
        }
    }
    return 1;
}
int main(){
    scanf("%d %s", &n, s+1);
    bool f = judge();
    if(n % 2 == 0) swap(s[n/2], s[n/2+1]);
    f |= judge();
    puts(f ? "Yes" : "No");
    // puts("Yes");
}