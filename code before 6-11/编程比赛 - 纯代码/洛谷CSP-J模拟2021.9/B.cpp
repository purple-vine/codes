#include <cstdio>
#include <stack>
#define ll long long
using namespace std;
int n,op,l,r,k;
stack<pair<int,int> >st;
ll query(int l,int r) {return (l+r)*(r-l+1ll)/2;}
ll get(ll k){
	ll ans=0ll,sum=0ll;
	while(sum<k){
		int l=st.top().first,r=st.top().second;st.pop();
		if(sum+r-l+1<k) {ans+=query(l,r);sum+=r-l+1;}
		else{
			ans+=query(r-k+sum+1,r);
			st.push(make_pair(l,r-k+sum));
			return ans;
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&op);
		if(op==1) {scanf("%d%d",&l,&r);st.push(make_pair(l,r));}
		else {scanf("%lld",&k);printf("%lld\n",get(k));}
	}
}
