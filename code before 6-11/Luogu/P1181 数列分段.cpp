#include <iostream>
using namespace std;
int n,m,cnt,sum,t;
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> t;
    	sum+=t;
    	if(sum>m){
    		sum=t;
    		cnt++;
		}
	}
	cout << ++cnt;
}
