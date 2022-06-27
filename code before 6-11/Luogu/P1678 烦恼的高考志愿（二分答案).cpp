#include <iostream>
#include <algorithm>
using namespace std;
int m,n,a[1000005],ans,t;
int main(){
    cin >> m >> n;
    for(int i=1;i<=m;i++) cin >> a[i];
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++){
    	cin >> t;
    	int c=lower_bound(a+1,a+m+1,t)-a;
    	if(c==m+1 ){
    		if(c<a[1]) ans+=a[1]-c;
    		else ans+=c-a[m];
		}
    	else ans+=min(a[c]-t,t-a[c-1]);
	}
	cout << ans;
}
