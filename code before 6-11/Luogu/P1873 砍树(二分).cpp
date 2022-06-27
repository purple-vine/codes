#include <iostream>
#include <algorithm>
using namespace std;
int m,n,a[1000005],l,r,mid,maxx,ans;
bool check(int t){
	long long ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i]>t) ans+=a[i]-t;
	}
	return ans>=m;
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) {cin >> a[i];maxx=max(maxx,a[i]);}
    l=0;
    r=maxx;
    while(l<=r){
    	mid=(l+r)/2;
    	if(check(mid)) {ans=mid;l=mid+1;}
    	else r=mid-1;
	}
	cout << ans;
}
