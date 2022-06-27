#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int M=5000005;
int n,a[M],b[M];
vector<int>t;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			t.push_back(a[i]+b[j]);
		}
	}
	sort(t.begin(),t.end());
	for(int i=0;i<n;i++) printf("%d ",t[i]);
	return 0;
}
