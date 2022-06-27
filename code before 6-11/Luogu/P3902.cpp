#include <iostream>
#include <cmath>
using namespace std;
int a[100005],n;
long long dp[100005],maxdp;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(dp[j]>dp[i] && a[j]<a[i]){
				dp[i] = dp[j];
			}
		}
		dp[i]++;
	}
	for(int i=1;i<=n;i++) maxdp=max(maxdp,dp[i]);
	cout << n-maxdp;
}
