#include <iostream>
#include <cmath>
using namespace std;
int n;
int poww(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++) ans*=a;
    return ans;
}
void c(int n){
    int i=1;
    if(n==0) return;
    while(poww(2,i)<=n) i++;
    i--;
    cout << poww(2,i) << " ";
    c(n-poww(2,i));
}
int main(){
    cin >> n;
    if(n%2==1) cout << -1;
    else c(n);
}
