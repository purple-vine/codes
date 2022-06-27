#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005]={1000000005},mid,l,r,q,ans; 
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++){
		cin >> q;
		ans= lower_bound(a,a+n+1,q)-a;
		if(a[ans]!=q) ans=-1;
		cout << ans << " ";
	}
}
