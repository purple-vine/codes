#include <iostream>
#include <algorithm>
using namespace std;
int a[30005],n,m,tot,ans;
int main(){
	cin >> m >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int i=1,j=n;
	while(i<j){
		if(a[i]+a[j]<=m){
			tot+=2;
			ans++;
			//cout << a[i] << " "<<a[j] << endl;
			i++;
			j--;
		}
		else{
			tot+=1;
			ans++;
			//cout << a[j] << endl;
			j--;
		}
	}
	if(tot<n) ans++;
	cout << ans;
	return 0;
}
