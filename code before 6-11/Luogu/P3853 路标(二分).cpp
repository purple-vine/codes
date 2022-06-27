#include <iostream>
#include <algorithm>
using namespace std;
int n,l,k,ans,mid,lt,r,d;
int a[10000005];
bool check(int s){
	int ans=0;
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]>=mid)
        {
            ans+=(a[i]-a[i-1])/mid;
            if((a[i]-a[i-1])%mid==0)
                ans--;
        }
	return ans<=k;
}
int main(){
    cin >> l >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    lt=0;
    r=l;
    while(lt<=r){
    	mid = (lt+r)/2;
    	//printf("%d %d %d",lt,mid,r);
    	//cout<< endl;
    	if(check(mid)) {ans=mid;r=mid-1;}
    	else lt=mid+1;
	}
    
	cout << ans;
}
