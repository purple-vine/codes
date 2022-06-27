#include <iostream>
#include <cmath>
using namespace std;
int a[1000005],n,maxx,l,r,l2=1000005,r2;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l >> r;
		a[l]++;
		a[r+1]--;
		l2=min(l2,l);
		r2=max(r2,r);
	}
	for(int i=1;i<=1000002;i++){
		a[i]+=a[i-1];
		//cout << a[i] << " ";
		maxx=max(maxx,a[i]);
	}
	cout << maxx;
}
