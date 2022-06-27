#include <iostream>
#include <algorithm>
using namespace std;
int m,n,a[100005],l,r,mid,maxx,ans,summ;
bool check(int t){
	long long ans = 0;
	for(int i=1;i<=n;i++){
		ans+=a[i]/t;
	}
	return ans>=m;
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) {cin >> a[i];maxx=max(maxx,a[i]);summ+=a[i];}
    l=1;
    r=maxx;
    ans=0;
    if(summ<m) {cout << 0;return 0;}
    while(l<=r){
    	mid=(l+r)/2;
    	if(check(mid)) {ans=mid;l=mid+1;}
    	else r=mid-1;
	}
	cout << ans;
	return 0;
}
