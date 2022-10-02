#include <cstdio>
using namespace std;
int ansx, ansy;
void checkmax(int i, int j){
    if(j > ansy) {ansx = i, ansy = j;}
    else if(j == ansy && i > ansx) {ansx = i; ansy = j;}
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 9; i++){
        int num = i;
        for(int j = 1; j <= n; j++){
            if(num % m == 0) checkmax(i, j);
            num = (10ll * num + i) % m;
        }
    }
    for(int i = 1; i <= ansy; i++) printf("%d", ansx);
    if(!ansy) {printf("-1\n");}
}