#include <cstdio>
#define int long long
using namespace std;
const int M = 1000005;
int p[M], l, r = -1, ll, t, n, w[M]; char s[M][15], c;
signed main(){
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf(" %c", &c);
		if(c == 'Q') printf("%s\n", l > r ? "EMPTY" : s[p[l]]);
		else if(c == 'C'){
			scanf("%s %lld", s[++t], &w[t]);
			while(l <= r && w[p[r]] < w[t]) --r;
			p[++r] = t;
		}
		else if(l <= r && p[l] <= ++ll) ++l;
	}
}
