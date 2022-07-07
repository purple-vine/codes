#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;
const int M = 3005;
bitset<M> k[M]; int n; long long ans; char s[M];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", s+1);
        for(int j = i+1; j <= n; j++) k[i][j] = s[j] == '1';
    }
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++){
            if(k[i][j]) ans += (k[i] & k[j]).count();
        }
    cout << ans;
}