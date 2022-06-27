#include <cstdio>
#include <cmath>
#define int long long
using namespace std; 
int t; long long n;
int calc(long long n, int t){
	long long ans = 1;
	while(n % t == 0) n /= t, ans *= t;
	return ans;
}
signed main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		int s1 = calc(n, 2), s2 = calc(n, 3); 
		int s3 = n / s1 / s2;
		if(s3 == 1){
			if(s2 <= 3) printf("0\n");
			else printf("1\n");
		} else {
			printf("1\n");
		}
	}
}
