#include <cstdio>
#define int long long
#define p 1000000007
using namespace std;
const int M = 1000005; 
int n, m, k, r[M], s[M], x, y, sum, ans, ss; char op;
signed main(){
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 1; i <= n; i++) r[i] = 1ll;
	for(int i = 1; i <= m; i++) s[i] = 1ll;
	while(k--){
		scanf(" %c %lld %lld", &op, &x, &y);
		if(op == 'R') r[x] = r[x] * y % p;
		else s[x] = s[x] * y % p;
	}
	for(int i = 1; i <= m; i++){
		sum = (sum + s[i] * i) % p; ss = (ss + s[i] * m) % p; 
	}
	for(int i = 1; i <= n; i++){
		ans = (ans + (((i - 1) * ss + sum) % p * r[i])) % p;
	} printf("%lld\n", ans);
}
